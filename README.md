# c-threadpool

C-threadpool is a threadpool implementation in c, originally written for my [c implementation of a simple server](https://github.com/SvenHepkema/c-api-server). Loosely based on [this blog](https://nachtimwald.com/2019/04/12/thread-pool-in-c/) by John Schember.

# Usage

This is an example of how you can use the threadpool:

``` c
#include <stdio.h>
#include <stdlib.h>

#include "src/threadpool.h"

const int N_TASKS = 10000;

void print_integer(void *input_arguments) {
  int *integer = (int *)input_arguments;
  printf("The number is %d\n", *integer);
  free(integer);
}

int main() {
  // Creating the threadpool
  threadpool_t *threadpool = malloc(sizeof(threadpool_t));
  create_threadpool(10, 100, threadpool);

  // Adding all the tasks
  for (int i = 0; i < N_TASKS; i++) {
    int *integer = malloc(sizeof(int));
    *integer = i;

    add_task_to_threadpool(print_integer, integer, threadpool);
  }

  // Destroying the threadpool
  destroy_threadpool(threadpool);
  free(threadpool);

  return 0;
}
```

# Functionality

Multithreaded execution of tasks, with threads that are created once and reused for execution of the next task. There is no result queue implemented by the implementation to retrieve task results. The allocation of tasks to threads is dynamic, when a thread is finished with a task it asks for a new task, if there are no tasks available, the thread sleeps for a small amount of time. When the destroy threadpool function is called, all tasks in the queue are first finished and then the threads are cleaned up.
