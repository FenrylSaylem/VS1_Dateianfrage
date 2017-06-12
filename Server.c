/**
 *  Server.c
 *
 *  creates a Server with Socket, that delivers a list of files and send n bytes of files to a client
*/

#include<stdio.h>
#include<string.h>    //strlen
#include<stdlib.h>    //strlen
#include<sys/socket.h>
#include<arpa/inet.h> //inet_addr
#include<unistd.h>    //write
#include<pthread.h> //for threading , link with lpthread
#include<stdbool.h>
#include<ctype.h>


//the thread function
void *connection_handler(void *);

/**
 * Creates socket and is waiting for client connections
 * creates a connection handler thread for every client instance
 *
 * @return 0 if succesfully
 */
int main(void) {
    int socket_desc, client_sock, c, *new_sock;
    struct sockaddr_in server, client;

    //Create socket
    socket_desc = socket(AF_INET, SOCK_STREAM, 0);
    if (socket_desc == -1) {
        perror("Could not create socket");
        exit(EXIT_FAILURE);
    }
    puts("Socket created");

    //Prepare the sockaddr_in structure
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = INADDR_ANY;
    server.sin_port = htons(8888);

    //Bind
    if (bind(socket_desc, (struct sockaddr *) &server, sizeof(server)) < 0) {
        //print the error message
        perror("bind failed. Error");
        return 1;
    }
    puts("bind done");

    //Listen
    listen(socket_desc, 3);

    //Accept and incoming connection
    puts("Waiting for incoming connections...");
    c = sizeof(struct sockaddr_in);


    /*Accept and incoming connection
    puts("Waiting for incoming connections...");
    c = sizeof(struct sockaddr_in);*/
    while ((client_sock = accept(socket_desc, (struct sockaddr *) &client, (socklen_t *) &c))) {
        puts("Connection accepted");

        pthread_t sniffer_thread;
        new_sock = malloc(1);
        *new_sock = client_sock;

        if (pthread_create(&sniffer_thread, NULL, connection_handler, (void *) new_sock) < 0) {
            perror("could not create thread");
            exit(EXIT_FAILURE);
        }

        //Now join the thread , so that we dont terminate before the thread
        //pthread_join( sniffer_thread , NULL);
        puts("Handler assigned");
    }

    if (client_sock < 0) {
        perror("accept failed");
        return 1;
    }

    return 0;
}

/**
 * Fügt einen Char an
 */
void append(char *str, char c) {
    size_t len = strlen(str);
    char *str2 = malloc(len + 1 + 1);
    strcpy(str2, str);
    str2[len] = c;
    str2[len + 1] = '\0';

}

/**
 * liest die ersten Bytes
 *
 * @param a Anzahl der zu lesenden Bytes
 * @param quelle file pointer zur Datei asu der gelesen werden soll
 */
char *leseBytes(int n, FILE *quelle) {
    char puffer[n];
    char *msg = "";
    char *str = malloc(sizeof(char) * n);

    fread(&puffer, sizeof(char), n, quelle);

    for (int i = 0; i < n - 1; i++) {
        append(msg, puffer[i]);
    }

    switch (n) {
        case 1:
            sprintf(str, "%c\n", puffer[0]);
            break;
        case 2:
            sprintf(str, "%c%c\n", puffer[0], puffer[1]);
            break;
        case 3:
            sprintf(str, "%c%c%c\n", puffer[0], puffer[1], puffer[2]);
            break;
        case 4:
            sprintf(str, "%c%c%c%c\n", puffer[0], puffer[1], puffer[2], puffer[3]);
            break;
        case 5:
            sprintf(str, "%c%c%c%c%c\n", puffer[0], puffer[1], puffer[2], puffer[3], puffer[4]);
            break;
        case 6:
            sprintf(str, "%c%c%c%c%c%c\n", puffer[0], puffer[1], puffer[2], puffer[3], puffer[4], puffer[5]);
            break;
        case 7:
            sprintf(str, "%c%c%c%c%c%c%c\n", puffer[0], puffer[1], puffer[2], puffer[3], puffer[4], puffer[5], puffer[6]);
            break;
        case 8:
            sprintf(str, "%c%c%c%c%c%c%c%c\n", puffer[0], puffer[1], puffer[2], puffer[3], puffer[4], puffer[5],
                    puffer[6], puffer[7]);
            break;
        case 9:
            sprintf(str, "%c%c%c%c%c%c%c%c%c\n", puffer[0], puffer[1], puffer[2], puffer[3], puffer[4], puffer[5],
                    puffer[6], puffer[7], puffer[8]);
            break;
        case 10:
            sprintf(str, "%c%c%c%c%c%c%c%c%c%c\n", puffer[0], puffer[1], puffer[2], puffer[3], puffer[4], puffer[5],
                    puffer[6], puffer[7], puffer[8], puffer[9]);
            break;
        default:
            sprintf(str, "Zu viele Bytes oder zu wenige Bytes\n");
    }
    return str;
}

/**
 * sucht ob Datei existiert
 * wenn ja oeffne und lese ersten 4 Bytes
 *
 * @param ptr Pointer auf Teilstring
 * @param n Anzahl der Bytes
 */
char *suchen(char **ptr, int n) {
    FILE *dateiname;

    if ((dateiname = fopen(*ptr, "r")) != NULL) {
        return leseBytes(n, dateiname);
    } else {
        return "Datei existiert nicht.\n";
    }
}

/**
 * trennt den String an jedem leerzeichen
 * schneidet '/n' am schluss ab
 *
 * @param t Array mit String
 */
int trennen(char t[], char *w[]) {
    int i = 0;
    char trennzeichen[] = ",";
    w[0] = strtok(t, trennzeichen);

    while (w[i] != NULL) {
        i++;
        w[i] = strtok(NULL, trennzeichen);
    }

    return i;
}

/**
 * prüft einen string ob er nur Zahlen enthält
 *
 * @param str zu prüfender String
 * @return  true or false
 */
bool is_valid_int(char str) {
    // Handle negative numbers.
    //
    if (str == '-')
        ++str;

    // Handle empty string or just "-".
    //
    if (!str)
        return false;

    // Check for non-digit chars in the rest of the stirng.
    //
    while (str) {
        if (!isdigit(str))
            return false;
        else
            ++str;
    }

    return true;
}

/**
 * Connection handler serves data for each client connection
 *
 * @param socket_desc socket connection to client
 *
 * */
void *connection_handler(void *socket_desc) {
    //Get the socket descriptor
    int sock = *(int *) socket_desc;
    int read_size;
    char *message = "\0"; 
	char client_message[2000];
    char *words[100];
    int bytes = 0;
    int argumentCount = 0;

    //Receive a message from client, parse it and answer
    while ((read_size = recv(sock, client_message, 2000, 0)) > 0) {
        argumentCount = trennen(client_message, &words[0]);
        if (!is_valid_int(*words[0])) {
            bytes = atoi(words[0]);
            if ((bytes < 1 || bytes > 10) && !is_valid_int(*words[0])) {
                message = "The first Argument was too high, too low or not a number.\n";
                write(sock, message, strlen(message));
            } else if (argumentCount > 6 || argumentCount < 2) {
                message = "There were too many or too few Files given.\n";
                write(sock, message, strlen(message));
            } else {
                for (int j = 1; j < argumentCount; j++) {
                    message = suchen(&words[j], bytes);
                    write(sock, message, strlen(message));
                }
            }
        } else {
            message = "The first Argument was not an amount of bytes.\n";
            write(sock, message, strlen(message));
        }
        message = "";
        memset(&client_message[0], 0, sizeof(client_message));
    }
    if (read_size == 0) {
        puts("Client disconnected");
        fflush(stdout);
    } else if (read_size == -1) {
        perror("recv failed");
    }

    //Free the socket pointer
    free(socket_desc);
    return 0;
}

