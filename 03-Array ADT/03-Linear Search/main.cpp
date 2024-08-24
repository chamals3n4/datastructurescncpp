#include <stdio.h>
#include <stdlib.h>
#include <iostream>

struct Array
{
    int A[10];
    int size;
    int length;
};

// not passing this by addr cuz just print the value
void Display(struct Array arr)
{
    int i;
    for (i = 0; i < arr.length; i++)
    {
        std::cout << arr.A[i] << " ";
    }
    std::cout << std::endl;
}

void swap(int *x, int *y)
{
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

int LinearSearch(struct Array arr, int key)
{
    int i;
    for (i = 0; i < arr.length; i++)
    {
        if (key == arr.A[i])
            return i;
    }
    return -1;
}

// Transposition - swap the element with the previous element
int LinearSearchTransposition(struct Array *arr, int key) // call by addr bcz we are modifying the actual array
{
    int i;
    for (i = 0; i < arr->length; i++)
    {
        if (key == arr->A[i])
        {
            swap(&arr->A[i], &arr->A[i - 1]);
            return i;
        }
    }
    return -1;
}

// Move to Head - directly swap the key element to first element
int LinearSearchMovetoHead(struct Array *arr, int key)
{
    int i;
    for (i = 0; i < arr->length; i++)
    {
        if (key == arr->A[i])
        {
            swap(&arr->A[i], &arr->A[0]);
            return i;
        }
    }
    return -1;
}

int main()
{

    struct Array arr = {{2, 3, 4, 5, 6}, 10, 5};
    Display(arr);
    std::cout << LinearSearchMovetoHead(&arr, 6) << std::endl;
    Display(arr);

    return 0;
}