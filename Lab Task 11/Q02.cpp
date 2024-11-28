#include <stdio.h>
#include <stdlib.h>
void createFile(const char *filename) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        printf("Error: Could not create the file %s\n", filename);
        exit(1);}
    fprintf(file, "Hello, this is a predefined file.\n");
    fprintf(file, "It contains some sample content.\n");
    fprintf(file, "Each line will be displayed with its number.\n");
    fclose(file);
    printf("File '%s' created successfully with predefined content.\n\n", filename);}
void displayFileContents(const char *filename) {
    FILE *file = fopen(filename, "r");
    char line[256];
    int lineNumber = 1;
    if (file == NULL) {
        printf("Error: File '%s' does not exist.\n", filename);
        return; }
    printf("Contents of the file '%s' with line numbers:\n", filename);
    printf("--------------------------------------------\n");
    while (fgets(line, sizeof(line), file)) {
        printf("%d: %s", lineNumber, line);
        lineNumber++;}
    fclose(file);}
int main() {
    const char *defaultFile = "predefined.txt";
    createFile(defaultFile);
    char filename[100];
    printf("Enter the name of the file to read: ");
    scanf("%s", filename);
    displayFileContents(filename);
    return 0;}
