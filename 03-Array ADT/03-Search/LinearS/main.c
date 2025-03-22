#include <stdio.h>
#include <stdlib.h>

// move to head trasposition and normal

struct Array
{
    int A[10];
    int size;
    int length;
};

void display(struct Array arr)
{
    for (int i = 0; i < arr.length; i++)
        printf("%d ", arr.A[i]);
    printf("\n");
}

void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

int LinearSearch(struct Array arr, int key)
{
    for (int i = 0; i < arr.length; i++)
    {
        if (arr.A[i] == key)
        {
            return i;
        }
    }
    return -1;
}

int LinearSearchTransposition(struct Array *arr, int key)
{
    for (int i = 0; i < arr->length; i++)
    {
        if (arr->A[i] == key)
        {
            swap(&arr->A[i], &arr->A[i - 1]);
            return i;
        }
    }
    return -1;
}

int LinearSearchMovetoHead(struct Array *arr, int key)
{
    for (int i = 0; i < arr->length; i++)
    {
        if (arr->A[i] == key)
        {
            swap(&arr->A[i], &arr->A[0]);
            return i;
        }
    }
    return -1;
}

int main()
{
    struct Array arr = {{10, 20, 30, 40, 50}, 10, 5};
    display(arr);
    // printf("%d ", LinearSearch(arr, 30));
    printf("%d \n", LinearSearchTransposition(&arr, 30));
    printf("%d \n", LinearSearchTransposition(&arr, 30));
    return 0;
}
