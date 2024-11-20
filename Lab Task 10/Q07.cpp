#include <stdio.h>
void bubbleSort(int arr[], int n){
    if (n == 1) return;
    for (int i = 0; i < n - 1; i++) {
        if (arr[i] > arr[i + 1]) {
            int temp = arr[i];
            arr[i] = arr[i + 1];
            arr[i + 1] = temp;}}
    bubbleSort(arr, n - 1);}
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }printf("\n");}
int main() {
    int n;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);}
    printf("\nOriginal Array: \n");
    printArray(arr, n);
    bubbleSort(arr, n);
    printf("\nSorted Array: \n");
    printArray(arr, n);
    return 0;}
