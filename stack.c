#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stack.h"
#include <unistd.h>
#define S 1024
struct StackNode
{
    char *data;
    struct StackNode *next;
};
int posnode = sizeof(struct StackNode);
int posarray = sizeof(struct StackNode);

// A structure to represent a stack

void *my_malloc(size_t size);
void my_free(void *ptr);

void *my_malloc_arr(size_t size);
void my_free_arr(void *ptr);
struct StackNode *newNode(char *data)
{
    struct StackNode *stackNode =
        (struct StackNode *)
            my_malloc(sizeof(struct StackNode));
    stackNode->data = (char *)my_malloc_arr(S);
    strcpy(stackNode->data, data);
    stackNode->next = NULL;
    return stackNode;
}

int isEmpty(struct StackNode *root)
{
    return !root;
}

void push(struct StackNode **root, char *data)
{
    struct StackNode *stackNode = newNode(data);
    stackNode->next = *root;
    *root = stackNode;
    printf("%s pushed to stack\n", stackNode->data);
}

char *pop(struct StackNode **root)
{
    if (isEmpty(*root))
        return "Empty";
    struct StackNode *temp = *root;
    *root = (*root)->next;
    char *popped = temp->data;
    my_free(temp->data);
    my_free(temp);

    return popped;
}

char *peek(struct StackNode **root)
{
    char *temp;
    if (isEmpty(*root))
    {
        temp = "Empty";
        return temp;
    }
    temp = (*root)->data;

    return temp;
}
void *my_malloc(size_t size)
{

    void *p = sbrk(posnode);
    posnode += sizeof(struct StackNode);
    return p;
}

void my_free(void *ptr)
{

    sbrk(posnode);
    posnode -= sizeof(struct StackNode);
}
void *my_malloc_arr(size_t size)
{

    void *p = sbrk(posarray);
    posarray += sizeof(struct StackNode);
    return p;
}

void my_free_arr(void *ptr)
{

    sbrk(posarray);
    posarray -= sizeof(struct StackNode);
}