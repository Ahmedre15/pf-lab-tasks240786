#include <stdio.h>
int main() {
	int factorial=1;
    int n, i;
    printf("Enter Number: ");
    scanf("%d", &n);
    if (n < 0)
        printf("Factorial of negative number does not exist");
    else {
        for (i = 1; i <= n; ++i) {
            factorial *= i;
        }
        printf("Factorial :%d",factorial);
    }

    return 0;
}

