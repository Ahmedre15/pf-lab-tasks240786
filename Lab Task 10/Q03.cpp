#include <stdio.h>
#include <string.h>
struct Car {
    char make[50];
    char model[50];
    int year;
    float price;
    int mileage;
};
void addCar(struct Car cars[], int *carcount);
void displayCars(struct Car cars[], int carcount);
void searchCar(struct Car cars[], int carcount);
int main() {
    struct Car cars[100];
    int carcount = 0;  
    int choice;
    do {
        printf("\nCar Dealership Management System\n");
        printf("1. Add a New Car\n");
        printf("2. Display Cars\n");
        printf("3. Search Cars by Make or Model\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addCar(cars, &carcount);
                break;
            case 2:
                displayCars(cars, carcount);
                break;
            case 3:
                searchCar(cars, carcount);
                break;
            case 4:
                printf("Exiting program\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 4);

    return 0;
}
void addCar(struct Car cars[], int *carcount) {
    printf("\nEnter details for the new car:\n");

    printf("Make: ");
    scanf("%s", cars[*carcount].make);

    printf("Model: ");
    scanf("%s", cars[*carcount].model);

    printf("Year: ");
    scanf("%d", &cars[*carcount].year);

    printf("Price: ");
    scanf("%f", &cars[*carcount].price);

    printf("Mileage: ");
    scanf("%d", &cars[*carcount].mileage);

    (*carcount)++;
    printf("Car added successfully!\n");
}
void displayCars(struct Car cars[], int carcount) {
    if (carcount == 0) {
        printf("\nNo cars available in the dealership.\n");
        return;
    }
    printf("\nList of Available Cars:\n");
    for (int i = 0; i < carcount; i++) {
        printf("\nCar %d:\n", i + 1);
        printf("Make: %s\n", cars[i].make);
        printf("Model: %s\n", cars[i].model);
        printf("Year: %d\n", cars[i].year);
        printf("Price: $%.2f\n", cars[i].price);
        printf("Mileage: %d miles\n", cars[i].mileage);
    }
}
void searchCar(struct Car cars[], int carcount) {
    char query[50];
    int found = 0;

    printf("\nEnter make or model to search: ");
    scanf("%s", query);

    printf("\nSearch Results:\n");
    for (int i = 0; i < carcount; i++) {
        if (strcasecmp(cars[i].make, query) == 0 || strcasecmp(cars[i].model, query) == 0) {
            printf("\nCar %d:\n", i + 1);
            printf("Make: %s\n", cars[i].make);
            printf("Model: %s\n", cars[i].model);
            printf("Year: %d\n", cars[i].year);
            printf("Price: $%.2f\n", cars[i].price);
            printf("Mileage: %d miles\n", cars[i].mileage);
            found = 1;
        }
    }
    if (!found) {
        printf("No cars found matching your query.\n");
    }
}
