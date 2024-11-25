#include <unistd.h>
#include <stdio.h>
#include <pthread.h>
#include <limits.h>

long int global = 0;
// Mutex semaphore (lock) needs to be global to be shared
pthread_mutex_t mutex;

void* writer_thread(void* args) {
    int local = 0;

    for(int counter=0; counter<10000000; counter++) {
        local = local + 1;
        pthread_mutex_lock(&mutex);  // P(mutex)
        global = global + 1;
        pthread_mutex_unlock(&mutex); // V(mutex)
        //printf("The value of local=%d and global=%d\n", local, global);
        //usleep(200000); // microseconds
    }
    return NULL;
}

int main() {
    // TODO: Add command line args for the number of points and 
    // the number of threads
    pthread_t thread_1;
    pthread_t thread_2;

    pthread_mutex_init(&mutex, NULL);

    printf("Main function starting\n");
    pthread_create(&thread_1, NULL, writer_thread, NULL);
    pthread_create(&thread_2, NULL, writer_thread, NULL);

    printf("Main function sleeping\n");
    pthread_join(thread_1, NULL);
    pthread_join(thread_2, NULL);
    printf("The of global=%ld\n", global);
    printf("Main function exiting\n");
    return 0;

}
