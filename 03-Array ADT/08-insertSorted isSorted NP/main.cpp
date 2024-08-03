#include <iostream>

#define TRUE 1
#define FALSE 0

struct Array
{
    int A[20];
    int size;
    int length;
};

void Display(struct Array arr)
{
    int i;
    for (i = 0; i < arr.length; i++)
        std::cout << arr.A[i] << " ";
    std::cout << std::endl;
}

void Swap(int *x, int *y)
{
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

void insertSort(struct Array *arr, int x)
{
    int i = arr->length - 1;
    if (arr->length == arr->size)
        return;
    while (i >= 0 && arr->A[i] > x)
    {
        arr->A[i + 1] = arr->A[i];
        i--;
    }
    arr->A[i + 1] = x;
    arr->length++;
}

int isSorted(struct Array arr)
{
    int i;
    for (i = 0; i < arr.length - 1; i++)
        if (arr.A[i] > arr.A[i + 1])
            return FALSE;
    return TRUE;
}

void reArrange(struct Array *arr)
{
    int i = 0;
    int j = arr->length - 1;
    while (i < j)
    {
        while (arr->A[i] < 0)
            i++;
        while (arr->A[j] >= 0)
            j--;
        if (i < j)
            Swap(&arr->A[i], &arr->A[j]);
    }
}

int main()
{
    struct Array arr = {{8, -4, 2, 3, -8, 5, 6, 7}, 10, 8};
    Display(arr);
    insertSort(&arr, 4);
    Display(arr);
    std::cout << isSorted(arr) << std::endl;
    reArrange(&arr);
    Display(arr);

    return 0;
}