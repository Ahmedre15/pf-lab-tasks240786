#include <stdio.h>
int main()
{
    int i;
	int n;
    printf("Enter Number\n");
    scanf("%d", &n);
     if (n<1){
    	printf("Inavalid Input");}
    		else{
    printf("All even numbers from 1 to %d are: \n", n);
    i=1;
    while(i<=n)
    {
        if(i%2==0)
        {
            printf("%d\n", i);
        }

        i++;
    }}
 

    return 0;
}
