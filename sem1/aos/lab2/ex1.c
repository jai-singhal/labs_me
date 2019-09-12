#include <stdio.h> 
#include <stdlib.h> 
#include <unistd.h> //Header file for sleep(). man 3 sleep for details. 
#include <pthread.h> 
#include<sys/types.h> 
#include<string.h> 
#include<sys/wait.h> 
/*
 fd[0]; //-> for using read end
 fd[1]; //-> for using write end
*/

int checkPrime(int n){
    for(int i = 2; i*i <= n; i++){
        if(n % i == 0)
            return 0;
        while(n%i == 0){
            n = n/i;
        }
    }
    return 1;
}

int  main(){
    pid_t childPid; 
    int x;

    int fd[2];  // Used to store two ends of pipe 
    pipe(fd);

    childPid = fork();

    if(childPid < 0){
        perror("Child process creation is failed");
        // exit(-1);
    }
    else if (childPid == 0){ // child process
        close(fd[1]);
        int y;
        read(fd[0], &y, sizeof(int));
        printf("Received number: %d\n", y);
        int res = checkPrime(y);
        printf("And number is ");
        if(res) printf("Prime\n");
        else printf("Not prime\n");
    }
    else { // parent process
        close(fd[0]);
        printf("What no. you have to send to parent: ");
        scanf("%d", &x);
        write(fd[1], &x, sizeof(int));
    }

    return 0;

}