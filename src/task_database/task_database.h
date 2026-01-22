#ifndef TASK_DATABASE_H
#define TASK_DATABASE_H

#include <stdint.h>

typedef enum status_t {
    STATUS_DONE,
    STATUS_IN_PROGRESS,
    STATUS_PENDING,
    STATUS_ERROR,
} status_t;

typedef struct task_t {
    char *description;
    uint32_t id;
    status_t status;
} task_t;

/*MAIN STRUCTURE*/
typedef struct task_db_t {
    task_t *tasks;
    uint32_t capacity;
    uint32_t counter;
} task_db_t;

/*OWNER-SHIP MODEL*/
task_db_t *create_database();
void free_database(task_db_t *db);

#endif
