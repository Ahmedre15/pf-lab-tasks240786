#include <stdio.h>

int main() {
	int m1,m2,n1,n2;
	printf("Enter m:1 :");
	scanf("%d",&m1);
		printf("Enter n:1 :");
	scanf("%d",&n1);
    int matrices1[m1][n1];
    int i,j;
     printf("Enter the Data for Matrix:01\n");
    for(i=0;i<m1;i++){
    	for(j=0;j<n1;j++){
    		printf("Enter Element of Row %d,Column %d: ",i+1,j+1);
    		scanf("%d", &matrices1[i][j]);
		}  }
			printf("Enter m:2 :");
	scanf("%d",&m2);
		printf("Enter n:2 :");
	scanf("%d",&n2);
	    if (m1 != m2 || n1 != n2) {
        printf("Error: Matrices must have the same dimensions for addition.\n");
        return 1;
    }
	int matrices2[m2][n2];
	printf("Enter the Data for Matrix:02\n");
	   for(i=0;i<m2;i++){
    	for(j=0;j<n2;j++){
    		printf("Enter Element of Row %d,Column %d: ",i+1,j+1);
    		   scanf("%d", &matrices2[i][j]);
		}
	}
	printf("Sum of Matrices:\n");
	for(i=0;i<m1;i++){
		for(j=0;j<n1;j++){
			printf("%d ",matrices1[i][j]+matrices2[i][j]);
		}printf("\n");
	}
    return 0;
}