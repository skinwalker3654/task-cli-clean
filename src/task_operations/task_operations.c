#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "task_operations.h"
#include "../task_utils/task_utils.h"

#define MINIMUM_ID_NUMBER 1
/*===========================================================/
 * MAIN OPERATIONS
 *===========================================================*/

/*this function adds a task into the database
 * @db: original database to put value
 * @description: the task description given from user
 * @id: the task id given from the user*/
void add_task(task_db_t *db, char *description, int id,status_t status) {
    if(db->counter >= db->capacity) {
        db->capacity *= 2;
        task_t *temp = realloc(db->tasks,sizeof(task_t)*db->capacity);
        if(!temp) {
            printf("Database failed to put the value due to memory issues.\n");
            return;
        }

        db->tasks = temp;
    }

    if(id < MINIMUM_ID_NUMBER) {
        printf("Invalid task ID, you should put a number bigger than 0\n");
        return;
    }

    int found_same_id = 0;
    for(int i=0; i<db->counter; i++) {
        if(db->tasks[i].id == id) {
            found_same_id = 1;
        }
    }

    if(found_same_id) {
        printf("Error: Task with the given ID already exists in the list\n");
        return;
    }

    db->tasks[db->counter].description = strdup(description);
    if(!db->tasks[db->counter].description) {
        printf("Error: Failed to create tasks description due to memory issues\n");
        return;
    }

    db->tasks[db->counter].id = id;
    db->tasks[db->counter].status = status;

    db->counter++;
}

/*this function removes a task from the database
 * @db: original database to remove tasks
 * @id: the users given ID for task to delete*/
void remove_task(task_db_t *db, int id) {
    if(db->counter == 0) {
        printf("Database is empty\n");
        return;
    }

    int task_index = find_task(*db,id);
    if(task_index == -1) {
        printf("Error: Task not found\n");
        return;
    }

    free(db->tasks[task_index].description);
    for(int i=task_index; i<db->counter-1; i++)
        db->tasks[i] = db->tasks[i+1];
    db->counter--;

    printf("Task removed succesfully\n");
}

/*this function lists the database tasks
 * @db: is the original database to list tasks*/
void list_tasks(task_db_t *db) {
    if(db->counter == 0) {
        printf("Database is empty\n");
        return;
    }

    printf("ID | STATUS      | DESCRIPTION\n");
    printf("---+-------------+------------------\n");
    for(int i=0; i<db->counter; i++) {
        printf("%d | %-16s | %s\n",
                db->tasks[i].id,
                make_status_to_string(db->tasks[i].status),
                db->tasks[i].description);
    }
}

/*this function renames the description of the task with the given id
 * @db: database to look for given id
 * @id: users given ID to rename
 * @description: users new description to put on the task description*/
void rename_task(task_db_t *db, int id, char *description) {
    if(db->counter == 0) {
        printf("Database is empty\n");
        return;
    }

    int task_index = find_task(*db,id);
    if(task_index == -1) {
        printf("Error: Task not found\n");
        return;
    }

    free(db->tasks[task_index].description);
    db->tasks[task_index].description = strdup(description);
    if(!db->tasks[task_index].description) {
        printf("Error: Failed to rename the task description do to memory issues\n");
        return;
    }

    printf("Task description has renamed succesfully\n");
}


/*this function changes the status of the task with given id to the given status
 * @db: original database to look for task
 * @id: users given ID of the task to change
 * @status: users given status to put*/
void set_status(task_db_t *db, int id, status_t status) {
    if(db->counter == 0) {
        printf("Database is empty\n");
        return;
    }

    int task_index = find_task(*db,id);
    if(task_index == -1) {
        printf("Error: Task not found\n");
        return;
    }

    if(db->tasks[task_index].status == status) {
        printf("Task is already with the status: %s\n",make_status_to_string(status));
        return;
    }

    db->tasks[task_index].status = status;
    printf("Task changed status succesfully\n");
}
