#include <stdio.h> 
#include <stdlib.h> 
#include <unistd.h> //Header file for sleep(). man 3 sleep for details. 
#include <pthread.h> 
#include<sys/types.h> 
#include<string.h> 
#include<sys/wait.h> 
#include <math.h>

int MAXCOUNT = (int)pow(10,8);

void *countThread1(void *vargp) { 
    int a = 0;
    for(int i = 0; i < MAXCOUNT; i++)
        ++a;
    printf("A\n");
}

void *countThread2(void *vargp) { 
    int a = 0;
    for(int i = 0; i < MAXCOUNT; i++)
        ++a;
    printf("B\n");

} 

void *countThread3(void *vargp) { 
    int a = 0;
    for(int i = 0; i < MAXCOUNT; i++)
        ++a;
    printf("c\n");

} 


int main() { 
    pthread_t tid1, tid2, tid3; 

    pthread_create(&tid1, NULL, countThread1, NULL);
    pthread_create(&tid2, NULL, countThread2, NULL); 
    pthread_create(&tid3, NULL, countThread3, NULL); 

    pthread_join( tid1, NULL);
    pthread_join( tid2, NULL); 
    pthread_join( tid3, NULL); 

    return 0;
}
