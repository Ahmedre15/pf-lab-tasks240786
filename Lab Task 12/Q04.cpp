#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int value;
    int frequency;
} Frequency;

int cmp(const void *a, const void *b) {
    Frequency *fa = (Frequency *)a;
    Frequency *fb = (Frequency *)b;
    if (fa->frequency != fb->frequency) {
        return fb->frequency - fa->frequency; 
    }
    return fa->value - fb->value; 
}

int main() {
    int T;
    printf("Enter the number of test cases: ");
    scanf("%d", &T);

    while (T--) {
        int N;
        printf("Enter the number of elements: ");
        scanf("%d", &N);

        int *arr = (int *)malloc(N * sizeof(int));
        Frequency *freq = (Frequency *)malloc(10002 * sizeof(Frequency));

        for (int i = 0; i < 10002; i++) {
            freq[i].value = i;
            freq[i].frequency = 0;
        }

        printf("Enter the elements:\n");
        for (int i = 0; i < N; i++) {
            scanf("%d", &arr[i]);
            freq[arr[i]].frequency++;
        }

        qsort(freq, 10002, sizeof(Frequency), cmp);

        printf("Number with highest frequency: %d\n", freq[0].value);

        free(arr);
        free(freq);
    }

    return 0;
}
