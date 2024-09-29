#include <stdio.h>
int main() {
int percentage;
printf("Enter your Percentage \n");
scanf("%d", &percentage);
percentage>=90 ? printf("A") : percentage>=80 ? printf("B") : percentage>=70?printf("C") :percentage>=60 ?printf("D") : printf("F") ;

return 0;
}
