# c-threadpool

C-threadpool is a threadpool implementation in c, originally written for my [c implementation of a simple server](https://github.com/SvenHepkema/c-api-server). Loosely based on [this blog](https://nachtimwald.com/2019/04/12/thread-pool-in-c/) by John Schember.

# Usage

This is an example of how you can use the threadpool:

``` c
#include<stdio.h>
#include<stdlib.h>

#include "src/threadpool.h"

const int N_TASKS = 1000;

void print_integer(void* input_arguments) {
    int* integer = (int*) input_arguments;

    printf("The number is %d\n", *integer);
}

int main() {
    // Creating the threadpool
    threadpool_t* threadpool = malloc(sizeof(threadpool_t));
    create_threadpool(10, threadpool);
    printf("Created the threadpool.\n");

    // Creating and adding all the tasks
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


    // Cleaning up the threadpool
    destroy_threadpool(threadpool);
    printf("Ended the threadpool.\n");

    return 0;
}

```

# Functionality

Multithreaded execution of tasks, with threads that are created once and reused for execution of the next task. There is no result queue implemented by the implementation to retrieve task results. 
