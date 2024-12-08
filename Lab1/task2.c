#include <stdio.h>

#define MAX 5
#define TRUE 1
#define FALSE 0

struct student
{
    char name[20];
    int roll;
    int age;
};

struct stack
{
    int TOS;
    struct student s[MAX];
};

void push(struct stack *ss, struct student st)
{
    if (ss->TOS == MAX - 1)
        printf("Stack Overflow\n");
    else
    {
        ss->TOS += 1;
        ss->s[ss->TOS] = st;
    }
}

struct student pop(struct stack *ss)
{
    struct student st;

    if (ss->TOS == -1)
        printf("Stack underflow\n");
    else
    {
        st = ss->s[ss->TOS];
        ss->TOS -= 1;
        return st;
    }
}

struct student peek(struct stack *ss)
{
    struct student st;

    if (ss->TOS == -1)
        printf("Stack underflow\n");
    else
    {
        st = ss->s[ss->TOS];
        return st;
    }
}

int isFull(struct stack *ss)
{
    if (ss->TOS == MAX - 1)
        return TRUE;
    else
        return FALSE;
}

int isEmpty(struct stack *ss)
{
    if (ss->TOS == -1)
        return TRUE;
    else
        return FALSE;
}

int main()
{
    int choice;
    struct student s;
    struct stack stk = {-1};

    do
    {
        printf("1. Push\n 2. Pop\n 3. Peek\n 4. IsFull\n 5. IsEmpty\n 6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            if (!isFull(&stk))
            {
                printf("Enter your name: ");
                scanf("%s", s.name);
                printf("Enter your age: ");
                scanf("%d", &s.age);
                printf("Enter your roll number: ");
                scanf("%d", &s.roll);
                push(&stk, s);
            }
            else
                printf("Stack is full. Cannot add new student anymore.\n");
            break;

        case 2:
            if (!isEmpty(&stk))
            {
                s = pop(&stk);
                printf("The removed items are: \n");
                printf("Name: %s\n", s.name);
                printf("Age: %d\n", s.age);
                printf("Roll No: %d\n", s.roll);
            }
            else
                printf("Stack is empty. Can't remove anymore.\n");
            break;

        case 3:
            if (!isEmpty(&stk))
            {
                s = peek(&stk);
                printf("Value at the top is\n");
                printf("Name: %s\n", s.name);
                printf("Age: %d\n", s.age);
                printf("Roll No: %d\n", s.roll);
            }
            else
                printf("No items to peek. The stack is empty.\n");
            break;

        case 4:
            if (isFull(&stk))
                printf("Stack is full.\n");
            else
                printf("Stack is not full.\n");
            break;

        case 5:
            if (isEmpty(&stk))
                printf("Stack is empty.\n");
            else
                printf("Stack is not empty.\n");
            break;

        default:
            printf("Choose numbers between 1 to 6\n");
            break;
        }
    } while (choice != 6);

    return 0;
}