#pragma once
#include <stdio.h>
#define S 1024


struct StackNode* newNode(char* data);


int isEmpty(struct StackNode* root);
void push(struct StackNode* root);
char* pop(struct StackNode** root);
int peek(struct StackNode* root);