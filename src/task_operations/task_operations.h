#ifndef TASK_OPERATIONS_H
#define TASK_OPERATIONS_H

#include "../task_database/task_database.h"

/*DATABASE OPERATIONS*/
void add_task(task_db_t *db,char *name,int id,status_t status);
void remove_task(task_db_t *db,int id);
void list_tasks(task_db_t *db);
void rename_task(task_db_t *db,int id,char *description);
void set_status(task_db_t *db,int id,status_t status);

#endif
