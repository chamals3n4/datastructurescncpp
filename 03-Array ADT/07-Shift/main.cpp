#include <iostream>

struct Array
{
    int A[10];
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

void leftShift(struct Array *arr)
{
    if (arr->length > 0)
    {
        int i;
        for (i = 0; i < arr->length - 1; i++)
            arr->A[i] = arr->A[i + 1];
        arr->A[arr->length - 1] = 0;
    }
}

void leftRotate(struct Array *arr)
{
    if (arr->length > 0)
    {
        int temp = arr->A[0]; // store the first element
        int i;
        for (i = 0; i < arr->length - 1; i++)
            arr->A[i] = arr->A[i + 1];
        arr->A[arr->length - 1] = temp;
    }
}

int main()
{
    struct Array arr = {{2, 3, 4, 5, 6}, 10, 5};
    Display(arr);
    // leftShift(&arr);
    leftRotate(&arr);
    Display(arr);

    return 0;
}