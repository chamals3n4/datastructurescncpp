#include <stdio.h>
#include <stdlib.h>

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

int BinarySearch(struct Array arr, int key)
{
    int l, mid, h;
    l = 0, h = arr.length - 1;
    while (l <= h)
    {
        mid = (l + h) / 2;
        if (key == arr.A[mid])
            return mid;
        else if (key < arr.A[mid])
            h = mid - 1;
        else
            l = mid + 1;
    }
    return -1;
}

int RBinSearch(struct Array arr, int l, int h, int key)
{
    int mid;
    if (l <= h)
    {
        mid = (l + h) / 2;
        if (key == arr.A[mid])
            return mid;
        else if (key < arr.A[mid])
            RBinSearch(arr, l, mid - 1, key);
        else
            RBinSearch(arr, mid + 1, h, key);
    }
    return -1;
}

int main()
{

    struct Array arr = {{10, 20, 30, 40, 50}, 10, 5};
    printf("%d \n", BinarySearch(arr, 30));
    printf("%d \n", RBinSearch(arr, 0, arr.length - 1, 30));

    printf("%d \n", BinarySearch(arr, 54));
    printf("%d \n", RBinSearch(arr, 0, arr.length - 1, 54));
    return 0;
}