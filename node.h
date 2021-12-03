//
// Created by rebec on 11/17/2021.
//

#ifndef PS4_NODE_H
#define PS4_NODE_H

//taken from ps3 solutions given
//

typedef struct node {
    double value;
    int type;
    struct node *next;
} node;



node *createNode(double value, int type);

#endif //PS4_NODE_H