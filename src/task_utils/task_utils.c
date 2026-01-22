#include <stdio.h>
#include <string.h>
#include "task_utils.h"

/*==============================================================================/
 * UTIL FUNCTIONS
 *==============================================================================*/

/*this function finds the task with the given desctiption and returns the index
 * @id: users given ID
 * @db: the original database that the function will search
 * returns tasks index on sucess and -1 if it didnt find a task with the given desctiption*/
int find_task(task_db_t db,int id) {
    for(int i=0; i<db.counter; i++) {
        if(db.tasks[i].id == id) {
            return i;
        }
    }

    return -1;
}

/*this function parses the given status into string format
 * @status: is the users given status to parse into string*/
char *make_status_to_string(status_t status) {
    switch(status) {
        case STATUS_DONE: return "done";
        case STATUS_IN_PROGRESS: return "in-progress";
        case STATUS_PENDING: return "pending";
        default: return "Unkown";
    }
}


/*this function parses the given string into status_t format
 * @string: is the users given string to parse into status_t*/
status_t make_string_to_status(char *string) {
    if(strcmp(string,"done")==0) {
        return STATUS_DONE;
    } else if(strcmp(string,"in-progress")==0) {
        return STATUS_IN_PROGRESS;
    } else if(strcmp(string,"pending")==0) {
        return STATUS_PENDING;
    }

    return STATUS_ERROR;
}

/*this function prints the help panel so the user can see the commands*/
void print_cli_usage() {
    printf("Usage:\n");
    printf("  ./main add <id> \"description\"             | this operation adds a task into the list\n");
    printf("  ./main remove <id>                     | this operation deletes a task from the list\n");
    printf("  ./main list                            | this operation prints the task list\n");
    printf("  ./main help                            | this operation prints this panel\n");
    printf("  ./main rename <id> \"new_description\" | this operation changes the old description of a task\n");
    printf("  ./main set-status <id> <status>        | this operation changes the status of a task\n\n");
    printf("Available task status: done, pending, in-progress\n");
}
