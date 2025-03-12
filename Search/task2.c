#include <stdio.h>
#include <stdlib.h>

struct BST
{
    int data;
    struct BST *LEFT;
    struct BST *RIGHT;
    // struct BST *parent;
};
struct BST *ROOT = NULL;

struct BST *createNode(int element)
{
    struct BST *newNode;
    newNode = (struct BST *)malloc(sizeof(struct BST));
    if (newNode == NULL)
        return NULL;
    else
    {
        newNode->data = element;
        newNode->LEFT = NULL;
        newNode->RIGHT = NULL;
        return newNode;
    }
};
struct BST *Insert(struct BST *ROOT, int element)
{
    if (ROOT == NULL)
        return createNode(element);

    else if (element < ROOT->data)
    {
        ROOT->LEFT = Insert(ROOT->LEFT, element);
    }
    else
    {
        ROOT->RIGHT = Insert(ROOT->RIGHT, element);
    }
    return ROOT;
}
struct BST *search(struct BST *ROOT, int key)
{
    if (ROOT == NULL || ROOT->data == key)
        return ROOT;
    else if (key < ROOT->data)
        return search(ROOT->LEFT, key);
    else
        return search(ROOT->RIGHT, key);
}
struct BST *findMin(struct BST *ROOT)
{
    while (ROOT->LEFT != NULL)
    {
        ROOT = ROOT->LEFT;
    }
    return ROOT;
}
struct BST *findMax(struct BST *ROOT)
{
    while (ROOT->RIGHT != NULL)
    {
        ROOT = ROOT->RIGHT;
    }
    return ROOT;
}

struct BST *Delete(struct BST *ROOT, int element)
{
    struct BST *temp;
    if (ROOT == NULL)
        return ROOT;
    else if (element < ROOT->data)
    {
        ROOT->LEFT = Delete(ROOT->LEFT, element);
    }
    else if (element > ROOT->data)
    {
        ROOT->RIGHT = Delete(ROOT->RIGHT, element);
    }
    else
    {
        // NO CHILD
        if (ROOT->LEFT == NULL && ROOT->RIGHT == NULL)
        {
            free(ROOT);
            return NULL;
        }

        // one child

        else if (ROOT->RIGHT == NULL)
        {
            temp = ROOT->LEFT;
            free(ROOT);
            return temp;
        }
        else if (ROOT->LEFT == NULL)
        {
            temp = ROOT->RIGHT;
            free(ROOT);
            return temp;
        }

        // two children

        else
        {
            temp = findMin(ROOT->RIGHT);
            ROOT->data = temp->data;
            ROOT->RIGHT = Delete(ROOT->RIGHT, temp->data);
        }
    }
    return ROOT;
}

void pre_order(struct BST *ROOT)
{
    if (ROOT == NULL)
    {
        printf("Tree is empty!\n");
        return;
    }
    else
    {
        printf("%d ", ROOT->data);
        pre_order(ROOT->LEFT);
        pre_order(ROOT->RIGHT);
    }
};
void in_order(struct BST *ROOT)
{
    if (ROOT == NULL)
    {
        printf("Tree is empty!\n");
        return;
    }
    else
    {
        in_order(ROOT->LEFT);
        printf("%d ", ROOT->data);
        in_order(ROOT->RIGHT);
    }
};
void post_order(struct BST *ROOT)
{
    if (ROOT == NULL)
    {
        printf("Tree is empty!\n");
        return;
    }
    else
    {
        post_order(ROOT->LEFT);
        post_order(ROOT->RIGHT);
        printf("%d ", ROOT->data);
    }
};
int main()
{
    int choice, element;

    while (1)
    {
        printf("\n1. INSERT\n2. DELETE\n3. SEARCH\n4. PREORDER\n5. INORDER\n6. POSTORDER\n7. EXIT\n");
        printf("Choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter the element to be inserted: ");
            scanf("%d", &element);
            ROOT = Insert(ROOT, element);
            printf("%d INSERTED\n", element);
            break;

        case 2:
            if (ROOT == NULL)
            {
                printf("Tree is empty! No value to delete.\n");
            }
            else
            {
                printf("Enter the element to be deleted: ");
                scanf("%d", &element);
                if (search(ROOT, element))
                {
                    ROOT = Delete(ROOT, element);
                    printf("%d DELETED\n", element);
                }
                else
                {
                    printf("%d NOT FOUND \n !!!", element);
                }
            }
            break;

        case 3:
            printf("Enter the element to be searched: ");
            scanf("%d", &element);
            if (search(ROOT, element))
                printf("%d FOUND\n", element);
            else
                printf("%d NOT FOUND\n", element);
            break;
        case 4:
            printf("Preorder: ");
            pre_order(ROOT);
            printf("\n");
            break;

        case 5:
            printf("Inorder: ");
            in_order(ROOT);
            printf("\n");
            break;

        case 6:
            printf("Postorder: ");
            post_order(ROOT);
            printf("\n");
            break;

        case 7:
            exit(0);
            break;

        default:
            printf("Invalid choice! Try again.\n");
            ;
        }
    }
}