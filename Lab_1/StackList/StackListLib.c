#define _CRT_SECURE_NO_WARNINGS
#include "StackListLib.h"

sElement* push(sElement* last) {
    sCar* newCar = (sCar*)malloc(sizeof(sCar));
    if (newCar == NULL) {
        printf("Memory allocation failed.\n");
        return last;
    }

    printf("Enter car brand: ");
    scanf("%s", newCar->brand);
    printf("Enter license plate: ");
    scanf("%s", newCar->licensePlate);

    sElement* newElement = (sElement*)malloc(sizeof(sElement));
    if (newElement == NULL) {
        free(newCar); // Clean up the car allocation
        printf("Memory allocation failed.\n");
        return last;
    }

    newElement->car = newCar;
    newElement->prev = last;
    return newElement;
}

sElement* pop(sElement* last) {
    if (isEmpty(last)) {
        printf("Stack is empty. Cannot pop.\n");
        return last;
    }

    sElement* topElement = last;
    printf("Popped car:\n");
    printf("Brand: %s\n", topElement->car->brand);
    printf("License Plate: %s\n\n");

    last = topElement->prev;
    free(topElement->car);
    free(topElement);
    return last;
}

int isEmpty(sElement* last) {
    return (last == NULL) ? 1 : 0;
}

int countElements(sElement* last) {
    int count = 0;
    sElement* temp = last;
    while (temp != NULL) {
        count++;
        temp = temp->prev;
    }
    return count;
}
