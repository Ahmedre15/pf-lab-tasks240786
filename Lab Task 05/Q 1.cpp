#include <stdio.h>
int main() {
int age;
char hascitizenship;
printf("Enter your age: ");
scanf("%d", &age);
printf("Has Citizenship(write Y or y)");
scanf(" %c", &hascitizenship);
if (age >= 18 ) {
	if (hascitizenship=='y' || hascitizenship=='Y')
    printf("You are eligible to vote.\n");}
else {
printf("You are not eligible to vote.\n");
}
return 0;
}
