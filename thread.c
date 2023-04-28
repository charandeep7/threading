#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>


void* routine(void *ptr )
{
    printf("Process Id: %d, %s\n",getpid(),(char*)ptr);
}

int main()
{
    pthread_t t1,t2;
    
    char *msg1 = "Thread 1", *msg2 = "Thread 2";
    
    if(pthread_create(&t1,NULL,routine,(void*)msg1)){
        printf("error in creating thread 1\n");
    }
    if(pthread_create(&t2,NULL,routine,(void*)msg2)){
        printf("error in creating thread 2\n");
    }
    
    pthread_join(t1,NULL);
    pthread_join(t2,NULL);
    
    pthread_exit(NULL);
    
    return 0;
}
