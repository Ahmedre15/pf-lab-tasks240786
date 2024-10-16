#include<stdio.h>
int main(){
int numbers[12]; 
for(int i = 0; i<=11; i++){
printf("Enter Numbers %d: ",i+1);
scanf("%d", &numbers[i]); 
}
	printf("Input Array: {");
 for(int i = 0; i<=11; i++){
 		printf("%d",numbers[i]);
 		if(i<11){printf(",");
		 }}printf("}\n");
		 printf("Pair Sum Array: {");
int sum[6]; 
    for(int j = 0,i=0; j < 6; j++) {
        sum[j] = numbers[i] + numbers[i + 1];  
        printf("%d ",  sum[j]);
        i=i+2;
    if(j<5){printf(",");
		 }}printf("}\n");
    
    return 0;}