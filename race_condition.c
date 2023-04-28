#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>


int mails = 0;

void* routine()
{
    for(int i=0; i<10000000; ++i){
        mails++;
    }
}

int main()
{
    pthread_t t1,t2;
    
    if(pthread_create(&t1,NULL,routine,NULL)){
        printf("error in thread 1\n");
    }
    if(pthread_create(&t2,NULL,routine,NULL)){
        printf("error in thread 2\n");
    }
    
    pthread_join(t1,NULL);
    pthread_join(t2,NULL);
    
    printf("The number of mails = %d\n",mails);
    pthread_exit(NULL);
    
    return 0;
}
