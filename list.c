#include <stdio.h>
#include <stdlib.h>

typedef struct _node
{
    int data;
    struct _node *next;
} node;

node *createNode()
{
    node *head = (node *)malloc(sizeof(node));
    head->next = NULL;

    return head;
}

void insert(node *n, int data)
{
    node *current = n;

    while (current->next != NULL)
    {
        current = current->next;
    }
    current->data = data;
    current->next = createNode();
}

void printAll(node *n)
{
    node *current = n;
    while (current->next != NULL)
    {
        printf("%i\n", current->data);
        current = current->next;
    }
}

void prepend(node **head, int data)
{
    node *new = NULL;
    new = createNode();

    new->data = data;
    new->next = *head;
    *head = new;
}

int removeByValue(node **head, int val)
{
    node *current = *head;
    node *temp = NULL;

    int retval;

    while (current->next != NULL)
    {
        if (current->data == val)
        {
            temp = current;
            current = temp->next;
        }
        current = current->next;
    }

    retval = temp->data;
    printf("%i", retval);

    /* current->next = temp->next;
    free(current); */

    return -1;
}

int main()
{

    node *head = createNode();
    insert(head, 7);
    insert(head, 1);
    insert(head, 5);
    /* prepend(&head, 9); */
    printf("found: %i\n", removeByValue(&head, 7));

    printAll(head);
}