#include <unistd.h>
#include <stdio.h>
#include <pthread.h>

void* writer_thread(void* args) {
    int local = 0;

    for(int counter=0; counter<20; counter++) {
        local = local + 1;
        printf("The value of local=%d\n", local);
        usleep(200000); // microseconds
    }
    return NULL;
}

int main() {
    // TODO: Add command line args for the number of points and 
    // the number of threads
    pthread_t thread_1;
    printf("Main function starting\n");
    pthread_create(&thread_1, NULL, writer_thread, NULL);

    printf("Main function sleeping\n");
    sleep(1);
    printf("Main function exiting\n");
    return 0;

}
