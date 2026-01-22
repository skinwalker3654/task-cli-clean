#ifndef TASK_STORAGE_H
#define TASK_STORAGE_H

#include "../task_database/task_database.h"

/*STORAGE FUNCTIONS*/
void save_tasks(task_db_t *db);
void load_tasks(task_db_t *db);

#endif
