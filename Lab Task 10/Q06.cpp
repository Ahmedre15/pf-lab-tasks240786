#include<stdio.h>
#include<string.h>
void f1(char a[50], int n)
{
	if(n<0)
	{
		return ;
	}
	else
	{
		printf("%c",a[n]);
		f1(a,n-1);
	}
}
int main()
{
	char sentence[50];
	printf("Enter a sentence: ");
    fgets(sentence,50,stdin);
int	size=strlen(sentence);
	f1(sentence,size);
}