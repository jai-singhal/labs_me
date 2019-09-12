#include<iostream>
#include <sys/ipc.h> 
#include <sys/msg.h> 
#include <sys/types.h> 
#include <unistd.h> 
#include <cstring> 
#include <pthread.h> 
#include <bits/stdc++.h>

using namespace std;

#define HELL printf("done\n");
#define print(x) cout << x << endl

// structure for message queue 
struct mesg_buffer { 
    int sender;
    int clock;
    // char mesg_text[100]; 
} message; 

struct process{
    /* data */
    pthread_t pid;
    int time;
    key_t queue; 
    int mesgid;
};

process dme[3];


mesg_buffer messageRecv(int reciever, key_t key){
    msgrcv(dme[reciever].mesgid, &message, sizeof(message), 1, 0); 
    return message;
}

void broadcastMsg(int sender, int clock){
    message.clock = clock;
    message.sender = sender; 
    // msgsnd to send message broasdcast
    for(int i = 0; i <= 2; i++){
        if(i+1 != sender){
            msgsnd(i+1, &message, sizeof(message), 0); 
        }
    }
}

void *dme_func0(void *vargp) { 
    broadcastMsg(1, 1);
    print("1st thread message sent");
   
    // while(1){
         msgrcv(1, &message, sizeof(message), 1, 0);
        cout << message.sender << " " << message.clock << endl;
    // }
    return NULL; 
} 


void *dme_func1(void *vargp) { 
    broadcastMsg(2, 1);
    print("2st thread message sent");
    
    // while(1){
         msgrcv(2, &message, sizeof(message), 1, 0);
        cout << message.sender << " " << message.clock << endl;
    // }
    return NULL; 
} 

void *dme_func2(void *vargp) { 
    // while(1){
        print("3st thread message sent");
        msgrcv(3, &message, sizeof(message), 1, 0);
        cout << message.sender << " " << message.clock << endl;
    // }
    return NULL; 
} 


int main(int argc, const char** argv) {
    
    dme[0].queue = ftok("pilot", 64);
    dme[1].queue = ftok("pilot", 65); 
    dme[2].queue = ftok("pilot", 66);

    dme[0].mesgid  = msgget(1, 0666 | IPC_CREAT); 
    dme[1].mesgid  = msgget(2, 0666 | IPC_CREAT); 
    dme[2].mesgid  = msgget(3, 0666 | IPC_CREAT); 

    HELL;

    pthread_create(&dme[0].pid, NULL, dme_func0, NULL); 
    pthread_create(&dme[1].pid, NULL, dme_func1, NULL); 
    pthread_create(&dme[2].pid, NULL, dme_func2, NULL); 

    pthread_join(dme[0].pid, NULL); 
    pthread_join(dme[1].pid, NULL); 
    pthread_join(dme[2].pid, NULL); 


    return 0;
}
