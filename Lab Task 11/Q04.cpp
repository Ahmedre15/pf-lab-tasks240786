#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EMPLOYEES 100

typedef struct {
    char name[50];
    char dob[15];
    int empID;
    char department[30];
    float salary;
} Employee;

Employee employees[MAX_EMPLOYEES];
int employeeCount = 0;

void addEmployee();
void deleteEmployee();
void displayEmployees();
void displayMenu();

int main() {
    int choice;
    while (1) {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                addEmployee();
                break;
            case 2:
                deleteEmployee();
                break;
            case 3:
                displayEmployees();
                break;
            case 4:
                printf("Exiting program. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}

void displayMenu() {
    printf("\n--- Employee Management System ---\n");
    printf("1. Add an Employee\n");
    printf("2. Delete an Employee\n");
    printf("3. Display All Employees\n");
    printf("4. Exit\n");
}

void addEmployee() {
    if (employeeCount >= MAX_EMPLOYEES) {
        printf("Error: Maximum employee limit reached.\n");
        return;
    }
    Employee emp;
    printf("Enter Name: ");
    scanf(" %[^\n]s", emp.name);
    printf("Enter Date of Birth (DD/MM/YYYY): ");
    scanf(" %[^\n]s", emp.dob);
    printf("Enter Employee ID: ");
    scanf("%d", &emp.empID);
    printf("Enter Department: ");
    scanf(" %[^\n]s", emp.department);
    printf("Enter Salary: ");
    scanf("%f", &emp.salary);

    employees[employeeCount++] = emp;
    printf("Employee added successfully!\n");
}

void deleteEmployee() {
    if (employeeCount == 0) {
        printf("No employees to delete.\n");
        return;
    }
    int empID, i, found = 0;
    printf("Enter Employee ID to delete: ");
    scanf("%d", &empID);
    for (i = 0; i < employeeCount; i++) {
        if (employees[i].empID == empID) {
            found = 1;
            break;
        }
    }
    if (found) {
        for (int j = i; j < employeeCount - 1; j++) {
            employees[j] = employees[j + 1];
        }
        employeeCount--;
        printf("Employee with ID %d deleted successfully!\n", empID);
    } else {
        printf("Employee with ID %d not found.\n", empID);
    }
}

void displayEmployees() {
    if (employeeCount == 0) {
        printf("No employees to display.\n");
        return;
    }
    printf("\n--- Employee List ---\n");
    for (int i = 0; i < employeeCount; i++) {
        printf("\nEmployee %d:\n", i + 1);
        printf("Name: %s\n", employees[i].name);
        printf("Date of Birth: %s\n", employees[i].dob);
        printf("Employee ID: %d\n", employees[i].empID);
        printf("Department: %s\n", employees[i].department);
        printf("Salary: %.2f\n", employees[i].salary);
    }
}
