#include<stdio.h>
void percent(int n, int i){
	if(i<101){
	float get=n/100.0;
	get=get*i;
	printf("%d Percent = %.2f\n",i,get);
	i++;
	percent(n,i);}
	else{return;
	}
	
}
int main(){
int number;
printf("Enter a value to split in percentage : ");	
scanf("%d",&number);
percent(number,1);	
}