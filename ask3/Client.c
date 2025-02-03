#include <netdb.h> 
#include <stdio.h> 
#include <stdlib.h>
#include <time.h>
#include <netinet/in.h> 
#include <sys/types.h>
#include <string.h> 
#include <sys/socket.h> 
#define MAX 80 
#define PORT 8080 
#define SA struct sockaddr 
  
int main() 
{ 
    int sockfd, connfd; 
    struct sockaddr_in servaddr, cli; 
  
    // socket create and varification 
    sockfd = socket(AF_INET, SOCK_STREAM, 0); 
    if (sockfd == -1) { 
        printf("socket creation failed...\n"); 
        exit(0); 
    } 
    else
        printf("Socket successfully created..\n"); 
    bzero(&servaddr, sizeof(servaddr)); 
  
    // assign IP, PORT 
    servaddr.sin_family = AF_INET; 
    servaddr.sin_addr.s_addr = inet_addr("127.0.0.1"); 
    servaddr.sin_port = htons(PORT); 
  
    // connect the client socket to server socket 
    if (connect(sockfd, (SA*)&servaddr, sizeof(servaddr)) != 0) { 
        printf("connection with the server failed...\n"); 
        exit(0); 
    } 
    else
        printf("connected to the server..\n"); 
  
    // function for chat
    srand(time(NULL));
    int i;
    for (i = 0; i < 10; i++){
        int ch = rand() % 20;
        int anser;
        write(sockfd, &ch, sizeof(ch)); 

        read(sockfd, &anser, sizeof(anser)); 
    }
    
  
    // close the socket 
    close(sockfd); 
} 