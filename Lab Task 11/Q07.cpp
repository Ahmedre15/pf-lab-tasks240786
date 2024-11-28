#include <stdio.h>
#include <string.h>
struct Course {
    int courseID;
    char courseName[50];
    char instructorName[50];
    int credits;
};
struct Department {
    char departmentName[50];
    struct Course courses[10]; 
    int numCourses; 
};
struct University {
    struct Department departments[5];
    int numDepartments;  
};
void addDepartment(struct University* uni) {
    if (uni->numDepartments >= 5) {
        printf("Cannot add more departments, limit reached!\n");
        return;
    }
    struct Department newDept;
    printf("Enter Department Name: ");
    scanf(" %[^\n]", newDept.departmentName);
    newDept.numCourses = 0;  // Initialize number of courses to 0

    uni->departments[uni->numDepartments++] = newDept;
    printf("Department added successfully!\n");
}
void addCourse(struct University* uni) {
    int deptIndex;
    printf("Enter department index (0-%d): ", uni->numDepartments - 1);
    scanf("%d", &deptIndex);
    if (deptIndex < 0 || deptIndex >= uni->numDepartments) {
        printf("Invalid department index!\n");
        return;
    }

    if (uni->departments[deptIndex].numCourses >= 10) {
        printf("Cannot add more courses, limit reached!\n");
        return;
    }

    struct Course newCourse;
    printf("Enter Course ID: ");
    scanf("%d", &newCourse.courseID);
    printf("Enter Course Name: ");
    scanf(" %[^\n]", newCourse.courseName);
    printf("Enter Instructor Name: ");
    scanf(" %[^\n]", newCourse.instructorName);
    printf("Enter Credits: ");
    scanf("%d", &newCourse.credits);

    uni->departments[deptIndex].courses[uni->departments[deptIndex].numCourses++] = newCourse;
    printf("Course added successfully!\n");
}
void displayDetails(struct University* uni) {
    for (int i = 0; i < uni->numDepartments; i++) {
        printf("\nDepartment: %s\n", uni->departments[i].departmentName);
        printf("Courses:\n");
        for (int j = 0; j < uni->departments[i].numCourses; j++) {
            printf("\tCourse ID: %d\n", uni->departments[i].courses[j].courseID);
            printf("\tCourse Name: %s\n", uni->departments[i].courses[j].courseName);
            printf("\tInstructor: %s\n", uni->departments[i].courses[j].instructorName);
            printf("\tCredits: %d\n", uni->departments[i].courses[j].credits);
        }
    }
  }
void calculateTotalCredits(struct University* uni) {
    int deptIndex;
    printf("Enter department index (0-%d): ", uni->numDepartments - 1);
    scanf("%d", &deptIndex);

    if (deptIndex < 0 || deptIndex >= uni->numDepartments) {
        printf("Invalid department index!\n");
        return;
    }

    int totalCredits = 0;
    for (int i = 0; i < uni->departments[deptIndex].numCourses; i++) {
        totalCredits += uni->departments[deptIndex].courses[i].credits;
    }
    printf("Total credits for department %s: %d\n", uni->departments[deptIndex].departmentName, totalCredits);
  }

int main() {
    struct University uni = { .numDepartments = 0 };  

    int choice;
    while (1) {
        printf("\n--- University Course Enrollment System ---\n");
        printf("1. Add a Department\n");
        printf("2. Add a Course\n");
        printf("3. Display All Details\n");
        printf("4. Calculate Total Credits for a Department\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addDepartment(&uni);
                break;
            case 2:
                addCourse(&uni);
                break;
            case 3:
                displayDetails(&uni);
                break;
            case 4:
                calculateTotalCredits(&uni);
                break;
            case 5:
                printf("Exiting program...\n");
                return 0;
            default:
                printf("Invalid choice, please try again.\n");
        }
    }
    return 0;
}
