//
// Created by rebec on 11/17/2021.
//


#include <stdlib.h>
#include <stdio.h>
#include "stack.h"

node *HEAD = NULL;


void push(node* node_p) {
    if (HEAD){
        node * temp_node = HEAD;
        HEAD = node_p;
        HEAD->next = temp_node;
    } else {
        HEAD = node_p;
    }
}


node* pop()	 {
    node * temp_node = HEAD;
    HEAD = HEAD->next;
    return temp_node;
}

node* peek() {
    return HEAD;
}

void clearStack() {
    while (HEAD){
        node * temp_node = pop();
        free(temp_node);
        temp_node = NULL;
    }
}

