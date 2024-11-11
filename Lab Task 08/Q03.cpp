#include <stdio.h>
int main(){
	int n;
	printf("Enter N : ");
	scanf("%d",&n);
	for(int i=n;i>=1;i--){
			for(int space=1;space<=n-i;space++){
				printf(" ");
			}
		for (int j = i; j >= 1; j--) {
            printf("%d ", j);
        }printf("\n");}
		for(int i=2;i<=n;i++){
			for(int space=1;space<=n-i;space++){
				printf(" ");
			}
		for (int j = i; j >= 1; j--) {
            printf("%d ", j);
        }printf("\n");
		}
}
