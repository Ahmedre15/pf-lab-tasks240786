#include <stdio.h>
int main() {
	int angle1,angle2,angle3;
	int sum=0;
	printf("Enter Angle 1\n");
	scanf(" %d",&angle1);
		printf("Enter Angle 2\n");
	scanf(" %d",&angle2);
		printf("Enter Angle 3\n");
	scanf(" %d",&angle3);
	if (angle1>0 && angle2>0 && angle3>0){
		sum= angle1+angle2+angle3 ;
		if(sum==180){
			printf("Triangle is Valid");
		}
		else{
			printf("Triangle is Invalid");
		}
	}
	else{
		printf("Invalid Angles");}
	
	return 0;
}
