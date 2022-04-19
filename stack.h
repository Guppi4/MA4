#ifndef COMMANDS_H_
#define COMMANDS_H_
#include <stdio.h>
#define S 1024


struct StackNode* newNode(char* data);

char* getData(struct StackNode* root);
int isEmpty(struct StackNode* root);
void push(struct StackNode** root,char* data);
char* pop(struct StackNode** root);
char* peek(struct StackNode* root);

#endif