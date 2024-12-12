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
// inet_addr()
#include <arpa/inet.h>
// exit()
#include <stdlib.h>
// memset
#include <string.h>

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


struct sockaddr_in* populateAddress(struct sockaddr_in* pAddress,socklen_t addr_size,__u_short portNumber,const char* ipAddress){
    //initializes the address to 0
    memset(pAddress,0,addr_size); 
    pAddress->sin_family = AF_INET;
    // htons converts little-endian to big-endian
    // if i wanted this to work on all machines consider implementing a helper function that figures out byte interpretation order
    pAddress->sin_port = htons(portNumber); 
    // TODO: add error checking of invalid ip addresses by using inet_aton instead of inet_addr
    pAddress->sin_addr.s_addr = inet_addr(ipAddress);
    return pAddress;
}

// Doesnt need to be threadsafe
int init_server(const char * ipAddress,const __u_short portNumber){
    // create the socket
    int sockfd = socket(AF_INET,SOCK_STREAM,0);
    //populate the address
    struct sockaddr_in address = *populateAddress(&address,sizeof(address),portNumber,ipAddress);
    int ret;
    socklen_t addr_size = sizeof(address);
    // bind the socket
    ret = bind(sockfd,(struct sockaddr*)&address,addr_size);
    if(ret != 0){
        printf("Error: Failed to bind socket");
        return -1;
    }
    return 0;
}

void* thread1(){
    printf("Stuff that can run asynchronusly");
    pthread_exit(0);
}

int main (){
    int checkError;
    printf("Enter IP address and port number of the client\n");
    printf("IP address is () on port ()\n");
    const char* ipAddress = "127.0.0.1";
    __u_short portNumber = 3000;
    checkError = init_server(ipAddress,portNumber);
    if(checkError == -1){
        printf("Error: Failed init_server()");
        exit(-1);
    }
    
    printf("Connection has been Established\n");
    
    pthread_t thread;
    printf("Creating thread\n");
    
    pthread_create(&thread,NULL,thread1,NULL);
    printf("Enter to end\n");
    scanf("Enter");
}