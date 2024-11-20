#include<stdio.h>
	int sum=0;
void func(int N){
	
	int rem;
	if(N>0){
	rem=N%10;
	sum=sum+rem;
	N=N/10;
	func(N);}
	else{
	printf("Sum = %d",sum);
	return;
	}
}
int main(){
	int Number;
	printf("Enter Number : ");
	scanf("%d",&Number);
	func(Number);
}