//
// Created by rebec on 11/17/2021.
//

// taken from ps3 solutions given
//

#include <stdlib.h>
#include <stdio.h>
#include "node.h"

enum type {operator, number};


node *createNode(double value, int type) {
    node *newNode = (struct node*) malloc(sizeof(node));
    if (newNode) {
        newNode->value = value;
        newNode->next = NULL;
        if (type == 0){
            newNode->type = operator;
        } else {
            newNode->type = number;
        }
    } else {
        puts("Unable to allocate memory for a node.\n");
        exit(-1);
    }
    return newNode;

}