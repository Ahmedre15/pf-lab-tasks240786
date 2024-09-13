#include <stdio.h>
int main()
    { 
    int score;
    printf(" Enter your Score");
    scanf("\n %d", &score);
    if(score<0 || score>100){
    	printf("Wrong Entry");
	}
    else if(score>=90){
    	printf("\nGrade A");
	}
	 else if(score>=80){
    	printf("\nGrade B");
	}
	 else if(score>=70){
    	printf("\nGrade C");
	}
	 else if(score>=60){
    	printf(" \nGrade D");
	}
	 else {
    	printf("\n Grade F");
	}
    

	return 0;
 }
