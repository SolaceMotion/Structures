#include <stdio.h>

#define LENGTH 10

int hash(const char *key)
{
    int sum = 0;
    int i = 0;
    while (key[i] != '\0')
    {
        sum += key[i];
        i++;
    }
    printf("hash is: %i\n", sum % LENGTH);
    return sum % LENGTH;
}

int isEmpty(int array[], int location)
{
    // If location in array is empty, the location is valid
    if (array[location] == 0)
    {
        return location;
    }
    return isEmpty(array, (location + 1) % LENGTH); // If location goes above 9 (approaches 10), set to 0 and examine 0th location
}

void add(int array[], const char *key, int value)
{
    int location = hash(key);
    array[isEmpty(array, location)] = value;

    /* int pt = 0;
    while (1)
    {
        if (array[location + pt] == 0)
        {
            pt++;
            break;
        }
        else
        {
            continue;
        }
    } */
    /* array[hash(key)] = value; */
}

int checkLocation()
{
}

int peek(int array[], const char *key)
{
    // Check location on hash using checkLocation
    return array[hash(key)];
}

int main()
{
    int array[LENGTH] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    add(array, "oliver", 3);
    add(array, "olivre", 2);

    printf("%i\n", peek(array, "oliver"));
    printf("%i\n", peek(array, "olivre"));

    for (int i = 0; i < LENGTH; i++)
    {
        printf("%i", array[i]);
    }
}