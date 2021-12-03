//
// Created by rebec on 11/17/2021.
//

#ifndef PS4_STACK_H
#define PS4_STACK_H
#include "node.h"


void push(node*);	     //Push a node onto the stack
node* pop(void); 	      //Pop the top of the stack
node* peek(void);	 //Return a reference to the node on top of the stack
void clearStack(void);      //resets the stack to empty


#endif //PS4_STACK_H
