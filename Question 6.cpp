 #include<stdio.h>
int main()
{
	int num1,num2;
	printf("Enter Two Numbers\n");
	scanf("%d%d",&num1,&num2);
	if(num1>num2){
		if (num1>100){
			printf("First number is significantly larger");
		}
		else{
			printf("First number is larger");
		}
	}
	
	else if(num2>num1){
		if (num1<0)
		printf("First number is negative and smaller");
		else
		printf("First Number is smaller");
	}
	
	else{
		printf("Both numbers are equal");
	}

		
	return 0;
	
}
