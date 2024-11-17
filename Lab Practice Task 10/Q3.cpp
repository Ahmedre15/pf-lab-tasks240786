#include <stdio.h>
#include <string.h>
struct Book {
    char title[100], author[100], ISBN[20];
    int publicationYear, isAvailable;
};

void addBook(struct Book library[], int *bookCount);
void searchBook(struct Book library[], int bookCount, const char* query);
void updateAvailability(struct Book library[], int bookCount, const char* isbn, int status);

int main() {
    struct Book library[100];
    int bookCount = 0, choice, status;
    char query[100], isbn[20];

    while (1) {
        printf("\nLibrary System\n1. Add Book\n2. Search Book\n3. Update Availability\n4. Exit\nChoice: ");
        scanf("%d", &choice);
        getchar();  

        switch (choice) {
            case 1: addBook(library, &bookCount); break;
            case 2: 
                printf("Enter title/author: ");
                fgets(query, sizeof(query), stdin);
                query[strcspn(query, "\n")] = 0;
                searchBook(library, bookCount, query); 
                break;
            case 3: 
                printf("Enter ISBN: ");
                fgets(isbn, sizeof(isbn), stdin);
                isbn[strcspn(isbn, "\n")] = 0;
                printf("Enter status (1=available, 0=checked out): ");
                scanf("%d", &status);
                getchar();
                updateAvailability(library, bookCount, isbn, status); 
                break;
            case 4: return 0;
            default: printf("Invalid choice! Try again.\n");
        }
    }
    return 0;
}

void addBook(struct Book library[], int *bookCount) {
    struct Book newBook;
    printf("Enter title: ");
    fgets(newBook.title, sizeof(newBook.title), stdin);
    newBook.title[strcspn(newBook.title, "\n")] = 0;
    printf("Enter author: ");
    fgets(newBook.author, sizeof(newBook.author), stdin);
    newBook.author[strcspn(newBook.author, "\n")] = 0;
    printf("Enter ISBN: ");
    fgets(newBook.ISBN, sizeof(newBook.ISBN), stdin);
    newBook.ISBN[strcspn(newBook.ISBN, "\n")] = 0;
    printf("Enter publication year: ");
    scanf("%d", &newBook.publicationYear);
    newBook.isAvailable = 1; 
    library[*bookCount] = newBook;
    (*bookCount)++;
    printf("Book added successfully!\n");
}

void searchBook(struct Book library[], int bookCount, const char* query) {
    int found = 0;
    for (int i = 0; i < bookCount; i++) {
        if (strstr(library[i].title, query) || strstr(library[i].author, query)) {
            printf("Found: %s by %s, ISBN: %s, Year: %d, %s\n", 
                   library[i].title, library[i].author, library[i].ISBN, 
                   library[i].publicationYear, library[i].isAvailable ? "Available" : "Checked Out");
            found = 1;
        }
    }
    if (!found) printf("No books found.\n");
}

void updateAvailability(struct Book library[], int bookCount, const char* isbn, int status) {
    int found = 0;
    for (int i = 0; i < bookCount; i++) {
        if (strcmp(library[i].ISBN, isbn) == 0) {
            library[i].isAvailable = status;
            printf("Availability updated.\n");
            found = 1;
            break;
        }
    }
    if (!found) printf("Book not found.\n");
}
