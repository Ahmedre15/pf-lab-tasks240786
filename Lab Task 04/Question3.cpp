#include<stdio.h>
int main(){
	float amount;
	float amountsaved;
	float newamount;
	printf("Enter the amount of Items");
	scanf("%f",&amount);
	if (amount <= 0) {
        printf("Invalid Input. Amount must be greater than 0.\n");
        return 1;
	}
	else if(amount<1500){
		newamount=(amount-(amount*0.07));
	} 
	else if(amount >= 1500 && amount < 3000){
		newamount=(amount -(amount*0.12));
	} 
	else if(amount<5000){
		newamount=(amount-(amount*0.22));
	} 
	else if(amount>5000){
		newamount=(amount-(amount*0.30));
	} 
	else{
		printf("Invalid Input");
	}
	amountsaved=amount-newamount;
	printf("\n original amount is %f",amount);
	printf("\n amount saved due to the discount is %f",amountsaved);
	printf("\n amount after applying the discount %f",newamount);
	return 0;
}
