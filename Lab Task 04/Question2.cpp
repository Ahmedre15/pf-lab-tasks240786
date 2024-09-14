#include<stdio.h>
int main() {
	double units;
	double bill;
	double surcharge;
	printf("Enter Total Number of Units:");
	scanf("%lf",&units);
	if(units<=30){
		bill=units*0.60;
	}
	else if(units<=110){
		bill=(30*0.60)+((units-30)*0.85);
	}
	else if(units<=210){
		bill=(30*0.60)+(80*0.85)+((units-110)*1.30);
	}
	else{
		bill=(30*0.60)+(80*0.85)+(110*1.30)+((units-210)*1.60);
	}
   surcharge=bill*0.15;
   bill+=surcharge;
   printf("Electricity bill is Rs %lf",bill);
	
	return 0;
}

