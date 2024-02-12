#include <pthread.h>
#include <stdlib.h>
#include<stdio.h>

#include "threadpool.h"

void* run_thread(void* arg) {
	task_t* task;

	//task->task_executor(task->input_arguments);
	printf("Hello I exist\n");

	return NULL;
}

int create_threadpool(int n_threads, threadpool_t* threadpool) {
	threadpool->n_threads = n_threads;
	threadpool->threads = malloc(sizeof(pthread_t) * n_threads);

	for (size_t i = 0; i < n_threads; i++) {
		pthread_create(&threadpool->threads[i], NULL, run_thread, NULL);
	}

	return 0;
}

int add_task_to_threadpool(task_t* task, threadpool_t* threadpool) {
	return 0;
}

int destroy_threadpool(threadpool_t* threadpool) {
	for (size_t i = 0; i < threadpool->n_threads; i++) {
		pthread_join(threadpool->threads[i], NULL);
	}

	return 0;
}
