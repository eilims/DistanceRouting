//
// Created by DanielB on 4/9/2018.
//

#include "DistanceRouting.h"

void updateRoutingTable(struct Node *sourceNode, struct Node *targetNode, int nodeArrayLength, int sourceNodeIndex,
                        int targetNodeIndex) {
    //first update targetNode total table from the routing table in sourceNode
    //the routing table from sourceNode is guaranteed to be the best option so it will always update
    //This is due to the routing table selecting the best option using bellman ford to update the routing table
    int i;
    for (i = 0; i < nodeArrayLength; i++) {
        //updating the targetNode total routing table
        targetNode->totalRoutingTable[sourceNodeIndex][i] = sourceNode->routingTable[i].cost;
//        if (sourceNode->routingTable[i].cost != INT_MAX) {
//            targetNode->totalRoutingTable[sourceNodeIndex][i] =
//                    sourceNode->routingTable[i].cost + targetNode->totalRoutingTable[targetNodeIndex][i];
//        }
    }
    int *minimumRouteArray = findMinimumDistance(targetNode->totalRoutingTable, nodeArrayLength, targetNodeIndex);
    for (i = 0; i < nodeArrayLength; i++) {
        targetNode->totalRoutingTable[targetNodeIndex][i] = minimumRouteArray[i];
        targetNode->routingTable[i].cost = minimumRouteArray[i];
        targetNode->routingTable[i].nextNode = i;
    }
}
