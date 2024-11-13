#include<stdio.h>
int main(){
    int washers,nuts,bolts;
    printf("Number of bolts :     ");
    scanf("%d",&bolts);
    printf("Number of nuts:       ");
    scanf("%d",&nuts);
    printf("Number of washers :   ");
    scanf("%d",&washers);
    	if(nuts<bolts || (2*bolts)>washers){
    	printf("Check the order:   ");
		if(nuts<bolts){
			printf("too few nuts");
			if((2*bolts)>washers){
			printf(" and ");}}	
		if((2*bolts)>washers){
			printf("too few washers");
		}}
		else{printf("Order is ok");
		}
		int totalcost=(5*bolts)+(3*nuts)+(1*washers);
		printf("\nTotal cost : %d",totalcost);
		return 0;
		}