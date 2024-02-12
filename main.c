#include<stdio.h>
#include<stdlib.h>

#include "src/threadpool.h"

const int N_TASKS = 1000;

void print_integer(void* input_arguments) {
	int* integer = (int*) input_arguments;
	printf("The number is %d\n", *integer);
	free(integer);
}

int main() {
	// Creating the threadpool
	threadpool_t* threadpool = malloc(sizeof(threadpool_t));
	create_threadpool(10, threadpool);

	// Adding all the tasks
	for (int i = 0; i < N_TASKS; i++) {
		int* integer = malloc(sizeof(int));
		*integer = i;

		add_task_to_threadpool(print_integer, integer, threadpool);
	}

	// Destroying the threadpool
	destroy_threadpool(threadpool);
	free(threadpool);

	return 0;
}
