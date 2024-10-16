#include<stdio.h>
int main(){
int min,max;
int i;
int numbers[30]; 
for(i = 0; i<=29; i++){
printf("Enter Numbers %d: ",i+1);
scanf("%d", &numbers[i]); 
}
max=numbers[0];
min=numbers[0];
  for (i = 1; i < 30; i++)
    {
        if (numbers[i] > max)
        {
            max = numbers[i];
        }

        if (numbers[i] < min)
        {
            min = numbers[i];
        }
    }
      printf("\nMaximum Number is : %d\n", max);
    printf("Minimum Number is : %d\n\n", min);
return 0;
}