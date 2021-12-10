//
// Created by rebec on 11/17/2021.
//

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "rpn .h"
#include "stack.h"
#include "errors.h"


//adding stuff to see where it goes
//trying to add stuff to PS5


double recursivePower(double num1, double num2){
    double result;
    if (0 < num2 < 1) {
        return -1;
    }
    if (num2 < 0) {
        return -1;
    }
    if (num2 == 0){
        return 1;
    }
    if (num2 == 1){
        return num1;
    }
    result = num1 * recursivePower(num1, num2 - 1);
    return result;
}



double evaluate (char* expression, int* status) {

    clearStack();
    *status = 0;

    if (!expression) {
        *status = NOEXPRESSION;
    }
    double result;

    char * token = strtok(expression, " ");

    if (token == NULL) {
        *status = NOEXPRESSION; // there is no expression given to evaluate
    }

    while (token != NULL) {

        const char list_of_operators[5] = "+-/*^";
        char * if_operator = strstr(list_of_operators, token);


        if (if_operator) {      //token is an operator because it is in the list_of_operators
            char operator_type = *if_operator; // can dereference if_operator because if statement checked if it was null
            double first_num;
            double second_num;


            if (peek()) {
                node *first_number = pop();
                first_num = first_number->value;

                if (peek()) {
                    node *second_number = pop();
                    second_num = second_number->value;

                    switch (operator_type) {
                        case '+':
                            result = first_num + second_num;
                            break;

                        case '-':
                            result = second_num - first_num;
                            break;

                        case '/':
                            if (first_num == 0){
                                *status = DIVBYZERO; // give an error because can't divide by 0
                            }
                                result = second_num / first_num;
                            break;

                        case '*':
                            result = second_num * first_num;
                            break;

                        case '^':
                            result = recursivePower(second_num, first_num);
                            if (result < 0) {
                                *status = INCORRECTEXPONENT; // give error (the exponent is not a whole number or it is a negative number)
                            }
                            break;


                        default:
                            printf("should not happen if checking for operator is correct\n");
                            result = 0;

                    };
                    node * result_node = createNode(result, 1);
                    push(result_node);


                    if(peek()) {
                        node * check_num_nodes = pop();
                        if (peek()){
                            *status = TOOFEWOPERATORS; // more than one node after evaluation
                            break;
                        }
                        push(check_num_nodes);
                    } else {
                        *status = NULLPOINTER; // head is null after evaluation
                        break;
                    }

                } else {
                    *status = TOOMANYOPERATORS; // there is one number in the stack and one operator
                    break;
                }

            } else {
                *status = TOOMANYOPERATORS; // there are no numbers in the stack and one operator
                break;
            }

        } else {                //token must be a number (since if it's not in if_operator, a null pointer is returned)

            char *end_ptr;
            double number_input = strtod(token, &end_ptr);
            node * number = createNode(number_input, 1);
            push(number);
        }

        token = strtok(NULL, " ");

    }

    return result;


}