/**
 *  Client for requesting data from a server
 *  Client ask for specific files and get n bytes of each file
 *
*/

#include<stdio.h> //printf
#include<stdlib.h> //EXIT_FAILURE
#include<string.h>    //strlen
#include<sys/socket.h>    //socket
#include<arpa/inet.h> //inet_addr
#include <unistd.h> //close

/**
 * Creates a socket and connects to a server
 * Requests the data from the server and wait for the reply
 *
 *
 */

int main(void) {
    int sock;
    struct sockaddr_in server;
    char message[1000], server_reply[2000];

    //Create socket
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        perror("Could not create socket");
        exit(EXIT_FAILURE);
    } else {
        puts("Socket created");
    }

    server.sin_addr.s_addr = inet_addr("127.0.0.1");
    server.sin_family = AF_INET;
    server.sin_port = htons(8888);

    //Connect to remote server
    if (connect(sock, (struct sockaddr *) &server, sizeof(server)) < 0) {
        perror("connect failed. Error");
        exit(EXIT_FAILURE);
    }

    puts("Connected\n");

    //keep communicating with server
    while (1) {
        printf("What Files are you asking for, and how many Bytes shall be given? Split the arguments with a comma, leading with the number of bytes.\n Message : ");
        scanf("%s", message);

        //Send some data
        if (send(sock, message, strlen(message), 0) < 0) {
            perror("Send failed");
            exit(EXIT_FAILURE);
        }

        //Receive a reply from the server
        if (recv(sock, server_reply, 2000, 0) < 0) {
            perror("recv failed");
            break;
        }

        puts("Server reply :");
        puts(server_reply);
	memset(&server_reply[0], 0 ,sizeof(server_reply ));
    }

   close(sock);
    return 0;
}
