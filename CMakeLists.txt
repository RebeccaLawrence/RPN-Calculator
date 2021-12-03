cmake_minimum_required(VERSION 3.0)
project(ps4 C)

set(CMAKE_C_STANDARD 99)

add_executable(ps4 main.c node.c stack.c node.h stack.h "rpn .h" errors.h rpn.c error.c)
