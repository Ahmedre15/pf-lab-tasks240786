#include <stdio.h>
struct Employee {
    int employeeID;
    char name[50];
    char department[50];
    float salary;};
int main() {
    int numEmployees;
    printf("Enter the number of employees: ");
    scanf("%d", &numEmployees);
    struct Employee employees[numEmployees];
    for (int i = 0; i < numEmployees; i++) {
        printf("\nEnter Employee %d details:\n", i + 1);
        printf("Employee ID: ");
        scanf("%d", &employees[i].employeeID);
        printf("Name: ");
        getchar();  
        fgets(employees[i].name, sizeof(employees[i].name), stdin);
        printf("Department: ");
        fgets(employees[i].department, sizeof(employees[i].department), stdin);
        printf("Salary: ");
        scanf("%f", &employees[i].salary);}
    printf("\n--- Employee Details ---\n");
    for (int i = 0; i < numEmployees; i++) {
        printf("\nEmployee ID: %d\n", employees[i].employeeID);
        printf("Name: %s", employees[i].name);
        printf("Department: %s", employees[i].department);
        printf("Salary: %.2f\n", employees[i].salary);}
    return 0;}
