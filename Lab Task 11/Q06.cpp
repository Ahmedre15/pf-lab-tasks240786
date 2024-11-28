#include <stdio.h>
#include <string.h>
struct Invoice {
    char partNumber[20];
    char partDescription[50];
    int quantity;
    float pricePerItem;};
float calculateInvoiceAmount(int quantity, float pricePerItem) {
    if (quantity <= 0) {
        quantity = 0;}
    if (pricePerItem <= 0) {
        pricePerItem = 0;}
    return quantity * pricePerItem;}
int main() {
    struct Invoice invoice = {"A12345","Hammer",10,15.50};
    float invoiceAmount = calculateInvoiceAmount(invoice.quantity, invoice.pricePerItem);
    printf("Invoice Details:\n");
    printf("Part Number: %s\n", invoice.partNumber);
    printf("Part Description: %s\n", invoice.partDescription);
    printf("Quantity: %d\n", invoice.quantity);
    printf("Price per Item: %.2f\n", invoice.pricePerItem);
    printf("Invoice Amount: %.2f\n", invoiceAmount);
    return 0;}
