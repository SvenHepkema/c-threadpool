#include <pthread.h>
#include <ctype.h>

#ifndef THREADPOOL_H
#define THREADPOOL_H


typedef struct task {
	struct task* next;
	void* input_arguments;
	void (*task_executor)(void* input_arguments);
} task_t;


typedef struct task_list {
	size_t n_tasks;
	task_t* first_task;
	task_t* last_task;
} task_list_t;


typedef struct threadpool {
	size_t n_threads;
	pthread_t* threads;

	task_list_t task_list;
} threadpool_t;


int create_threadpool(int n_threads, threadpool_t* threadpool);
int add_task_to_threadpool(task_t* task, threadpool_t* threadpool);
int destroy_threadpool(threadpool_t* threadpool);


#endif // THREADPOOL_H
