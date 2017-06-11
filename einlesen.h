
/*
 * einlesen.h
 *
 *  Created on: 11.06.2017
 *      Author: wolf
 */

#ifndef EINLESEN_H_
#define EINLESEN_H_
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
int leseBytes(int, FILE*);


#endif /* EINLESEN_H_ */
