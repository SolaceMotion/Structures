#include <stdio.h>
#include <stdlib.h>

typedef struct _node
{
    int data;
    struct _node *leaves[2];
} node;

node *initTree()
{
    node *root = (node *)malloc(sizeof(node));

    for (int i = 0; i < 2; i++)
    {
        root->leaves[i] = NULL;
    }
    return root;
}

void insert(node *root, int data)
{
    node *current = root;

    if (current->data)
    {
        current->data = data;
        return;
    }

    for (int i = 0; i < 2; i++)
    {

        if (data > current->data)
        {
            current = current->leaves[1];
            current->data = data;
        }
        if (data < current->data)
        {
            current = current->leaves[0];
            current->data = data;
        }
        current = current->leaves[i];
    }
}

int main()
{

    node *root = initTree();
    insert(root, 5);
    insert(root, 2);

    printf("%i", root->data);
    return 0;
}