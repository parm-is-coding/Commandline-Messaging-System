// scanf and printf
#include <stdio.h>
// bool
#include <stdbool.h>
#include <pthread.h>
// sleep()
#include <unistd.h>
//socket()
#include <sys/socket.h>
//sock_addr_in
#include <netinet/in.h>
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
    int sockfd = socket(AF_INET,SOCK_STREAM,0);
    // Figureout sockaddr and socklen_t
    int ret;
    struct sockaddr_in address;
    
    socklen_t addr_size = sizeof(address);
    ret = bind(sockfd,address,addr_size);
    if(ret == -1){
        return -1;
    }
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