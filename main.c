#include <stdio.h>
#include "BellmanFord.h"
#include "DistanceRouting.h"


void allocateBellmanTestArray(int ***array, int arraySize) {
    int i;
    *array = malloc(arraySize * sizeof(int));
    for (i = 0; i < arraySize; i++) {
        (*array)[i] = malloc(arraySize * sizeof(int));
    }
}

void initBellmanTestArrayNegative(int **array) {
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
}

void initBellmanTestArrayWorking(int **array) {
    //Standard Case
    //Expected result: 055798
    array[0][0] = 0;
    array[0][1] = 10;
    array[0][2] = INT_MAX;
    array[0][3] = INT_MAX;
    array[0][4] = INT_MAX;
    array[0][5] = 8;

    array[1][0] = INT_MAX;
    array[1][1] = 0;
    array[1][2] = INT_MAX;
    array[1][3] = 2;
    array[1][4] = INT_MAX;
    array[1][5] = INT_MAX;

    array[2][0] = INT_MAX;
    array[2][1] = 1;
    array[2][2] = 0;
    array[2][3] = INT_MAX;
    array[2][4] = INT_MAX;
    array[2][5] = INT_MAX;

    array[3][0] = INT_MAX;
    array[3][1] = INT_MAX;
    array[3][2] = -2;
    array[3][3] = 0;
    array[3][4] = INT_MAX;
    array[3][5] = INT_MAX;

    array[4][0] = INT_MAX;
    array[4][1] = -4;
    array[4][2] = INT_MAX;
    array[4][3] = -1;
    array[4][4] = 0;
    array[4][5] = INT_MAX;

    array[5][0] = INT_MAX;
    array[5][1] = INT_MAX;
    array[5][2] = INT_MAX;
    array[5][3] = INT_MAX;
    array[5][4] = 1;
    array[5][5] = 0;
}

void testBellmanArray(int **array, int arraySize) {
    int i;
    int *minimumArray = findMinimumDistance(array, arraySize);
    if (minimumArray != NULL) {
        printf("\nValid Minimum Table\n");
        for (i = 0; i < arraySize; i++) {
            printf("Index: %d Value: %d\n", i, minimumArray[i]);
        }
        //Free memory
        free(minimumArray);
    } else {
        printf("Negative Cycle Detected\n");
    }
}

void printNodeArray(struct Node **nodeArray, int nodeArraySize) {
    int i;
    int o;
    int q;
    printf("\nRouting tables\n");
    for (i = 0; i < nodeArraySize; i++) {
        for (o = 0; o < nodeArraySize; o++) {
            printf("Source Node: %d Destination Node: %d Weight: %d\n", i, o, nodeArray[i]->routingTable[o].cost);
        }
    }
    printf("\nTotal routing tables\n");
    for (q = 0; q < nodeArraySize; q++) {
        printf("Table Owner: %d\n", q);
        for (i = 0; i < nodeArraySize; i++) {
            for (o = 0; o < nodeArraySize; o++) {
                printf("Source Node: %d Destination Node: %d Weight: %d\n", i, o,
                       nodeArray[q]->totalRoutingTable[i][o]);
            }
        }
        printf("\n");
    }
}

//Requires size of 3
void setNodeArrayTest1(struct Node **nodeArray) {
    nodeArray[0]->totalRoutingTable[0][0] = 0;
    nodeArray[0]->totalRoutingTable[0][1] = 1;
    nodeArray[0]->totalRoutingTable[0][2] = 5;

    nodeArray[1]->totalRoutingTable[1][0] = 1;
    nodeArray[1]->totalRoutingTable[1][1] = 0;
    nodeArray[1]->totalRoutingTable[1][2] = 2;

    nodeArray[2]->totalRoutingTable[2][0] = 5;
    nodeArray[2]->totalRoutingTable[2][1] = 2;
    nodeArray[2]->totalRoutingTable[2][2] = 0;
}

void allocateNodeArray(struct Node ***nodeArray, int nodeArraySize) {
    int i;
    int o;
    *nodeArray = malloc(nodeArraySize * sizeof(struct Node *));
    for (i = 0; i < nodeArraySize; i++) {
        (*nodeArray)[i] = malloc(sizeof(struct Node));
        (*nodeArray)[i]->totalRoutingTable = malloc(nodeArraySize * sizeof(int *));
        for (o = 0; o < nodeArraySize; o++) {
            (*nodeArray)[i]->totalRoutingTable[o] = malloc(nodeArraySize * sizeof(int));
        }
        (*nodeArray)[i]->routingTable = malloc(nodeArraySize * sizeof(struct routingEntry));
    }
}

void initNodeArray(struct Node **nodeArray, int nodeArraySize) {
    int i;
    int o;
    int q;
    for (i = 0; i < nodeArraySize; i++) {
        for (o = 0; o < nodeArraySize; o++) {
            nodeArray[i]->routingTable[o].cost = INT_MAX;
            nodeArray[i]->routingTable[o].nextNode = -1;
            if (i == o) {
                nodeArray[i]->routingTable[o].cost = 0;
                nodeArray[i]->routingTable[o].nextNode = o;
            }
        }
    }
    for (q = 0; q < nodeArraySize; q++) {
        for (i = 0; i < nodeArraySize; i++) {
            for (o = 0; o < nodeArraySize; o++) {
                nodeArray[q]->totalRoutingTable[i][o] = INT_MAX;
                if (q == i && q == o) {
                    nodeArray[q]->totalRoutingTable[i][o] = 0;
                }
            }
        }
    }
}

int main() {
    printf("Hello, World!\n");
    int arraySize = 6;
    int i;
    int o;
    int q;
    int **array;
    allocateBellmanTestArray(&array, arraySize);
    initBellmanTestArrayWorking(array);
    testBellmanArray(array, arraySize);

    //Free memory from bellman tests
    for (i = 0; i < arraySize; i++) {
        free(array[i]);
    }
    free(array);



    //Setting up Distance routing test
    int nodeArraySize = 3;
    struct Node **nodeArray;

    //allocate node values
    allocateNodeArray(&nodeArray, nodeArraySize);

    //Initialize values
    initNodeArray(nodeArray, nodeArraySize);

    //Set test value
    setNodeArrayTest1(nodeArray);

    //Verify proper sizing and assignment
    //printNodeArray(nodeArray, nodeArraySize);

    for (q = 0; q < nodeArraySize; q++) {
        for (i = 0; i < nodeArraySize; i++) {
            for (o = 0; o < nodeArraySize; o++) {
                if (o != i) {
                    updateRoutingTable(nodeArray[o], nodeArray[i], nodeArraySize, o, i);
                }
            }
        }
    }


    //Verify proper sizing and assignment
    printNodeArray(nodeArray, nodeArraySize);

    //Freeing all pointers from node testing
    for (i = 0; i < nodeArraySize; i++) {
        for (o = 0; o < nodeArraySize; o++) {
            free(nodeArray[i]->totalRoutingTable[o]);
        }
        free(nodeArray[i]->totalRoutingTable);
        free(nodeArray[i]->routingTable);
        free(nodeArray[i]);
    }
    free(nodeArray);
    return 0;
}