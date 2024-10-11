#include<stdio.h>
int main(){

int i;
int numbers[20]; 
for(i = 0; i<=19; i++){
printf("Enter Numbers %d: ",i+1);
scanf("%d", &numbers[i]); 
}
for(int i=19;i>=0;i--){
	printf("%d ",numbers[i]);
}
return 0;
}
