#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <time.h>

void* roll_die()
{
    int value = (int)(rand() % 6) + 1;
    int* result = malloc(sizeof(int));
    *result = value;
    printf("value = %d\n",value);
    return (void*)result;
}

int main()
{
    int* die_roll_result;
    
    srand(time(NULL));
    
    pthread_t thread;
    if(pthread_create(&thread,NULL,roll_die,NULL)){
        printf("error in creating thread\n");
    }
    
    pthread_join(thread,(void**)&die_roll_result);
    
    printf("Die_roll_result = %d\n",*die_roll_result);
    
    free(die_roll_result);
    
    pthread_exit(NULL);
    
    return 0;
}
