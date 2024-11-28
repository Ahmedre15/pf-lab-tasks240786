#include <stdio.h>
struct phone {
    int areaCode;
    int exchange;
    int number;
};
int main() {
    struct phone myPhone = {212, 767, 8900}; 
    struct phone userPhone;  
    printf("Enter area code: ");
    scanf("%d", &userPhone.areaCode);
    printf("Enter exchange: ");
    scanf("%d", &userPhone.exchange);
    printf("Enter number: ");
    scanf("%d", &userPhone.number);
    printf("My number is (%d) %d-%d\n", myPhone.areaCode, myPhone.exchange, myPhone.number);
    printf("Your number is (%d) %d-%d\n", userPhone.areaCode, userPhone.exchange, userPhone.number);
    return 0;
}
