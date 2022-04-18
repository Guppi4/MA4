#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
 #include <string.h>
#define S 1024
// A structure to represent a stack
struct StackNode {
    char* data;
    struct StackNode* next;
};
struct StackNode* newNode(char* data)
{
    struct StackNode* stackNode =
      (struct StackNode*)
      malloc(sizeof(struct StackNode));
     stackNode->data=(char*)malloc(S);
     strcpy(stackNode->data ,data);
    stackNode->next = NULL;
    return stackNode;
}
 
int isEmpty(struct StackNode* root)
{
    return !root;
}
 
void push(struct StackNode** root, char* data)
{
    struct StackNode* stackNode = newNode(data);
    stackNode->next = *root;
    *root = stackNode;
    printf("%s pushed to stack\n", data);
}
 
char* pop(struct StackNode** root)
{
    if (isEmpty(*root))
        return "Empty";
    struct StackNode* temp = *root;
    *root = (*root)->next;
    char* popped = temp->data;
    free(temp);
 
    return popped;
}
 
char* peek(struct StackNode* root)
{
    if (isEmpty(root))
        return "Empty";
    return root->data;
}
 
int main()
{
    struct StackNode* root = NULL;
 
    push(&root, "one");
    push(&root, "two");
    push(&root, "thre");
 
    printf("%s popped from stack\n", pop(&root));
 
    printf("Top element is %s\n", peek(root));
 
    return 0;
}