#include<stdio.h>
int main(){
int sum = 0;
int i;
int numbers[15]; 
for(i = 0; i<=14; i++){
printf("Enter Numbers %d: ",i+1);
scanf("%d", &numbers[i]); 
}
for(i = 0; i<=14; i++)
sum = sum + numbers[i];
printf("Sum is %d\n", sum);
return 0;
}
