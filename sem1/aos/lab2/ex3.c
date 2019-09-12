#include <stdio.h> 
#include <stdlib.h> 
#include <unistd.h> //Header file for sleep(). man 3 sleep for details. 
#include <pthread.h> 
#include<sys/types.h> 
#include<string.h> 
#include<sys/wait.h> 
#include <math.h>

int main(){

    pthread_t process1, process2, process3;
    int fd_p1[2];  // Used to store two ends of pipe 
    int fd_p2[2];  // Used to store two ends of pipe 
    int fd_p3[2];  // Used to store two ends of pipe 


    pthread_create(&process1, NULL, countThread1, NULL);
    pthread_create(&process2, NULL, countThread2, NULL); 
    pthread_create(&process3, NULL, countThread3, NULL); 




    return 0;
}