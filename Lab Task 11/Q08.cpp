#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILENAME "books.txt"

struct Book {
    int bookID;
    char title[100];
    char author[100];
    int quantity;
    float price;
};

void addBook() {
    FILE *file = fopen(FILENAME, "a");
    if (!file) { printf("Error opening file.\n"); return; }

    struct Book book;
    printf("Enter Book ID: ");
    scanf("%d", &book.bookID);
    getchar();  // Consume newline

    printf("Enter Title: ");
    fgets(book.title, 100, stdin);
    book.title[strcspn(book.title, "\n")] = '\0';

    printf("Enter Author: ");
    fgets(book.author, 100, stdin);
    book.author[strcspn(book.author, "\n")] = '\0';

    printf("Enter Quantity: ");
    scanf("%d", &book.quantity);
    if (book.quantity < 0) book.quantity = 0;

    printf("Enter Price: ");
    scanf("%f", &book.price);
    if (book.price < 0) book.price = 0;

    fwrite(&book, sizeof(book), 1, file);
    fclose(file);
    printf("Book added!\n");
}

void viewBooks() {
    FILE *file = fopen(FILENAME, "r");
    if (!file) { printf("Error opening file.\n"); return; }

    struct Book book;
    while (fread(&book, sizeof(book), 1, file)) {
        printf("ID: %d, Title: %s, Author: %s, Quantity: %d, Price: %.2f\n", 
                book.bookID, book.title, book.author, book.quantity, book.price);
    }
    fclose(file);
}

void searchBook() {
    FILE *file = fopen(FILENAME, "r");
    if (!file) { printf("Error opening file.\n"); return; }

    int id;
    printf("Enter Book ID to search: ");
    scanf("%d", &id);

    struct Book book;
    while (fread(&book, sizeof(book), 1, file)) {
        if (book.bookID == id) {
            printf("Found: ID: %d, Title: %s, Author: %s, Quantity: %d, Price: %.2f\n", 
                    book.bookID, book.title, book.author, book.quantity, book.price);
            fclose(file);
            return;
        }
    }
    printf("Book not found.\n");
    fclose(file);
}

void updateBook() {
    FILE *file = fopen(FILENAME, "r+");
    if (!file) { printf("Error opening file.\n"); return; }

    int id;
    printf("Enter Book ID to update: ");
    scanf("%d", &id);

    struct Book book;
    while (fread(&book, sizeof(book), 1, file)) {
        if (book.bookID == id) {
            printf("Enter new Quantity: ");
            scanf("%d", &book.quantity);
            if (book.quantity < 0) book.quantity = 0;

            printf("Enter new Price: ");
            scanf("%f", &book.price);
            if (book.price < 0) book.price = 0;

            fseek(file, -sizeof(book), SEEK_CUR);
            fwrite(&book, sizeof(book), 1, file);
            fclose(file);
            printf("Book updated!\n");
            return;
        }
    }
    printf("Book not found.\n");
    fclose(file);
}

void deleteBook() {
    FILE *file = fopen(FILENAME, "r");
    if (!file) { printf("Error opening file.\n"); return; }

    FILE *temp = fopen("temp.txt", "w");
    if (!temp) { printf("Error creating temp file.\n"); fclose(file); return; }

    int id;
    printf("Enter Book ID to delete: ");
    scanf("%d", &id);

    struct Book book;
    int found = 0;
    while (fread(&book, sizeof(book), 1, file)) {
        if (book.bookID == id) {
            found = 1;
            continue;
        }
        fwrite(&book, sizeof(book), 1, temp);
    }

    fclose(file);
    fclose(temp);

    if (found) {
        remove(FILENAME);
        rename("temp.txt", FILENAME);
        printf("Book deleted!\n");
    } else {
        printf("Book not found.\n");
    }
}

void calculateInventory() {
    FILE *file = fopen(FILENAME, "r");
    if (!file) { printf("Error opening file.\n"); return; }

    struct Book book;
    float total = 0;
    while (fread(&book, sizeof(book), 1, file)) {
        total += book.quantity * book.price;
    }

    printf("Total inventory value: %.2f\n", total);
    fclose(file);
}

int main() {
    int choice;
    while (1) {
        printf("\n1. Add Book\n2. View Books\n3. Search Book\n4. Update Book\n5. Delete Book\n6. Calculate Inventory\n7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: addBook(); break;
            case 2: viewBooks(); break;
            case 3: searchBook(); break;
            case 4: updateBook(); break;
            case 5: deleteBook(); break;
            case 6: calculateInventory(); break;
            case 7: exit(0);
            default: printf("Invalid choice.\n");
        }
    }
    return 0;
}
