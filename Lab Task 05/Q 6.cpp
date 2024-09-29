#include<iostream>
int main(){
	int number , sum;
	printf("ENTER A NUMBER (0 TO 15)\n");
	scanf("%d",&number);	
	if((number & 1) == 1){
		sum = sum + 1;
	}
	if((number & 2) == 2){
		sum = sum + 1;
	}
		if((number & 4) == 4){
		sum = sum + 1;
	}
		if((number & 8) == 8){
		sum = sum + 1;
	}
	printf("\n No of Ones = %d",sum);
	return 0 ;
}
