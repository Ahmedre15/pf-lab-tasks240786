#include<stdio.h>
 int main(){
 	int integer;
 	int i;
 	int array[7]={1,2,3,5,6,7,8};
 	printf("Array: {");
 for(i = 0; i<=6; i++){
 		printf("%d",array[i]);
 		if(i<6){printf(",");
		 }
	 }printf("}\n");
	 printf("Enter Integer to Search: ");
	 scanf("%d",&integer);
	for(i = 0; i<=6; i++){
 		if(array[i]==integer){printf("%d found at Index %d",integer,i+1);break;
		 }
		 }
    if(i>6){printf("Not Found");}
		 
 	return 0;}
 