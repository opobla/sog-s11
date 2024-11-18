#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
    int pid;
    int worker_count_target = 5;
    int status;

    for(int worker_count = 0; worker_count < worker_count_target ; worker_count++) {
        pid = fork();
        if (pid == 0) {
            // This code is to be executed by the child
            // WORKERS
            // Actual work simulation
            sleep(1);
            printf("I am the worker #%d, pid=%d and ppid=%d \n", 
                    worker_count, 
                    getpid(), 
                    getppid());
            sleep(5-worker_count);
            printf("Worker #%d exiting...\n", worker_count);
            exit(0);
        } 
    }

    printf("I am the father with pid %d and my father %d \n", getpid(), getppid());
    printf("Waiting for my %d children to finish\n", worker_count_target);

    for(int worker_count = 0; worker_count < worker_count_target ; worker_count++) {
        printf("Father waiting ..\n");
        pid = wait(&status);
        printf("Father: child with PID=%d finished ..\n", pid);
    }
    printf("Father exiting ..\n");
}
