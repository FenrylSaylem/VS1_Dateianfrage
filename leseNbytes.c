/*
 * Kleines Programm um n Bytest einer Datei wiederzugeben.
*/

#include<stdio.h>
#include<stdlib.h>

int leseBytes (int a) {
	char puffer[a];
	FILE *quelle;

	quelle = fopen( "test.txt", "r+b");
	if (quelle != NULL)
		fread(&puffer, sizeof(char), a, quelle);

	// a-1, sonst gibt er eine Stelle zu viel aus
	for (int i = 0; i < a - 1; i++) {
		printf( "Wert %d = %c\n", i, puffer[i]);
	}
	return 0;
}

int main (void) {
	int i = 0;

	printf("Geben Sie die Anzahl an Bytes an: ");
	i = (getchar()/8);
	printf("%c\n", i);
	
	leseBytes(i);

	return 0;
}

