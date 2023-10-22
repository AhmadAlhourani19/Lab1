#pragma once

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXSTRING 20

typedef struct sCar {
	char brand[MAXSTRING];
	char licensePlate[MAXSTRING];
} sCar;

typedef struct sElement {
	sCar* car;
	struct sElement* prev;
} sElement;

sElement* push(sElement* last);
sElement* pop(sElement* last);
int isEmpty(sElement* last);
int countElements(sElement* last);
void printStack(sElement* last);
