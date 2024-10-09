#include<stdio.h>
int main(){
	int num,sum=0,a=0,b=1;
    printf("Enter Number\n");
    scanf("%d",&num);
	 if (num <= 1) {
        printf("Not a Prime Number\n");
        return 0;}
	for (int i=2; num>i ;i++)
	{	if(num%i ==0 )
		{printf("Not Prime Number\n");
		return 0;
		}}
printf("\nPrime Number");
  printf("\nFibonacci series till %d\n",num);
 printf("%d %d", a, b);
  do{
  	sum= b+a;
  	 a=b;
      b=sum;
      if(num>sum){
  	printf(" %d",sum);}
  }
  while(sum<num);
   return 0;
}
