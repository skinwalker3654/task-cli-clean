#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "task_database/task_database.h"
#include "task_operations/task_operations.h"
#include "task_storage/task_storage.h"
#include "task_utils/task_utils.h"

int main(int argc,char **argv) {
    if(argc < 2 || argc > 4) {
        printf("Error: Invalid arguments passed\n");
        printf("Type: \"./main help\" for more details\n");
        return 1;
    }

    task_db_t *database = create_database();
    if(database == NULL) return 1;

    load_tasks(database);
    if(strcmp(argv[1],"add")==0) {
        if(argc != 4) {
            printf("Error: Invalid usage\n");
            printf("Correct usage: ./main add <id> \"description\"\n");
            goto CLEANUP;
        }

        char *endPtr;
        int id = strtol(argv[2],&endPtr,10);
        if(*endPtr != '\0') {
            printf("Error: Invalid task ID '%s'\n",argv[2]);
            goto CLEANUP;
        }

        add_task(database,argv[3],id,STATUS_PENDING);
        printf("Task added succesfully\n");
    } else if(strcmp(argv[1],"remove")==0) {
        if(argc != 3) {
            printf("Error: Invalid usage\n");
            printf("Correct usage: ./main remove <id>\n");
            goto CLEANUP;
        }

        char *endPtr;
        int id = strtol(argv[2],&endPtr,10);
        if(*endPtr != '\0') {
            printf("Error: Invalid task ID '%s'\n",argv[2]);
            goto CLEANUP;
        }

        remove_task(database,id);
    } else if(strcmp(argv[1],"list")==0) {
        if(argc != 2) {
            printf("Error: Invalid usage\n");
            printf("Correct usage: ./main list\n");
            goto CLEANUP;
        }

        list_tasks(database);
    } else if(strcmp(argv[1],"rename")==0) {
        if(argc != 4) {
            printf("Error: Invalid usage\n");
            printf("Correct usage: ./main rename <id> \"new_description\"\n");
            goto CLEANUP;
        }

        char *endPtr;
        int id = strtol(argv[2],&endPtr,10);
        if(*endPtr != '\0') {
            printf("Error: Invalid task ID '%s'\n",argv[2]);
            goto CLEANUP;
        }

        rename_task(database,id,argv[3]);
    } else if(strcmp(argv[1],"set-status")==0) {
        if(argc != 4) {
            printf("Error: Invalid usage\n");
            printf("Correct usage: ./main set-status <id> <status>\n");
            printf("Available task status: done, pending, in-progress\n");
            goto CLEANUP;
        }

        char *endPtr;
        int id = strtol(argv[2],&endPtr,10);
        if(*endPtr != '\0') {
            printf("Error: Invalid task ID '%s'\n",argv[2]);
            goto CLEANUP;
        }

        status_t status = make_string_to_status(argv[3]);
        if(status == STATUS_ERROR) {
            printf("Error: Invalid status '%s'\n",argv[3]);
            printf("Available task status: done, pending, in-progress\n");
            goto CLEANUP;
        }
        set_status(database,id,status);
    } else if(strcmp(argv[1],"help")==0) {
        if(argc != 2) {
            printf("Error: Invalid usage\n");
            printf("Correct usage: ./main help\n");
            goto CLEANUP;
        }

        print_cli_usage();
    } else {
        printf("Error: Invalid arguments passed\n");
        printf("Type: \"./main help\" for more details\n");
        goto CLEANUP;
    }

    CLEANUP:
        save_tasks(database);
        free_database(database);

    return 0;
}
