#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "StackArrayLib.h"

int main() {
	sCar* stack[MAXARRAY];
	for (int i = 0; i < MAXARRAY; i++) {
		stack[i] = NULL;
	}

	int choice;
	int number = 0;

	printf("Welcome to our stack program!\n\n");

	while (1) {
		printf("What would you like to do next?\n");
		printf("\t1: Push new element on the stack\n");
		printf("\t2: Pop element from the stack\n");
		printf("\t3: Count elements in the stack\n");
		printf("\t4: Print stack\n");
		printf("Press any other key to exit this program.\n");

		if (scanf("%d", &choice) != 1)
			return 0;

		switch (choice) {
		case 1:
			push(stack);
			break;
		case 2:
			pop(stack);
			break;
		case 3:
			number = countElements(stack);
			printf("The stack has %d elements.\n\n", number);
			break;
		case 4:
			printStack(stack);
			break;
		default:
			return 0;
		}
	}
	return 0;
}