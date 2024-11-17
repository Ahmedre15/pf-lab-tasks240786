#include<stdio.h>
void func(int l, int i){
	if(l>0 && i>0){
	
	int rem=l/i;
	printf("%d maximum peices of length %d units is possible for this length\n",rem,i);
	l=l%i;
	func(l,i-1);}
	else{return;
	}
}
int main(){
	int length;
	printf("Enter length of rope : ");
	scanf("%d",&length);
	func(length,3);
	
}