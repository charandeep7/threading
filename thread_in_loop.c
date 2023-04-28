#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>


void* routine(void *thread_no)
{
    printf("Process Id: %d, Thread: %d\n",getpid(),(int*)thread_no);
}

int main()
{
    const int N = 100;
    pthread_t thread[N];
    
    for(int i=0; i<N; ++i){
        if(pthread_create(&thread[i],NULL,routine,(void*)i)){
            printf("error in creating thread %d\n",i);
        }
    }
    
    for(int i=0; i<N; ++i){
        pthread_join(thread[i],NULL);
    }
    
    pthread_exit(NULL);
    
    return 0;
}
