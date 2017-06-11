
/*
 * @Server.c
 * @author  Gruppe  Wirth
 * @version 1.0
 *
 * @section DESCRIPTION
 *
 * Hauptprogramm zum Sicherstellen eienr Serverseitigen Kommunikation.
 */

#include<stdio.h>
#include<string.h>    //strlen
#include<stdlib.h>    //strlen
#include<sys/socket.h>
#include<arpa/inet.h> //inet_addr
#include<unistd.h>    //write
#include<pthread.h> //for threading , link with lpthread

#define MAX_WORDS 5

//the thread function

void *connection_handler(void *);

/*
 * Hauptprogramm
 * @param int socket_desc Socketnummer
 * @param int client_socket Socketnummer des Clients
 * @param int c Rechenwert
 * @param int new_sock pointer auf neuen socket
 * @param sockadr_in_server Server speichert hier Clientadresse
*/
int main(int argc, char *argv[]) {
    int socket_desc;
    int client_sock;
    int c;
    int *new_sock;
    struct sockaddr_in server, client;

    //Socket erstellen, Fehlermeldung wenn nicht
    socket_desc = socket(AF_INET, SOCK_STREAM, 0);
    if (socket_desc == -1) {
        printf("Could not create socket");
    }
    puts("Socket erstellt");

    //Strukturvorbereitung: sockaddr_in 
    server.sin_family = AF_INET; //Adressfamilie
    server.sin_addr.s_addr = INADDR_ANY;//egal welche Eingangsadresse
    server.sin_port = htons(8888);//Port 8888

    //Verbinden, Fehlermeldung wenn nicht möglich
    if (bind(socket_desc, (struct sockaddr *) &server, sizeof(server)) < 0) {
        //print the error message
        perror("bind failed. Error");
        return 1;
    }
    puts("Verbindung erfolgreich hergestellt");

    //Lauschen - warten auf eingehende Verbindungen
    listen(socket_desc, 3);
    puts("Warten auf eingehende Verbindungen...");
    c = sizeof(struct sockaddr_in);


    /*Accept and incoming connection
    puts("Waiting for incoming connections...");
    c = sizeof(struct sockaddr_in);*/
    
    //Verbindungshandler
    while ((client_sock = accept(socket_desc, (struct sockaddr *) &client, (socklen_t * ) & c))) {
        puts("Verbindung hergestellt\n");

        pthread_t sniffer_thread;
        new_sock = malloc(1);
        *new_sock = client_sock;

        if (pthread_create(&sniffer_thread, NULL, connection_handler, (void *) new_sock) < 0) {
            perror("could not create thread");
            return 1;
        }

        //Now join the thread , so that we dont terminate before the thread
        //pthread_join( sniffer_thread , NULL);
        puts("Handler zugewiesen");
    }

    if (client_sock < 0) {
        perror("accept failed");
        return 1;
    }

    return 0;
}
/*
 * Funktion zum haendeln von Verbindungen
 * @param sock casten des Socket_desc -integer zu einem Pointer, Socketnummer
 * @param message Nachrichten zur Eingabensteuerung
 * @param int read_size
 * @param char *message, client_message[2000]
 * 
 */
void *connection_handler(void *socket_desc) {
    //Get the socket descriptor
    int sock = *(int *) socket_desc;
    int read_size;
    char *message, client_message[2000];
    /*char *aPtr;
    char *buffer;
    char *words;
    FILE *fp;
    unsigned char test[10];
    int i = 0;
    int count = 0;
    */

    //Nachrichtenuebertragungen, Begrueßung und Eingabeparameter abfragen
    message = "Hallo ich bin dein Verbindungshaendler\n";
    write(sock, message, strlen(message));

    message = "Welche Dateien werden benötigt, wie viele Bytes sollen gelesen werden? Bitte die eingaben durch \",\" Trennen.\n";
    write(sock, message, strlen(message));

    //Receive a message from client
    while ((read_size = recv(sock, client_message, 2000, 0)) > 0) {
        //noch fehlerhafte Programmlogik
        /*puts("Das schaff ich noch.");
        buffer=strdup(client_message);
        do{
            aPtr = strsep(&buffer, ",");
            if  (aPtr && count < MAX_WORDS) 
            {
                words[count++] = *aPtr;
            }
        } while(aPtr && count < MAX_WORDS);
        if (count > 5)
        {
            puts("Es wurden zu viele Dateien angefragt.");
        }
        else
        {
            i=0;
            for(i; i<count;i++)
            {
                fp = fopen(&words[i], "r");
                if(fp == NULL)
                {
                    printf("Die Datei %s konnte NICHT geöffnet werden.",&words[i]);
                }
                else
                {
                    fread(test, words[count],1,fp);
                    puts(test);
                }
            }
        }*/
    }
    //Verbindungsabbau
    if (read_size == 0) {
        puts("Verbindung zum Client getrennt\n");
        fflush(stdout);
    } else if (read_size == -1) {
        perror("recv failed");
    }

    //freigeben des Socket-Pointers
    free(socket_desc);

    return 0;
}
