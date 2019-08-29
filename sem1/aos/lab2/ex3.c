#include <stdio.h> 
#include <stdlib.h> 
#include <unistd.h> //Header file for sleep(). man 3 sleep for details. 
#include <pthread.h> 
#include<sys/types.h> 
#include<string.h> 
#include<sys/wait.h> 
#include <math.h>

int main(){

    pid_t process1, process2, process3;
    int fd_p1[2];  // Used to store two ends of pipe 
    int fd_p2[2];  // Used to store two ends of pipe 
    int fd_p3[2];  // Used to store two ends of pipe 


    process1 = fork();
    process2 = fork();
    process3 = fork();


    if(process1 < 0){
        perror("Child process creation is failed");
        // exit(-1);
    }
    else if (process1 == 0){ // child process
        close(fd_p1[1]);
        int y;
        read(fd_p1[0], &y, sizeof(int));
        printf("Received number: %d\n", y);
        int res = checkPrime(y);
        printf("And number is ");
        if(res) printf("Prime\n");
        else printf("Not prime\n");
    }
    else { // parent process
        close(fd_p1[0]);
        printf("What no. you have to send to parent: ");
        scanf("%d", &x);
        write(fd_p1[1], &x, sizeof(int));
    }





    return 0;
}