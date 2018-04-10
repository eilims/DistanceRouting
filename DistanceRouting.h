//
// Created by DanielB on 4/9/2018.
//

#ifndef DISTANCEROUTING_DISTANCEROUTING_H
#define DISTANCEROUTING_DISTANCEROUTING_H

#include <limits.h>
#include "BellmanFord.h"

//Index is the destination
//Cost is weight to destination
//Next node is the next node in the chain
struct routingEntry {
    int cost;
    int nextNode;
};


struct Node {
    struct routingEntry* routingTable;
    int** totalRoutingTable;
};

void updateRoutingTable(struct Node* sourceNode, struct Node* targetNode, int nodeArrayLength,  int sourceNodeIndex, int targetNodeIndex);

#endif //DISTANCEROUTING_DISTANCEROUTING_H
