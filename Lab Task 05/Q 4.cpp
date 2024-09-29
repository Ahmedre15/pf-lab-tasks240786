#include <stdio.h>
int main() {
int purchaseamount;
char hasmembership;
printf("Enter your Total Purchase Amount: ");
scanf(" %d",&purchaseamount);
printf("Has Membership(write Y or y)");
scanf(" %c",&hasmembership);
 purchaseamount > 100  ?
	(hasmembership=='y' || hasmembership=='Y'
   ? printf("Discount is Applied\n")
   :printf("Discount is not applied"))
   :printf("Discount is not applied");
return 0;
}
