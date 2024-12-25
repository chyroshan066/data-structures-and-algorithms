#include <stdio.h>

#define MAX 5

struct CircularQueue
{
    int FRONT;
    int REAR;
    int DATA[MAX];
};
typedef struct CircularQueue CQ;

void enqueue(CQ *Q, int element)
{
    if (Q->FRONT == (Q->REAR + 1) % MAX)
        printf("Queue is full\n");
    else
    {
        Q->DATA[Q->REAR] = element;
        Q->REAR = (Q->REAR + 1) % MAX;
        printf("%d was ENQUEUED!\n", element);
    }
}

int dequeue(CQ *Q)
{
    int element = -1;
    if (Q->FRONT == Q->REAR)
        printf("Queue is empty\n");
    else
    {
        element = Q->DATA[Q->FRONT];
        Q->FRONT = (Q->FRONT + 1) % MAX;
    }
    return element;
}

int main()
{
    int choice, data;
    CQ Q = {0, 0}; // Initialization of Q.FRONT and Q.REAR to 0
    do
    {
        printf("1. ENQUEUE\n 2. DEQUEUE\n 3. EXIT\n");
        printf("Choice? ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Element? ");
            scanf("%d", &data);
            enqueue(&Q, data);
            break;
        case 2:
            data = dequeue(&Q);
            if (data != -1)
                printf("DEQUEUED element is %d\n", data);
            break;
        case 3:
            printf("BYE!\n");
            break;

        default:
            break;
        }
    } while (choice != 3);
    return 0;
}
