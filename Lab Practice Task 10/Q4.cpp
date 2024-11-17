#include <stdio.h>
#include <string.h>

struct Flight {
    char flightNumber[10], departureCity[50], arrivalCity[50], departureTime[20], arrivalTime[20];
    int availableSeats;
};

void bookSeat(struct Flight flights[], int flightCount, const char* flightNumber);
void displayFlights(struct Flight flights[], int flightCount, const char* departureCity, const char* arrivalCity);
void updateFlight(struct Flight flights[], int flightCount, const char* flightNumber);

int main() {
    struct Flight flights[100];
    int flightCount = 0, choice, status;
    char departureCity[50], arrivalCity[50], flightNumber[10];

    while (1) {
        printf("\n1. Book Seat\n2. Display Flights\n3. Update Flight\n4. Exit\nChoice: ");
        scanf("%d", &choice);
        getchar();  

        switch (choice) {
            case 1:
                printf("Enter flight number: ");
                fgets(flightNumber, sizeof(flightNumber), stdin);
                flightNumber[strcspn(flightNumber, "\n")] = 0;
                bookSeat(flights, flightCount, flightNumber);
                break;
            case 2:
                printf("Enter departure city: ");
                fgets(departureCity, sizeof(departureCity), stdin);
                departureCity[strcspn(departureCity, "\n")] = 0;
                printf("Enter arrival city: ");
                fgets(arrivalCity, sizeof(arrivalCity), stdin);
                arrivalCity[strcspn(arrivalCity, "\n")] = 0;
                displayFlights(flights, flightCount, departureCity, arrivalCity);
                break;
            case 3:
                printf("Enter flight number: ");
                fgets(flightNumber, sizeof(flightNumber), stdin);
                flightNumber[strcspn(flightNumber, "\n")] = 0;
                updateFlight(flights, flightCount, flightNumber);
                break;
            case 4: return 0;
            default: printf("Invalid choice!\n");
        }
    }
    return 0;
}
void bookSeat(struct Flight flights[], int flightCount, const char* flightNumber) {
    for (int i = 0; i < flightCount; i++) {
        if (strcmp(flights[i].flightNumber, flightNumber) == 0) {
            if (flights[i].availableSeats > 0) {
                flights[i].availableSeats--;
                printf("Seat booked! Remaining seats: %d\n", flights[i].availableSeats);
            } else {
                printf("No seats available.\n");
            }
            return;
        }
    }
    printf("Flight not found.\n");
}

void displayFlights(struct Flight flights[], int flightCount, const char* departureCity, const char* arrivalCity) {
    int found = 0;
    for (int i = 0; i < flightCount; i++) {
        if (strcmp(flights[i].departureCity, departureCity) == 0 && strcmp(flights[i].arrivalCity, arrivalCity) == 0) {
            printf("Flight %s: Departs %s at %s, Arrives %s at %s, Seats Available: %d\n", 
                   flights[i].flightNumber, flights[i].departureCity, flights[i].departureTime, 
                   flights[i].arrivalCity, flights[i].arrivalTime, flights[i].availableSeats);
            found = 1;
        }
    }
    if (!found) printf("No flights found.\n");
}

void updateFlight(struct Flight flights[], int flightCount, const char* flightNumber) {
    for (int i = 0; i < flightCount; i++) {
        if (strcmp(flights[i].flightNumber, flightNumber) == 0) {
            printf("Enter new departure time: ");
            fgets(flights[i].departureTime, sizeof(flights[i].departureTime), stdin);
            printf("Enter new arrival time: ");
            fgets(flights[i].arrivalTime, sizeof(flights[i].arrivalTime), stdin);
            printf("Enter new number of available seats: ");
            scanf("%d", &flights[i].availableSeats);
            getchar();  
            printf("Flight updated!\n");
            return;
        }
    }
    printf("Flight not found.\n");
}
