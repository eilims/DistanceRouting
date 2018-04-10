//
// Created by DanielB on 4/8/2018.
//

#ifndef DISTANCEROUTING_BELLMANFORD_H
#define DISTANCEROUTING_BELLMANFORD_H

#include <malloc.h>
#include <limits.h>

struct BellmanNode {
    int weight;
    int previousNodeIndex;
};

struct BellmanNode* findMinimumDistance(int** array, int arrayLength, int startingIndex);


#endif //DISTANCEROUTING_BELLMANFORD_H
