#include <unistd.h>
#include <stdio.h>

int main() {
    int pid;

    pid = fork();
    if (pid == 0) {
        // This code is to be executed by the child
        printf("I am the child with pid %d and my father %d, and pid=%d \n", getpid(), getppid(), pid);
    } else {
        // This code is to be executed by the father
        printf("I am the father with pid %d and my father %d, and pid=%d \n", getpid(), getppid(), pid);
    }


    sleep(1);

}
