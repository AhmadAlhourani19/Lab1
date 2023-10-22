#include "StackArrayLib.h"

void push(sCar* stack[]) {
	if (countElements(stack) == MAXARRAY) {
		printf("Stack is full! \n");
	}

	sCar* newCar = (sCar*)malloc(sizeof(sCar));
	if (newCar == NULL) {
		printf("Memory allocation failed\n");
		exit(1);
	}

	printf("Enter Car brand: \n");
	scanf("%s", newCar->brand);

	printf("Enter Car licensePlate: \n");
	scanf("%s", newCar->licensePlate);

	for (int i = 0; i < MAXARRAY; i++) {
		if (stack[i] == NULL) {
			stack[i] = newCar;
			break;
		}
	}
}

void pop(sCar* stack[]) {
	if (isEmpty(stack)) {
		printf("Stack is empty. Nothing to POP: \n");
	}

	for (int i = 0; i < MAXARRAY; i++) {
		if (stack[i] != NULL) {
			printf("popped car: \n");
			printf("Car brand %s", stack[i]->brand);
			printf("Car licensePlate %s", stack[i]->licensePlate);

			free(stack[i]);
			stack[i] = NULL;
			break;
		}
	}
}

int isEmpty(sCar* stack[]) {
	for (int i = 0; i < MAXARRAY; i++) {
		if (stack[i] != NULL) {
			return 0;
		}
	}
	return 1;
}

int countElements(sCar* stack[]) {
	int count = 0;
	for (int i = 0; i < MAXARRAY; i++) {
		if (stack[i] != NULL) {
			count++;
		}
	}
	return count;
}

void printStack(sCar* stack[]) {
	int number = countElements(stack);
	if (number == 0)
		printf("Stack is empty.\n");
	number--;
	while ((number >= 0) && (stack[number] != NULL)) {
		printf("The car %d is:\n", number + 1);
		printf("Brand: %s\n", stack[number]->brand);
		printf("License Plate: %s\n\n", stack[number]->licensePlate);
		number--;
	}
}