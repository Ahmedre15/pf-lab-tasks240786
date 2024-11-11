#include <stdio.h>
int main() {
    int matrix[4][4];
    int temp;
    printf("Enter the elements of a 4x4 matrix (scores):\n");
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            printf("Element [%d][%d]: ", i, j);
            scanf("%d", &matrix[i][j]);}}
    for (int col = 0; col < 4; col++) {
        for (int i = 0; i < 3; i++) {     
            for (int j = i + 1; j < 4; j++) { 
                if (matrix[i][col] > matrix[j][col]) {
                    temp = matrix[i][col];
                    matrix[i][col] = matrix[j][col];
                    matrix[j][col] = temp; }}}}
    printf("\nMatrix with columns sorted in ascending order:\n");
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");}
    return 0;
}
