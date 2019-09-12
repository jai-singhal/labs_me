#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

int globalVar = 6;

int main(int argc, char const *argv[]){

    int var;
    pid_t pid;
    var = 88;
    int myvar = 1;
    int i;
    printf("Before fork\n");


  //  for(i = 0; i < 3; i++){
        pid = fork();
        globalVar++;
        
//}

    if(pid < 0){
        perror("ERROR in creating child process\n");
    }
    else if(pid > 0){
        sleep(3);
        printf("Child process: pid = %d global var = %d var = %d my_var = %d \n", getpid(), globalVar, var, myvar);
    }
    else{ // pid = 0; parent process
        var++;
        // globalVar++;
        printf("Parent process: pid = %d global var = %d var = %d my_var = %d \n", getpid(), globalVar, var, myvar);
        exit(0);
    }

    return 0;
}
