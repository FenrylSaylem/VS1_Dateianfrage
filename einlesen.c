#include <stdio.h>
#include <stdlib.h>

#define MAX 100

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
	ptr = strtok(t, trennzeichen);

	while (ptr != NULL) {
		suchen(ptr);
		ptr = strtok(NULL, trennzeichen);
		int anzahl = sizeof(ptr);
		printf("Anzahl Einheiten im Array: %d", anzahl);
	}
}

int suchen(char *ptr) {
	FILE* dateiname;

	printf("ausgabe: %s\n", ptr);
	if ((dateiname = fopen(ptr, "r")) != NULL) {
		printf("Datei existiert.\n");
	}
	else {
		printf("Datei existiert nicht.\n");
	}
}

int main(void) {
	char text[MAX];
	einlesen(text);
	//ausgeben(text);
	trennen(text);
	return 0;
}
