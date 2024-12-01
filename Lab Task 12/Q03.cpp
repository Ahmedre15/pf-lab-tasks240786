#include <stdio.h>
#include <stdlib.h>

#define INITIAL_CAPACITY 4

typedef struct {
    float *array;
    int size;
    int capacity;
} DynamicArray;

void initArray(DynamicArray *arr) {
    arr->array = (float *)malloc(INITIAL_CAPACITY * sizeof(float));
    arr->size = 0;
    arr->capacity = INITIAL_CAPACITY;
}

void resizeArray(DynamicArray *arr, int newCapacity) {
    arr->array = (float *)realloc(arr->array, newCapacity * sizeof(float));
    arr->capacity = newCapacity;
}

void addNumber(DynamicArray *arr, float number) {
    if (arr->size == arr->capacity) {
        resizeArray(arr, arr->capacity * 2);
    }
    arr->array[arr->size++] = number;
}

void displayArray(DynamicArray *arr) {
    printf("Array elements:\n");
    for (int i = 0; i < arr->size; i++) {
        printf("%f ", arr->array[i]);
    }
    printf("\n");
}

void removeLastNumber(DynamicArray *arr) {
    if (arr->size > 0) {
        arr->size--;
    } else {
        printf("Array is already empty.\n");
    }
}

void shrinkArray(DynamicArray *arr) {
    if (arr->size < arr->capacity / 2) {
        resizeArray(arr, arr->size);
    }
}

void freeArray(DynamicArray *arr) {
    free(arr->array);
    arr->array = NULL;
    arr->size = 0;
    arr->capacity = 0;
}

int main() {
    DynamicArray arr;
    initArray(&arr);

    int choice;
    float number;

    while (1) {
        printf("Menu:\n");
        printf("1. Add a new number\n");
        printf("2. Display all numbers\n");
        printf("3. Remove the last number\n");
        printf("4. Shrink the array\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter a number: ");
                scanf("%f", &number);
                addNumber(&arr, number);
                break;
            case 2:
                displayArray(&arr);
                break;
            case 3:
                removeLastNumber(&arr);
                break;
            case 4:
                shrinkArray(&arr);
                break;
            case 5:
                freeArray(&arr);
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
