#include <stdio.h>
struct Rectangle {
    float length;
    float width;};
int check(struct Rectangle rect) {
    if (rect.length > 0.0 && rect.length < 20.0 && rect.width > 0.0 && rect.width < 20.0) {
        return 1;}
    return 0;}
float calculatePerimeter(struct Rectangle rect) {
    return 2 * (rect.length + rect.width);}
float calculateArea(struct Rectangle rect) {
    return rect.length * rect.width;}
int main() { struct Rectangle rect;
    printf("Enter the length of the rectangle: ");
    scanf("%f", &rect.length);
    printf("Enter the width of the rectangle: ");
    scanf("%f", &rect.width);
    if (!check(rect)) {
        printf("Invalid dimensions! Length and width must be between 0.0 and 20.0.\n");
        return 1; }
    printf("Perimeter of the rectangle: %.2f\n", calculatePerimeter(rect));
    printf("Area of the rectangle: %.2f\n", calculateArea(rect));
    return 0;}
