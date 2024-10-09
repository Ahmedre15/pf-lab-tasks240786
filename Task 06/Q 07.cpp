#include <stdio.h>
int main() {
    int a,c = 0, num;
    printf("Enter Number\n");
    scanf("%d", &num);
    int b = num; 
	while (b>0){
		a=b%10;
		b=b/10;
		a=a*a*a;
		c=c+a;
	}
	if(c==num){
		printf("Armstrong");
	}
	else{	printf("Not Armstrong");
	}
	return 0;
}
