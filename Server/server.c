// scanf and printf
#include <stdio.h>
// bool
#include <stdbool.h>
#include <pthread.h>
// sleep()
#include <unistd.h>

#define NUMTHREADS 2

// void *readInput(void * args){
//         printf("thread readInput");
//         // timeout 2 seconds
//         sleep(2);

//         // Exit the thread
//         pthread_exit(NULL);
//     }
    
//     void *receiveData(void* args){
//         printf("thread receiveData");
//         // timeout 2 seconds
//         sleep(2);
//         // Exit the thread
//         pthread_exit(NULL);
//     }


void* thread1(){
    printf("Thread start\n");
    sleep(5);
    printf("Thread half\n");
    sleep(5);
    printf("Thread finish\n");
    pthread_exit(0);
}

int main (){
    printf("Enter IP address and port number of the client\n");
    printf("IP address is () on port ()\n");
    printf("Connection has been Established\n");
    
    // bool exit = false;
    
    pthread_t thread;
    printf("Creating thread\n");
    
    pthread_create(&thread,NULL,thread1,NULL);
    printf("Enter to end\n");
    scanf("Enter");
}