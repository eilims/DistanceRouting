#include <stdio.h>
#include "BellmanFord.h"

int main() {
    printf("Hello, World!\n");
    int arraySize = 4;
    int i;
    int **array = malloc(arraySize * sizeof(int));
    for (i = 0; i < arraySize; i++) {
        array[i] = malloc(arraySize * sizeof(int));
    }

    //negative cycle case
    array[0][0] = 0;
    array[0][1] = 1;
    array[0][2] = INT_MAX;
    array[0][3] = INT_MAX;

    array[1][0] = INT_MAX;
    array[1][1] = 0;
    array[1][2] = -1;
    array[1][3] = INT_MAX;

    array[2][0] = INT_MAX;
    array[2][1] = INT_MAX;
    array[2][2] = 0;
    array[2][3] = -1;

    array[2][0] = -1;
    array[2][1] = INT_MAX;
    array[2][2] = INT_MAX;
    array[2][3] = 0;

//Standard Case 055798
//    array[0][0] = 0;
//    array[0][1] = 10;
//    array[0][2] = INT_MAX;
//    array[0][3] = INT_MAX;
//    array[0][4] = INT_MAX;
//    array[0][5] = 8;
//
//    array[1][0] = INT_MAX;
//    array[1][1] = 0;
//    array[1][2] = INT_MAX;
//    array[1][3] = 2;
//    array[1][4] = INT_MAX;
//    array[1][5] = INT_MAX;
//
//    array[2][0] = INT_MAX;
//    array[2][1] = 1;
//    array[2][2] = 0;
//    array[2][3] = INT_MAX;
//    array[2][4] = INT_MAX;
//    array[2][5] = INT_MAX;
//
//    array[3][0] = INT_MAX;
//    array[3][1] = INT_MAX;
//    array[3][2] = -2;
//    array[3][3] = 0;
//    array[3][4] = INT_MAX;
//    array[3][5] = INT_MAX;
//
//    array[4][0] = INT_MAX;
//    array[4][1] = -4;
//    array[4][2] = INT_MAX;
//    array[4][3] = -1;
//    array[4][4] = 0;
//    array[4][5] = INT_MAX;
//
//    array[5][0] = INT_MAX;
//    array[5][1] = INT_MAX;
//    array[5][2] = INT_MAX;
//    array[5][3] = INT_MAX;
//    array[5][4] = 1;
//    array[5][5] = 0;

    int *minimumArray = findMinimumDistance(array, arraySize);
    if (minimumArray != NULL) {
        for (i = 0; i < arraySize; i++) {
            printf("Index: %d Value: %d\n", i, minimumArray[i]);
        }

        //Free memory
        free(minimumArray);
    } else {
        printf("Negative Cycle Detected\n");
    }
    for (i = 0; i < arraySize; i++) {
        free(array[i]);
    }
    free(array);
    return 0;
}