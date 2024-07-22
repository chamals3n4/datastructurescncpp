#include <iostream>
#include <stdio.h>
#include <stdlib.h>

struct Array
{
    int A[10];
    int size;
    int length;
};

void Display(struct Array arr)
{
    for (int i = 0; i < arr.length; i++)
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

// Method 1 - Auxiliary Array
void auxReverse(struct Array *arr)
{
    int *B;
    int i, j;
    // B = (int *)malloc(arr->length * sizeof(int));
    B = new int[arr->length];

    // reverse copy of all the element in array A in to B
    for (i = arr->length - 1, j = 0; i >= 0; i--, j++)
        B[j] = arr->A[i];

    // copy all the element in array B to A
    for (i = 0; i < arr->length; i++)
        arr->A[i] = B[i];
}

void swpReverse(struct Array *arr)
{
    int i, j;
    for (i = 0, j = arr->length - 1; i < j; i++, j--)
        swap(&arr->A[i], &arr->A[j]);
}

int main()
{
    struct Array arr = {{2, 3, 4, 5, 6}, 10, 5};
    Display(arr);
    // auxReverse(&arr);
    swpReverse(&arr);
    Display(arr);
}