 
#include<stdio.h>
int main(){
	printf("A while loop is often more suitable for user input when the number of iterations is unknown, as it allows for continuous input until a specific condition is met\n");
	int num;
	int sum=0;
		while (1) {
	printf("Enter Number\n");
	scanf("%d",&num);
	if(num==0){break;
	}
		sum=sum+num;
	}
	
	printf("Total Sum is %d",sum);
	
}
