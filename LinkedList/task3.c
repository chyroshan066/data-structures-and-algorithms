#include <stdio.h>
#include <stdlib.h>

struct SLL
{
    int data;
    struct SLL *next;
};

struct SLL *first, *last = NULL;
struct SLL *createNode(int element)
{
    struct SLL *NewNode;
    NewNode = (struct SLL *)malloc(sizeof(struct SLL));
    if (NewNode == NULL)
        return NULL;
    else
        NewNode->data = element;
    NewNode->next = NULL;
    return NewNode;
}
void insertAtBegining(int element)
{
    struct SLL *NewNode = createNode(element);
    if (NewNode == NULL)
        printf("Memory allocation is failed \n");
    else
    {
        if (first == NULL)
        {
            first = last = NewNode;
        }
        else
        {
            NewNode->next = first;
            first = NewNode;
        }
        printf("%d was inserted at the BEGINING \n", first->data);
    }
}
void insertAtEnd(int element)
{
    struct SLL *NewNode = createNode(element);
    if (NewNode == NULL)
        printf("Memory allocation is failed \n");
    else
    {
        if (first == NULL)
        {
            first = last = NewNode;
        }
        else
        {
            last->next = NewNode;
            last = NewNode;
        }

        printf("%d was inserted at the End \n", last->data);
    }
}

void insertAtSpecific(int element, int POS)
{
    int i;
    struct SLL *NewNode = createNode(element);
    struct SLL *temp;
    if (NewNode == NULL)
        printf("Memory allocation is failed");
    else
    {
        if (POS == 1)
        {
            insertAtBegining(element);
        }
        else
        {

            temp = first;
            for (i = 0; i < POS - 1; i++)
            {
                temp = temp->next;
            }
            NewNode->next = temp->next;
            temp->next = NewNode;
            printf("%d was inserted at the SPECIFIC %d \n", element, POS);
        }
    }
}
int deletionFromBegining()
{
    struct SLL *temp;
    int element = -1;
    if (first == NULL)
    {
        printf("LIST IS EMPTY \n");
    }
    else if (first->next == NULL)
    {
        temp = first;
        first = last = NULL;
        element = temp->data;
        free(temp);
    }
    else
    {
        temp = first;
        first = first->next;
        element = temp->data;
        free(temp);
    }
    return element;
}

int deletionFromEnd()
{
    struct SLL *temp;
    int element = -1;
    if (first == NULL)
    {
        printf("LIST IS EMPTY \n");
    }
    else if (first->next == NULL)
    {
        temp = first;
        first = last = NULL;
        element = temp->data;
        free(temp);
    }
    else
    {
        temp = first;
        while (temp->next != last)
        {
            temp = temp->next;
        }

        last = temp;
        temp = temp->next;
        element = temp->data;
        free(temp);
        last->next = NULL;
    }
    return element;
}

int deletionAtSpecific(int POS)
{
    int element;
    int i;
    struct SLL *temp, *tempp;
    if (POS < 1)
    {
        printf("Invalid position.\n");
    }
    else if (POS == 1)
    {
        element = deletionFromBegining();
    }
    else
    {
        temp = first;
        for (i = 1; i < POS - 1; i++)
        {
            temp = temp->next;
        }
        tempp = temp->next;
        temp->next = tempp->next;
        element = tempp->data;
        free(tempp);
    }
    return element;
}

int search(int key)
{

    int flag = 0;
    struct SLL *temp;

    if (first == NULL)
    {
        printf("LIST IS  EMPTY \n");
    }

    else
    {
        temp = first;
        do
        {
            if (temp->data == key)
            {
                flag = 1;
                // printf("Element %d was found \n,key");
                break;
            }
            temp = temp->next;
        } while (temp != NULL);
        if (flag == 1)
            printf("%d is found in the list\n", key);

        else
        {
            printf("ELEMENT %d was NOT FOUND \n", key);
        }
    }
    return flag;
}

void display()
{
    struct SLL *temp;
    ;
    if (first == NULL)
    {
        printf("LIST IS EMPTY \n");
    }
    else
    {
        temp = first;
        do
        {
            printf("%d -> ", temp->data);
            temp = temp->next;
        } while (temp != NULL);
        printf("NULL \n");
    }
}
int main()
{
    int data, srch;
    insertAtBegining(100);
    display();
    insertAtEnd(200);
    display();
    insertAtBegining(500);
    display();
    insertAtSpecific(300, 2);
    display();
    insertAtSpecific(1000, 3);
    display();
    data = deletionFromBegining();
    if (data != -1)
    {
        printf("Data was deletd from BEGINING %d\n", data);
        display();
    }
    data = deletionFromEnd();
    if (data != -1)
    {
        printf("Data was deletd from End %d \n", data);
        display();
    }

    data = deletionAtSpecific(2);
    display();
    printf("Enter the element to search: \n");
    scanf("%d", &srch);
    search(srch);

    display();

    return 0;
}