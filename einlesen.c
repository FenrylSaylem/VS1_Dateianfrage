
/*
 * liest Dateinamen von Benutzer
 * teilt den String
 * prueft ob Datei existiert
 * oeffnet datei und liest erste vier bytes
 * main
 */


#include "einlesen.h"

/**
 * einlesen der Dateinamen in einem String
 *
 * @param t[] Array
 */
int einlesen(char *t) {
	printf("Geben Sie ein paar Worte ein: ");
	fgets(t, MAX, stdin);
	return 0;
}
/**
 * ausgeben der Benutzereingaben
 *
 * @param *t Array
 */
void ausgeben(char *t) {
	printf("\n\nIhre Eingabe: %s", t);
}

/**
 * trennt den String an jedem leerzeichen
 * schneidet '/n' am schluss ab
 *
 * @param *t Array mit String
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

/**
 * sucht ob Datei existiert
 * wenn ja oeffne und lese ersten 4 Bytes
 *
 * @param *ptr Pointer auf Teilstring
 */
void suchen(char *ptr) {
	FILE* dateiname;
	int i = 0;

	i = 4;  //anzahlBytes();
	printf("ausgabe: %s\n", ptr);
	if ((dateiname = fopen(ptr, "r")) != NULL) {
		printf("Datei existiert.\n");
		printf("Die ersten %c Bytes: ", i);
		leseBytes(i);
	} else {
		printf("Datei existiert nicht.\n");
	}
}

/**
 * liest die Anzahl an Bytes vom Benutzer ein
 */
int anzahlBytes(void) {
	int i = 0;
	printf("Geben Sie die Anzahl an Bytes an: ");
	i = (getchar() / 8);
	return i;
}

/**
 * liest die ersten Bytes
 *
 * @param a Anzahl der zu lesenden Bytes
 */
int leseBytes(int a) {
	char puffer[a];
	FILE *quelle;

	quelle = fopen("test.txt", "r+b");
	if (quelle != NULL) {
		fread(&puffer, sizeof(char), a, quelle);
	}

	// a-1, sonst gibt er eine Stelle zu viel aus
	for (int i = 1; i < a + 1; i++) {
		printf("\nWert %d = %d\n", i, puffer[i]);
	}
	return 0;
}

//Den Vergleich macht er richtig, er akzeptiert aber leider auch eingaben >=10 indem er die Zahl wertet
//int test(int i) {
//	printf("Geben Sie eine Zahl zwischen 0 und 9 ein\n");
//	int c = getchar();
//	if ((c > 47) && (c <= 57)) {
//		return 0;
//	} else {
//		return 2;
//	}
//	return i;
//}

int main(void) {
	char text[MAX];
	einlesen(text);
	//ausgeben(text);
	trennen(text);
	return 0;
}

