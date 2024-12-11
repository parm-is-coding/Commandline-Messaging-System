#include <stdbool.h>
#include <string.h>
#include <stdio.h>

int main(){
    char message[32];
    bool end = false;
    do {
        printf("Enter a message:\n");
        scanf("%s",message);
        if(strcmp(message,"exit") == 0){
            end = true;
        }else{
            printf("Message: %s \nHas been sent to the server\n",message);
        }
    }while (end != true);

}