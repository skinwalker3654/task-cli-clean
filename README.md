# Task CLI Manager (C)

A CLI tool that manages tasks and saves them in
a file and allocates memory dynamicly

---

## Features
1. add
2. remove
3. rename
4. set-status
5. list
---

## Requirments:
`gcc` compiler and `Make` GNU tool.

### build and run:
```bash
make all
./task #arguments
```
### clear leftovers
```bash
make clean
```
---

## Database file
The tasks are saved in `database.txt` with form:

```
id|description|status|
```

example:

```
1|go for walk|pending|
2|eat food|in-progress|
```

---

## PROJECT LIST:
task_cli_tool/
    |- src/
    |   |- task_utils/
    |   |    |- task_utils.c
    |   |    |- task_utils.h
    |   |
    |   |- task_operations/
    |   |    |- task_operations.c
    |   |    |- task_operations.h
    |   |
    |   |- task_storage/
    |   |    |- task_storage.c
    |   |    |- task_storage.h
    |   |
    |   |- task_database/
    |   |- task_database.c
    |        |-  task_database.h
    |
    |- MAIN.c
    |- README.md
    |- Makefile

---

`BY`: skinwalker
# task-cli-clean
