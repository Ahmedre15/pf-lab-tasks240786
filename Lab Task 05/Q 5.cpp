#include <stdio.h>
int main() {
    int number;
    printf("Enter a number: ");
    scanf("%d", &number);
    if (number & 1) {
        printf("%d is Odd\n", number);
    } else {
        printf("%d is Even\n", number);
    }
    return 0;
}

