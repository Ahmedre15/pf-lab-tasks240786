#include<stdio.h>
int main()
{
	int time;
	printf("Enter Time(24-hour Format)\n");
	scanf(" \n%d", &time);
	if(time>0 && time<5){
		printf("Good Night");
	}
	else if(time>=6 && time<12){
		printf("Good Morning");
	}
	else if(time>=12 && time<18){
		printf("Good Afternoon");
	}
	else if(time>=18 && time<24){
		printf("Good Evening");
	}
	else{
		printf("Invalid time");
	}
	
	
	return 0;
}
