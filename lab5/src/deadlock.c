#include<pthread.h>
#include<stdio.h>
#include<stdlib.h>
#include <unistd.h>

pthread_mutex_t lock1, lock2;

void *function1(){

    pthread_mutex_lock(&lock1);

    printf("Operation started in function1..\n");
    sleep(2);

    printf("Trying to get function2\n");
    pthread_mutex_lock(&lock2); 
    printf("Aquired function2\n");
    pthread_mutex_unlock(&lock2);

    printf("Operation finished in function1..\n");

    pthread_mutex_unlock(&lock1);

    pthread_exit(NULL);
}

void *function2(){

    pthread_mutex_lock(&lock2);

    printf("Operation started in function2..\n");
    sleep(2);

    printf("Trying to get function1\n");
    pthread_mutex_lock(&lock1); 
    printf("Aquired function1\n");
    pthread_mutex_unlock(&lock1);

    printf("Operation finished in function2..\n");

    pthread_mutex_unlock(&lock2);

    pthread_exit(NULL);
}

int main() {

    pthread_mutex_init(&lock1,NULL);
    pthread_mutex_init(&lock2,NULL);

    pthread_t t1,t2;

    pthread_create(&t1,NULL,function1,NULL);
    pthread_create(&t2,NULL,function2,NULL);

    pthread_join(t1,NULL);
    pthread_join(t2,NULL);

return 0;
}