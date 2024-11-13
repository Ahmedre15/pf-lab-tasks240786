#include<stdio.h>
mot(int N){ 
int i,j;
int a = N;
	for(i=N;i>=1;i--){
		for(j=1;j<=i;j++){
			printf(" . ");
		}
			for(j=N;j>=i;j--){
			printf("o");}printf("\n");}
		for(i=2;i<=N;i++){
		for(j=1;j<=i;j++){
			printf(" . ");}
		for(j=a;j>=2;j--){
			printf("o");}
		a--;
		printf("\n");}}
int main(){
		int Number;
	printf("Enter Number : ");
	scanf("%d",&Number);
	mot(Number);
	return 0;
}