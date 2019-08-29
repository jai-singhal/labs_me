#include <stdio.h> 
#include <stdlib.h> 
#include <unistd.h> //Header file for sleep(). man 3 sleep for details. 
#include <pthread.h> 

int g = 0;

// A normal C function that is executed as a thread 
// when its name is specified in pthread_create() 
void *myThreadFun(void *vargp) { 
    int *myid = (int *)vargp; 
    static int s = 0; 
  
    ++s; 
    ++g; 
    printf("Thread ID: %d, Static: %d, Global: %d\n", *myid, ++s, ++g); 
} 

int main() { 
    int i; 
    pthread_t tid; 
  
    // Let us create three threads 
    for (i = 0; i < 10; i++){
        pthread_create(&tid, NULL, myThreadFun, (void *)&tid); 
        pthread_join(tid, NULL); 
    }
  
    pthread_exit(NULL); 
    return 0; 
}
