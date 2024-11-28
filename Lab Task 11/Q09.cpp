#include <stdio.h>
#include <string.h>

#define MAX_DEPTS 5
#define MAX_COURSES 5
#define MAX_STUDENTS 5

struct Student {
    int id, age;
    char name[50];
    float grade;
};

struct Course {
    int id;
    char name[100];
    struct Student students[MAX_STUDENTS];
    int studentCount;
};

struct Department {
    int id;
    char name[100];
    struct Course courses[MAX_COURSES];
    int courseCount;
};

struct University {
    struct Department departments[MAX_DEPTS];
    int deptCount;
};

void addStudent(struct Course *course) {
    struct Student s;
    if (course->studentCount < MAX_STUDENTS) {
        printf("Enter Student ID: ");
        scanf("%d", &s.id);
        printf("Enter Student Name: ");
        scanf(" %[^\n]%*c", s.name); // To read a line with spaces
        printf("Enter Student Age: ");
        scanf("%d", &s.age);
        printf("Enter Student Grade: ");
        scanf("%f", &s.grade);
        course->students[course->studentCount++] = s;
    }
}

void addCourse(struct Department *dept) {
    struct Course c;
    if (dept->courseCount < MAX_COURSES) {
        printf("Enter Course ID: ");
        scanf("%d", &c.id);
        printf("Enter Course Name: ");
        scanf(" %[^\n]%*c", c.name); // To read a line with spaces
        c.studentCount = 0;
        dept->courses[dept->courseCount++] = c;
    }
}

void addDepartment(struct University *uni) {
    if (uni->deptCount < MAX_DEPTS) {
        struct Department d;
        printf("Enter Department ID: ");
        scanf("%d", &d.id);
        printf("Enter Department Name: ");
        scanf(" %[^\n]%*c", d.name); // To read a line with spaces
        d.courseCount = 0;
        uni->departments[uni->deptCount++] = d;
    }
}

void displayUniversity(struct University *uni) {
    for (int i = 0; i < uni->deptCount; i++) {
        printf("\nDept: %s\n", uni->departments[i].name);
        for (int j = 0; j < uni->departments[i].courseCount; j++) {
            printf("  Course: %s\n", uni->departments[i].courses[j].name);
            for (int k = 0; k < uni->departments[i].courses[j].studentCount; k++) {
                struct Student s = uni->departments[i].courses[j].students[k];
                printf("    Student: %s, ID: %d, Age: %d, Grade: %.2f\n", s.name, s.id, s.age, s.grade);
            }
        }
    }
}

int findDepartmentIndex(struct University *uni, int deptId) {
    for (int i = 0; i < uni->deptCount; i++) {
        if (uni->departments[i].id == deptId) {
            return i;
        }
    }
    return -1; // Department not found
}

int findCourseIndex(struct Department *dept, int courseId) {
    for (int i = 0; i < dept->courseCount; i++) {
        if (dept->courses[i].id == courseId) {
            return i;
        }
    }
    return -1; // Course not found
}

int main() {
    struct University uni = {0};
    int choice;
    
    while (1) {
        printf("\n1. Add Department\n2. Add Course\n3. Add Student\n4. Display Info\n5. Exit\nChoice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1: addDepartment(&uni); break;
            case 2: {
                int deptId;
                printf("Enter Department ID: ");
                scanf("%d", &deptId);
                int deptIndex = findDepartmentIndex(&uni, deptId);
                if (deptIndex != -1) {
                    addCourse(&uni.departments[deptIndex]);
                } else {
                    printf("Invalid Department ID.\n");
                }
                break;
            }
            case 3: {
                int deptId, courseId;
                printf("Enter Department ID and Course ID: ");
                scanf("%d %d", &deptId, &courseId);
                int deptIndex = findDepartmentIndex(&uni, deptId);
                if (deptIndex != -1) {
                    int courseIndex = findCourseIndex(&uni.departments[deptIndex], courseId);
                    if (courseIndex != -1) {
                        addStudent(&uni.departments[deptIndex].courses[courseIndex]);
                    } else {
                        printf("Invalid Course ID.\n");
                    }
                } else {
                    printf("Invalid Department ID.\n");
                }
                break;
            }
            case 4: displayUniversity(&uni); break;
            case 5: return 0;
            default: printf("Invalid choice.\n");
        }
    }
}
