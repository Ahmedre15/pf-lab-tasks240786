#include <stdio.h>
#include <stdlib.h>

void insert(int **arr, int *size, int *capacity, int pos, int value) {
    if (*size >= *capacity) {
        *capacity *= 2;
        *arr = (int *)realloc(*arr, *capacity * sizeof(int));
    }
    for (int i = *size; i > pos; i--) {
        (*arr)[i] = (*arr)[i - 1];
    }
    (*arr)[pos] = value;
    (*size)++;
}

void delete(int *arr, int *size, int pos) {
    if (*size == 0) {
        printf("Array is empty.\n");
        return;
    }
    for (int i = pos; i < *size - 1; i++) {
        arr[i] = arr[i + 1];
    }
    (*size)--;
}

void display(int *arr, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int T;
    printf("Enter the number of test cases: ");
    scanf("%d", &T);

    while (T--) {
        int N, capacity, size, pos, value, option;
        printf("Enter the number of elements: ");
        scanf("%d", &N);

        capacity = N > 4 ? N : 4; 
        size = N;
        int *arr = (int *)malloc(capacity * sizeof(int));

        printf("Enter the elements:\n");
        for (int i = 0; i < N; i++) {
            scanf("%d", &arr[i]);
        }

        while (1) {
            printf("Choose an option: 1. Insert 2. Delete 3. Display 4. Exit\n");
            scanf("%d", &option);

            if (option == 1) {
                printf("Enter position and value to insert: ");
                scanf("%d %d", &pos, &value);
                if (pos >= 0 && pos <= size) {
                    insert(&arr, &size, &capacity, pos, value);
                } else {
                    printf("Invalid position.\n");
                }
            } else if (option == 2) {
                printf("Enter position to delete: ");
                scanf("%d", &pos);
                if (pos >= 0 && pos < size) {
                    delete(arr, &size, pos);
                } else {
                    printf("Invalid position.\n");
                }
            } else if (option == 3) {
                display(arr, size);
            } else if (option == 4) {
                break;
            } else {
                printf("Invalid option. Please choose again.\n");
            }
        }

        free(arr);
    }

    return 0;
}
