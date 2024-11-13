#include<stdio.h>
#include<string.h>
int main(){
	char names[5][20]={"Alice", "Harry", "Charlie", "Diana", "Eve"};
	char search[20];
	int found=0;
	printf("Enter a name to search : ");
    scanf("%s",search);
	for(int i=0;i<5;i++){
	if(strcmp(names[i], search) == 0){
	found=1;
	break;
}} 
	if(found==1){printf("Found");
	}
	else{printf("Not Found");
}return 0;
}