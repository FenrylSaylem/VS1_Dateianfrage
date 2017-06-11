/*
 * @Client.c
 * @author  Gruppe  Wirth
 * @version 1.0
 *
 * @section DESCRIPTION
 *
 * Clientseitiges Programm zum steuern von Datenuebertragungen durch Sockets.
 */

#include<stdio.h> //printf
#include<string.h>    //strlen
#include<sys/socket.h>    //socket
#include<arpa/inet.h> //inet_addr

/*
 * Clientseitiger Hauptprogrammablauf
 * @param int sock Nummer des zu erstellenden Sockets
 * @param sockaddr_in server struct zum zuweisen des Sockets
 * @param message an den Server zu sendende Daten
 * @param von dem Server empfangene Daten
*/

int main(int argc, char *argv[]) {
    int sock;
    struct sockaddr_in server;
    char message[1000];
    char server_reply[2000];

    //Einrichtung eines Sockets, Fehlermeldung wenn nicht.
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        printf("Socket konnte nicht erstellt werden");
    }
    puts("Socket erstellt");

    //Serveremulation durch verwenden des Localhosts
    server.sin_addr.s_addr = inet_addr("127.0.0.1");
    
    //Bekanntgabe der Serverfamilie (Adressfamilie)
    server.sin_family = AF_INET;
    
    //Kommunikation über den 8888 Port des Servers
    server.sin_port = htons(8888);

    //Verbinden zu einem Remoteserver, perror und return 1 wenn nicht erfolgreich
    if (connect(sock, (struct sockaddr *) &server, sizeof(server)) < 0) {
        perror("connect failed. Error");
        return 1;
    }
    
    //Wenn erfolgreich Connected ausgeben
    puts("Verbunden\n");

    //Aufrechterhaltung der Kommunikatiuon zum Server mittels While-Schleife
    while (1) {
        printf("Ihre Nachricht: ");
        scanf("%s", message);

        //Senden von Daten, wenn nicht erfolgreich ausgeben Senden fehlgeschlagen
        if (send(sock, message, strlen(message), 0) < 0) {
            puts("\nSenden fehlgeschlagen\n");
            return 1;
        }

        //Empfang einer serverseitigen Antwort 
        if (recv(sock, server_reply, 2000, 0) < 0) {
            puts("\nKeine Antwort durch den Server\n");
            break;
        }

        puts("Server antwortet:");
        puts(server_reply);
        printf("\n");
    
    }
    
    //Socket schliessen
    close(sock);
    return 0;
}
