#include<stdio.h>
 int main(){
int i;
int numbers[6]; 
for(i = 0; i<=6; i++){
printf("Enter Numbers %d: ",i+1);
scanf("%d", &numbers[i]); 
}
 	printf("Before: {");
 for(i = 0; i<=6; i++){
 		printf("%d",numbers[i]);
 		if(i<6){printf(",");
		 }
	 }printf("}\n");
    printf("After: {");
    for(i = 1; i <= 6; i++) { 
        printf("%d", numbers[i]);
        printf(",");
    }
    printf("%d}\n", numbers[0]);
	 return 0;}
 