#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>


int mails = 0;
pthread_mutex_t mutex;

void* routine()
{
    for(int i=0; i<10000000; ++i){
        pthread_mutex_lock(&mutex);
        mails++;
        pthread_mutex_unlock(&mutex);
    }
}

int main()
{
    pthread_t t1,t2;
    
    pthread_mutex_init(&mutex,NULL);
    
    if(pthread_create(&t1,NULL,routine,NULL)){
        printf("error in thread 1\n");
    }
    if(pthread_create(&t2,NULL,routine,NULL)){
        printf("error in thread 2\n");
    }
    
    pthread_join(t1,NULL);
    pthread_join(t2,NULL);
    
    pthread_mutex_destroy(&mutex);
    
    printf("The number of mails = %d\n",mails);
    pthread_exit(NULL);
    
    return 0;
}
