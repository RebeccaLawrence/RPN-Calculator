//
// Created by rebec on 11/18/2021.
//

#include "errors.h"
#include "stdlib.h"
#include <stdio.h>



char* errs[] = {
        "Null pointer encountered where there shouldn't be, program fails",
        "Too many operators, program fails",
        "Too few operators, program fails",
        "Divided by zero, program fails",
        "No expression passed into evaluate, program fails",
        "Exponent is either not a whole number or negative (which cant happen with recursive power function), program fails"
};

void error_handling(int input){
    printf("%s\n", errs[(input)*-1 - 1]);
}