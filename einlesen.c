/*
 * @einlesen.c
 * @author  Gruppe  Wirth
 * @version 1.0
 *
 * @section DESCRIPTION
 *
 * Programm zum Einlesen, Prüfen und Trennen von Texteingaben, Suchen von Dateinamen.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

//Prototypes
int einlesen(char *);
void ausgeben(char *);
void trennen(char *);
void suchen(char *);
int anzahlBytes(void);
int leseBytes(int);

/*
 * Funktion zum einlesen von Worten bzw Dateinamen
 * @param char t[] eingelesene Worte bzw Dateinamen
*/

void einlesen(char t[]) {
	printf("Geben Sie ein paar Worte ein: ");
	fgets(t, MAX, stdin);
}


/*
 * Funktion zum Ausgeben der Eingabe- Testfunktion
*/

void ausgeben(char *t) {
	printf("Ihre Eingabe: %s", t);
}


/*
 * Funktion zum Trennen von Worten bzw Dateinamen
 * @param char t[] eingelesene Dateinamen
 * @param char ptr nach Leerzeichen und \n getrennte Dateinamen
*/

void trennen(char *t) {
	char *ptr;
	char trennzeichen[] = " ";
	ptr = strtok(t, "\n");
	ptr = strtok(t, trennzeichen);

	while (ptr != NULL) {
		suchen(ptr);
		ptr = strtok(NULL, trennzeichen);
		//int anzahl = sizeof(ptr);
		//printf("Anzahl Einheiten im Array: %d", anzahl);
	}
}


/*
 * Funktion zum Suchen von Dateinamen
 * @param char t[] eingelesene Dateinamen
 * @param FILE dateiname Pointer zum Aufrufen von Dateinamen
 * @param i Laufzeitvariable
*/

void suchen(char *ptr) {
	FILE* dateiname;
	int i = 0;
	
	i = anzahlBytes();
	printf("ausgabe: %s\n", ptr);
	if ((dateiname = fopen(ptr, "r")) != NULL) {
		printf("Datei existiert.\n");
		printf("Die ersten %c Bytes: ", i);
		leseBytes(i);
	}
	else {
		printf("Datei existiert nicht.\n");
	}
}


/*
 * Funktion zum Einlesen von Byte-Berten
 * @param ruechkabewert Anzahl der eingelesenen Bytes
*/

int anzahlBytes (void) {
	int rueckgabewert = 0;
	printf("Geben Sie die Anzahl an Bytes an: ");
	rueckgabewert = (getchar()/8);
	return rueckgabewert;
}


/*
 * Funktion zum Einlesen der ersten n Bytes einer Datei
 * @param char puffer[] eingelesene Worte einer Dtei
 * @param int anzahl Anzahl der einegelesenen Bytes
 * @param FILE quelle Pointer auf die zu lesende Datei
 * @param int i Laufzeitvariable
*/

int leseBytes (int anzahl) {
        char puffer[anzahl];
	FILE *quelle;

        quelle = fopen( "test.txt", "r+b");
        if (quelle != NULL){
                fread(&puffer, sizeof(char), anzahl, quelle);
	}

        // anzahl-1, sonst gibt er eine Stelle zu viel aus
        for (int i = 0; i < anzahl - 1; i++) {
                printf( "Wert %d = %c\n", i, puffer[i]);
        }
        return 0;
}


/*
 * Funktion zum Testen von Eingaben auf einstellige Zahlen
 * @param int c Testvariable 
 * @return -1 bei ungueltiger Eingabe
 * @return c bei gültiger Eingabe sprich bei Integerwert die vorderste Zahl
*/

//Den Vergleich macht er richtig, er akzeptiert aber leider auch eingaben >=10 indem er die erste Zahl wertet
int test(void){
  printf("Geben Sie eine Zahl zwischen 0 und 9 ein\n");
  int c = getchar();
	if ((c>47)&&(c<=57)){
	    return c;
	}
	else{
	    return -1;
	}
}


/*
 * Hauptprogrammaufruf
 * @param text pointer auf einen Textbereich mit der laenge MAX
*/

int main(void) {
	char text[MAX];
	einlesen(text);
	//ausgeben(text);
	trennen(text);
	return 0;
}

