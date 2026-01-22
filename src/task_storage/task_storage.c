#include <stdio.h>
#include "task_storage.h"
#include "../task_utils/task_utils.h"
#include "../task_operations/task_operations.h"

#define DATABASE_FILE_NAME "database.txt"
/*===============================================================================/
 * STORAGE FUNCTIONS
 *===============================================================================*/

/*this function saves every task into a file to keep the data
 * @db: is the database to save in the file*/
void save_tasks(task_db_t *db) {
    FILE *file = fopen(DATABASE_FILE_NAME,"w");
    if(!file) {
        printf("Error: Failed to save the tasks\n");
        return;
    }
    
    for(int i=0; i<db->counter; i++) {
        fprintf(file,"%d|%s|%s|\n",
                db->tasks[i].id,
                db->tasks[i].description,
                make_status_to_string(db->tasks[i].status));
    }

    fclose(file);
}

/*this function loads every task that is store to the DATABASE_FILE_NAME
 * @db: is the database to put the tasks in*/
void load_tasks(task_db_t *db) {
    FILE *file = fopen(DATABASE_FILE_NAME,"r");
    if(!file) return;

    char line[256];

    int id;
    char description[256];
    char status[256];

    while(fgets(line,sizeof(line),file)) {
        if(sscanf(line,"%d|%[^|]|%[^|]|",&id,description,status)==3) {
            add_task(db,description,id,make_string_to_status(status));
        }
    }
    
    fclose(file);
}

