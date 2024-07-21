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

void Append(struct Array *arr, int x)
{
    if (arr->length < arr->size)
        arr->A[arr->length++] = x; // Add element at the current length then increment by one
}

void Insert(struct Array *arr, int index, int x)
{
    int i;
    if (index >= 0 && index <= arr->length)
    {
        for (i = arr->length; i > index; i--)
            arr->A[i] = arr->A[i - 1];
        arr->A[index] = x;
        arr->length++;
    }
}

int Delete(struct Array *arr, int index)
{
    int x = 0;
    int i;
    if (index >= 0 && index < arr->length)
    {
        x = arr->A[index];
        for (i = index; i < arr->length - 1; i++)
        {
            arr->A[i] = arr->A[i + 1];
        }
        arr->length--;
        return x;
    }
    return 0;
}

int main()
{

    struct Array arr = {{2, 3, 5, 6, 7}, 10, 5};

    Display(arr);
    // Append(&arr, 8);
    // Insert(&arr, 2, 4);
    std::cout << Delete(&arr, 4) << std::endl;
    Display(arr);

    return 0;
}