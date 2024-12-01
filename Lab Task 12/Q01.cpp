#include <stdio.h>
#include <stdlib.h>

int main() {
    int numStudents, numGrades;
    float **grades;

    printf("Enter the number of students: ");
    scanf("%d", &numStudents);

    grades = (float **)malloc(numStudents * sizeof(float *));

    for (int i = 0; i < numStudents; i++) {
        printf("Enter the number of grades for student %d: ", i + 1);
        scanf("%d", &numGrades);

        grades[i] = (float *)malloc(numGrades * sizeof(float));

        printf("Enter the grades for student %d:\n", i + 1);
        for (int j = 0; j < numGrades; j++) {
            printf("Grade %d: ", j + 1);
            scanf("%f", &grades[i][j]);
        }
    }

    printf("\nGrades entered:\n");
    for (int i = 0; i < numStudents; i++) {
        printf("Grades for student %d: ", i + 1);
        for (int j = 0; grades[i][j] != '\0'; j++) {
            printf("%.2f ", grades[i][j]);
        }
        printf("\n");
    }

    for (int i = 0; i < numStudents; i++) {
        free(grades[i]);
    }
    free(grades);

    return 0;
}
