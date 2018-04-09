//
// Created by DanielB on 4/8/2018.
//


#include "BellmanFord.h"

//Be sure to free the returned pointer once you are finished!
int *findMinimumDistance(int **array, int arrayLength) {
    int nodeUnderTest;
    int currentEdge;
    int iteration;

    //Initializing returned array
    int *minimumArray = malloc(arrayLength * sizeof(int));
    for (nodeUnderTest = 0; nodeUnderTest < arrayLength; nodeUnderTest++) {
        minimumArray[nodeUnderTest] = INT_MAX;
    }

    //Begin processing
    minimumArray[0] = 0;
    //All iterations
    for (iteration = 0; iteration < arrayLength - 1; iteration++) {
        //Getting all edges
        for (nodeUnderTest = 0; ((nodeUnderTest < arrayLength)); nodeUnderTest++) {
            for (currentEdge = 0; currentEdge < arrayLength; currentEdge++) {
                //Make sure that the edge has been visited, the edge to the node exists, and the node is not the current one
                if (array[nodeUnderTest][currentEdge] < INT_MAX && minimumArray[nodeUnderTest] != INT_MAX && currentEdge != nodeUnderTest) {
                    //if the combined minimum and the current weight are less than the existing minimum then takle the new one
                    if (array[nodeUnderTest][currentEdge] + minimumArray[nodeUnderTest] < minimumArray[currentEdge]) {
                        minimumArray[currentEdge] = array[nodeUnderTest][currentEdge] + minimumArray[nodeUnderTest];
                    }
                }
            }
        }
    }
    return minimumArray;
}


