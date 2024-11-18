#include <unistd.h>
#include <stdio.h>

int main() {

    fork();
    printf("I am a process with pid %d \n", getpid());

}
