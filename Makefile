SOURCE = src/MAIN.c src/task_utils/task_utils.c src/task_operations/task_operations.c src/task_database/task_database.c src/task_storage/task_storage.c
DATABASEFILE = database.txt
TARGET = task
GCC = gcc

all: $(SOURCE)
	@echo "compiling the project..."
	$(CC) $^ -o $(TARGET)
	@echo "RUN: ./task"

clean:
	@echo "deleting executables..."
	rm -rf $(TARGET) $(DATABASEFILE)

.PHONY: all clean
