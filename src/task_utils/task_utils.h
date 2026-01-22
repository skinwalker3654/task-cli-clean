#ifndef TASK_UTILS_H
#define TASK_UTILS_H

#include "../task_database/task_database.h"

/*UTIL FUNCTIONS*/
int find_task(task_db_t db,int id);
char *make_status_to_string(status_t status);
status_t make_string_to_status(char *string);
void print_cli_usage();

#endif
