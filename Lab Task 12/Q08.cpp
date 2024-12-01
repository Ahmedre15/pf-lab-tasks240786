#include <stdio.h>
#include <stdlib.h>

int main() {
    int numPoints;
    float *fees;
    float totalProfit = 0.0;

    printf("Enter the total number of points in the facility: ");
    scanf("%d", &numPoints);

    fees = (float *)malloc(numPoints * sizeof(float));

    if (fees == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    for (int i = 0; i < numPoints; i++) {
        printf("Enter fee for point %d: ", i + 1);
        scanf("%f", &fees[i]);

        if (fees[i] < 0) {
            printf("Invalid fee. Please enter a non-negative value.\n");
            i--;
            continue;
        }

        totalProfit += fees[i];
    }

    printf("Total Profit for the facility: $%.2f\n", totalProfit);

    free(fees);

    return 0;
}
