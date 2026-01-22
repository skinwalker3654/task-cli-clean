#include <stdio.h>
#include <stdlib.h>
#include "task_database.h"

/*==========================================================/
 * DATABASE OWNER-SHIP
 *==========================================================*/

/*this function initializes the database and it return
 * NULL when memory allocation failed*/
task_db_t *create_database() {
    task_db_t *database = malloc(sizeof(task_db_t));
    if(!database) {
        return NULL;
    }

    database->capacity = 2;
    database->counter = 0;

    database->tasks = malloc(sizeof(task_t)*database->capacity);
    if(!database->tasks) {
        free(database);
        return NULL;
    }

    return database;
}

/*this function frees the database
 * @db: the original database
 * it stops if the database is already unallocated*/
void free_database(task_db_t *db) {
    if(!db || !db->tasks) {
        return;
    }

    for(int i=0; i<db->counter; i++) 
        free(db->tasks[i].description);

    free(db->tasks);
    db->tasks = NULL;

    free(db);
    db = NULL;
}
