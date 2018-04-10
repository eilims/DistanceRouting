//
// Created by DanielB on 4/8/2018.
//


#include "BellmanFord.h"

//Be sure to free the returned pointer once you are finished!
struct BellmanNode *findMinimumDistance(int **array, int arrayLength, int startingIndex) {
    int nodeUnderTest;
    int currentEdge;
    int iteration;

    //Initializing returned array
    struct BellmanNode *minimumArray = malloc(arrayLength * sizeof(struct BellmanNode));
    for (nodeUnderTest = 0; nodeUnderTest < arrayLength; nodeUnderTest++) {
        minimumArray[nodeUnderTest].weight = INT_MAX;
        minimumArray[nodeUnderTest].previousNodeIndex = -1;
    }

    //Begin processing from specified node
    minimumArray[startingIndex].weight = 0;
    minimumArray[startingIndex].previousNodeIndex = startingIndex;
    //All iterations
    for (iteration = 0; iteration < arrayLength - 1; iteration++) {
        //Getting all edges
        for (nodeUnderTest = 0; ((nodeUnderTest < arrayLength)); nodeUnderTest++) {
            for (currentEdge = 0; currentEdge < arrayLength; currentEdge++) {
                //Make sure that the edge has been visited, the edge to the node exists, and the node is not the current one
                if (array[nodeUnderTest][currentEdge] < INT_MAX && minimumArray[nodeUnderTest].weight != INT_MAX &&
                    currentEdge != nodeUnderTest) {
                    //if the combined minimum and the current weight are less than the existing minimum then take the new one
                    if (array[nodeUnderTest][currentEdge] + minimumArray[nodeUnderTest].weight <
                        minimumArray[currentEdge].weight) {
                        minimumArray[currentEdge].weight =
                                array[nodeUnderTest][currentEdge] + minimumArray[nodeUnderTest].weight;
                        minimumArray[currentEdge].previousNodeIndex = nodeUnderTest;
                    }
                }
            }
        }
    }

    for (nodeUnderTest = 0; ((nodeUnderTest < arrayLength)); nodeUnderTest++) {
        for (currentEdge = 0; currentEdge < arrayLength; currentEdge++) {
            //Make sure that the edge has been visited, the edge to the node exists, and the node is not the current one
            if (array[nodeUnderTest][currentEdge] < INT_MAX && minimumArray[nodeUnderTest].weight != INT_MAX &&
                currentEdge != nodeUnderTest) {
                //if the combined minimum and the current weight are less than the existing minimum then takle the new one
                if (array[nodeUnderTest][currentEdge] + minimumArray[nodeUnderTest].weight <
                    minimumArray[currentEdge].weight) {
                    return NULL;
                }
            }
        }
    }

    return minimumArray;
}


