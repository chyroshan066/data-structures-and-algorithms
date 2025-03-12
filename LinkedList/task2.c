// Dynamic implementation of Queue

#include <stdio.h>
#include <stdlib.h>

struct SLL
{
    int data;
    struct SLL *Next;
};
struct SLL *FRONT, *REAR = NULL;
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
void ENQUEUE(int element)
{
    struct SLL *NewNode = createNode(element);
    if (NewNode == NULL)
    {
        printf("Memory allocation is failed \n");
    }
    else if (FRONT == NULL) // Queue is empty
    {
        FRONT = REAR = NewNode;
    }
    else
    {
        REAR->Next = NewNode;
        REAR = NewNode;
    }
    printf("%d was ENQUEUED in stack \n", element);
}
int DEQUEUE()
{
    struct SLL *temp;
    int element = -1;
    if (FRONT == NULL)
    {
        printf("QUEUE is empty \n");
    }
    else if (FRONT->Next == NULL)
    {
        temp = FRONT;
        FRONT = REAR = NULL;
        element = temp->data;
        free(temp);
    }
    else
    {
        temp = FRONT;
        FRONT = FRONT->Next;
        element = temp->data;
        free(temp);
    }
    return element;
}
int main()
{
    int data;
    printf("Enter data to be ENQUEUED: \n");
    scanf("%d", &data);
    ENQUEUE(data);
    ENQUEUE(1000);
    ENQUEUE(5000);

    data = DEQUEUE();
    if (data != -1)
    {
        printf("%d was DEQUEUD from stack \n", data);
    }
}