#include <stdio.h>

#define MAXBOXES 10  
#define MAXITEMS 10  

typedef struct Box {
    int weights[MAXITEMS];     
    int weightsCount;           

    int nestedBoxes[MAXBOXES];  
    int nestedBoxCount;        
} Box;

int calculateTotalWeight(Box boxes[], int boxIndex) {
    Box box = boxes[boxIndex];
    int totalWeight = 0;

    for (int i = 0; i < box.weightsCount; i++) {
        totalWeight += box.weights[i];
    }

    for (int i = 0; i < box.nestedBoxCount; i++) {
        totalWeight += calculateTotalWeight(boxes, box.nestedBoxes[i]);
    }

    return totalWeight;
}

int main() {
    
    Box boxes[MAXBOXES];

    boxes[0].weightsCount = 2;
    boxes[0].weights[0] = 2;
    boxes[0].weights[1] = 3;
    boxes[0].nestedBoxCount = 0;

    boxes[1].weightsCount = 1;
    boxes[1].weights[0] = 4;
    boxes[1].nestedBoxCount = 0;


    boxes[2].weightsCount = 0;
    boxes[2].nestedBoxCount = 2;
    boxes[2].nestedBoxes[0] = 0;
    boxes[2].nestedBoxes[1] = 1;
    
    boxes[3].weightsCount = 1;
    boxes[3].weights[0] = 1;
    boxes[3].nestedBoxCount = 0;

    boxes[4].weightsCount = 0;
    boxes[4].nestedBoxCount = 2;
    boxes[4].nestedBoxes[0] = 2; 
    boxes[4].nestedBoxes[1] = 3; 
    int totalWeight = calculateTotalWeight(boxes, 4);
    printf("Total weight of the main box is %d\n", totalWeight);

    return 0;
}
