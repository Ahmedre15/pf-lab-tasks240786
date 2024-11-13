#include<stdio.h>
#include<string.h>
int main(){
	int i=0;
	char username1[20]="admin";
	char password1[20]="1234";
	char username[20];
		char password[20];
printf("Enter Username\n");
	scanf("%s",username);
	printf("Enter Password\n");
	scanf("%s",password);
   
    if (strcmp(username1, username) ==0 && strcmp(password1, password)==0){
    	printf("Access Granted");}
    	 else{
	printf("Access Denied\n");}
    	return 0;
    	}