#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _trie
{
    char car[20];
    struct _trie *paths[10];
} trie;

trie *newNode()
{
    trie *node = NULL;
    node = (trie *)malloc(sizeof(trie));

    for (int i = 0; i < 10; i++)
    {
        node->paths[i] = NULL;
    }

    return node;
}

void insert(trie *node, int year, char *car)
{
    trie *current = node;
    int digit = year;

    int noOfDigits = 0;

    while (digit != 0)
    {
        noOfDigits++;
        digit /= 10;
    }

    int currDigit = year;

    int digits[noOfDigits];

    int i = noOfDigits - 1;
    while (currDigit != 0)
    {
        int dig = currDigit % 10;
        currDigit = currDigit / 10;

        digits[i] = dig;
        i--;
    }

    for (int i = 0; i < noOfDigits; i++)
    {
        // This screws up things and sets already set paths to null, however is needed for program to compile.
        // current->paths[digits[i]] = NULL;

        if (current->paths[digits[i]] == NULL)
        {
            current->paths[digits[i]] = newNode();
        }
        current = current->paths[digits[i]];
    }
    strcpy(current->car, car);
}

int search(trie *node, int year)
{
    trie *current = node;
    int digit = year;

    int noOfDigits = 0;

    while (digit != 0)
    {
        noOfDigits++;
        digit /= 10;
    }

    int currDigit = year;

    int digits[noOfDigits];

    int i = noOfDigits - 1;
    while (currDigit != 0)
    {
        int dig = currDigit % 10;
        currDigit = currDigit / 10;

        digits[i] = dig;
        i--;
    }

    for (int i = 0; i < noOfDigits; i++)
    {
        // If at any point an index has no car, return
        if (current->paths[digits[i]]->car == NULL)
            return 0;

        current = current->paths[digits[i]];
    }
    printf("%s", current->car);
    return 1;
}

int searchByCar(trie *node, char *car)
{
    trie *current = node;
    int in = 0;

    /* printf("%i", strcmp(current->paths[1]->paths[9]->paths[8]->paths[5]->car, car) == 0); */

    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            if (current->paths[j] != NULL)
            {
                if (strcmp(current->paths[j]->car, car) == 0)
                {
                    in = j;
                }
                /*  continue; */
                // Traverse
                current = current->paths[j];
            }
            /* else if (strcmp(current->paths[j]->car, car) == 0)
            {
                // String exists in trie
                in = j;
            } */
        }
    }
    return in;
}

int main()
{
    trie *head = newNode();

    insert(head, 1987, "Volvo");
    insert(head, 1985, "BMW");

    /* printf("%i", search(head, 1985));
    printf("%i", search(head, 1987)); */
    printf("%i", searchByCar(head, "BMW"));
    /* printf("%s", head->paths[1]->paths[9]->paths[8]->paths[5]->car);
    printf("%s", head->paths[1]->paths[9]->paths[8]->paths[7]->car); */
    /* head->paths[0] = malloc(sizeof(trie *)); */

    return 0;
}