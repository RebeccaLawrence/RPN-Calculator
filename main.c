#include <stdio.h>
#include <stdlib.h>
#include "rpn .h"
#include "errors.h"

int main() {

    int status = 0;

    char expression_problem1[] =  {"24.2 12 / 3 / 17 + +"};
    double result_problem1 = evaluate(expression_problem1, &status);

    if (status == 0) {
        printf("The result of problem 1 is %f\n", result_problem1);
    } else {
        error_handling(status);
    }



    char expression_problem2[] =  {"+"};
    double result_problem2 = evaluate(expression_problem2, &status);


    if (status == 0) {
        printf("The result of problem 2 is %f\n", result_problem2);
    } else {
        error_handling( status);
    }



    char expression_problem3[] =  {"17 22 / 4 * 16 -"};
    double result_problem3 = evaluate(expression_problem3, &status);


    if (status == 0) {
        printf("The result of problem 3 is %f\n", result_problem3);
    } else {
        error_handling( status);
    }


    char expression_problem4[] =  {"2 8 ^ 3 /"};
    double result_problem4 = evaluate(expression_problem4, &status);


    if (status == 0) {
        printf("The result of problem 4 is %f\n", result_problem4);
    } else {
        error_handling( status);
    }

    char expression_problem5[] =  {"17 22 33 / 4 + 2"};
    double result_problem5 = evaluate(expression_problem5, &status);


    if (status == 0) {
        printf("The result of problem 5 is %f\n", result_problem5);
    } else {
        error_handling( status);
    }


    char expression_problem6[] =  {""};
    double result_problem6 = evaluate(expression_problem6, &status);


    if (status == 0) {
        printf("The result of problem 6 is %f\n", result_problem6);
    } else {
        error_handling( status);
    }


    char expression_problem7[] =  {"8 7 + 6 - 5 / 4 * 3 ^"};
    double result_problem7= evaluate(expression_problem7, &status);


    if (status == 0) {
        printf("The result of problem 7 is %f\n", result_problem7);
    } else {
        error_handling( status);
    }



}
