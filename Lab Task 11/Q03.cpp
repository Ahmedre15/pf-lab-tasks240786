#include <stdio.h>
#include <stdlib.h>

int main() {
    char sourceFile[100], destFile[100];
    FILE *source, *destination;
    char ch;

    printf("Enter the name of the source file: ");
    scanf("%s", sourceFile);

    source = fopen(sourceFile, "r");
    if (source == NULL) {
        printf("Error: Could not open source file %s\n", sourceFile);
        return 1;
    }

    printf("Enter the name of the destination file: ");
    scanf("%s", destFile);

    destination = fopen(destFile, "w");
    if (destination == NULL) {
        printf("Error: Could not open destination file %s\n", destFile);
        fclose(source);
        return 1;
    }

    while ((ch = fgetc(source)) != EOF) {
        if (ch >= 'a' && ch <= 'z') {
            ch = ch - 32;
        }
        fputc(ch, destination);
    }

    printf("File copied successfully with lowercase characters converted to uppercase.\n");

    fclose(source);
    fclose(destination);

    return 0;
}
