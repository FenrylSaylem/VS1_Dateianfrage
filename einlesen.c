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

int einlesen(char t[]) {
	printf("Geben Sie ein paar Worte ein: ");
	fgets(t, MAX, stdin);
	return 0;
}

void ausgeben(char *t) {
	printf("Ihre Eingabe: %s", t);
}

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

int anzahlBytes ( void ) {
	int i = 0;
	printf("Geben Sie die Anzahl an Bytes an: ");
	i = (getchar()/8);
	return i;
}

int leseBytes (int a) {
        char puffer[a];
	FILE *quelle;

        quelle = fopen( "test.txt", "r+b");
        if (quelle != NULL){
                fread(&puffer, sizeof(char), a, quelle);
	}

        // a-1, sonst gibt er eine Stelle zu viel aus
        for (int i = 0; i < a - 1; i++) {
                printf( "Wert %d = %c\n", i, puffer[i]);
        }
        return 0;
}

//Den Vergleich macht er richtig, er akzeptiert aber leider auch eingaben >=10 indem er die Zahl wertet
int test(int i){
  printf("Geben Sie eine Zahl zwischen 0 und 9 ein\n");
  int c = getchar();
	if ((c>47)&&(c<=57)){
	    return 0;
	}
	else
	  {
	    return 1;
	  }
  return i;
}

int main(void) {
	char text[MAX];
	einlesen(text);
	//ausgeben(text);
	trennen(text);
	return 0;
}

