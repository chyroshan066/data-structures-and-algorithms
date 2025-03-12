// Dynamic implementation of list
#include <stdio.h>
#include <stdlib.h>

struct SLL
{
    int data;
    struct SLL *Next;
};
struct SLL *top = NULL;
struct SLL *createNode(int element)
{
    struct SLL *NewNode;
    NewNode = (struct SLL *)malloc(sizeof(struct SLL));
    if (NewNode == NULL)
        return NULL;
    else
        NewNode->data = element;
    NewNode->Next = NULL;
    return NewNode;
}

void push(int element)
{
    struct SLL *NewNode = createNode(element);
    if (NewNode == NULL)
    {
        printf("MEmoory allcation if failed \n");
    }
    else if (top == NULL) // stack is empty
    {
        top = NewNode;
    }
    else
    {
        NewNode->Next = top;
        top = NewNode;
    }
    printf("%d was pushed in stack \n", element);
}

int pop()
{
    int element;
    struct SLL *temp;
    if (top == NULL)
    {
        printf("Satck underflow \n"); // stack is empty
        return -1;
    }
    else if (top->Next == NULL)
    {
        temp = top;
        top = NULL;
        element = temp->data;
        free(temp);
    }
    else
    {
        temp = top;
        top = top->Next;
        element = temp->data;
        free(temp);
    }
    return element;
}

int main()
{
    int data;
    printf("Enter data to be pushed: \n");
    scanf("%d", &data);
    push(data);
    push(100);
    push(500);
    data = pop();
    if (data != -1)
    {
        printf("%d was popped from stack \n", data);
    }
}