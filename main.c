#include<stdio.h>
#include<stdlib.h>

#include "src/threadpool.h"

const int N_TASKS = 1000;

void print_integer(void* input_arguments) {
	int* integer = (int*) input_arguments;

	printf("The number is %d\n", *integer);
}

int main() {
	// ======================
	// Creating the threadpool
	// ======================
	
	threadpool_t* threadpool = malloc(sizeof(threadpool_t));
	create_threadpool(10, threadpool);

	printf("Created the threadpool.\n");

	// ======================
	// Adding all the tasks
	// ======================
	
	task_t* task;
	int* integer;
	for (int i = 0; i < N_TASKS; i++) {
		integer = malloc(sizeof(int));
		*integer = i;

		task = malloc(sizeof(task_t));
		task->task_executor = print_integer;
		task->input_arguments = integer;

		add_task_to_threadpool(task, threadpool);
	}

	printf("Added all the tasks to threadpool.\n");


	// ======================
	// Destroying the threadpool
	// ======================
	
	destroy_threadpool(threadpool);

	printf("Ended the threadpool.\n");

	return 0;
}
