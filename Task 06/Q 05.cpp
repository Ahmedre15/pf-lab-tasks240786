#include<stdio.h>
int main() {
    int num;
    printf("Enter Number\n");
    scanf("%d",&num);
	 if (num <= 1) {
        printf("Not a Prime Number\n");
        return 0;
    }

	for (int i=2; num>i ;i++)
	{
		if(num%i ==0 )
		{printf("Not Prime Number\n");
		return 0;
		}
		}
printf("\nPrime Number");
	return 0;
}
