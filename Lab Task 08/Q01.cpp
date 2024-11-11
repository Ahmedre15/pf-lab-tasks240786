#include <stdio.h>
int main(){
    int rowsum = 0,columnsum = 0;
    int arr[3][3];
    int i;
    for (int i = 0; i < 3; i++){
        printf("Enter score for Particpant %d\n", i + 1);
        for (int j = 0; j < 3; j++) {
            printf("Enter Score %d ", j + 1);
            scanf("%d", &arr[i][j]); }}
    for (i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++)
        {
            printf("%d ", arr[i][j]);}
        printf("\n");}
    for (i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            rowsum = rowsum + arr[i][j];
           columnsum = columnsum + arr[j][i];}
        printf("Sum of row %d is %d\n", i + 1, rowsum);
        rowsum = 0;
        printf("Sum of Column %d is %d\n", i + 1, columnsum);
        columnsum = 0; } return 0;}

