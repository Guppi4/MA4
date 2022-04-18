#pragma once
#include <stdio.h>


 typedef struct Stack {
    int top;
    unsigned capacity;
    int* array;
}Stack;
void creat_stack(Stack *s);
int isFull(Stack* s);
int isEmpty(Stack *s);
void push(Stack* stack, int item);
int pop(Stack* stack);
int peek(Stack* stack);