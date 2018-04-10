//
// Created by DanielB on 4/9/2018.
//

#ifndef DISTANCEROUTING_DISTANCEROUTING_H
#define DISTANCEROUTING_DISTANCEROUTING_H

#include <limits.h>

struct routingEntry {
    int cost;
    int nextNode;
};

struct Node {
    struct routingEntry* routingTable;
};

#endif //DISTANCEROUTING_DISTANCEROUTING_H
