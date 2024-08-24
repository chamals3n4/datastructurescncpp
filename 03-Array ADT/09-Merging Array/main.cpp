#include <iostream>

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

struct Array *Merge(struct Array *arr1, struct Array *arr2)
{
    int i, j, k;
    i = j = k = 0;
    // struct Array *arr3 = (struct Array *)malloc(sizeof(struct Array));4
    struct Array *arr3 = new Array;

    while (i < arr1->length && j < arr2->length)
    {
        if (arr1->A[i] < arr2->A[j])
            arr3->A[k++] = arr1->A[i++];
        else
            arr3->A[k++] = arr2->A[j++];
    }
    for (; i < arr1->length; i++)
        arr3->A[k++] = arr1->A[i++];
    for (; j < arr2->length; j++)
        arr3->A[k++] = arr2->A[j++];

    arr3->length = arr1->length + arr2->length;
    arr3->size = 20;

    return arr3;
}

int main()
{
    struct Array arr1 = {{2, 6, 10, 15, 25}, 10, 5};
    struct Array arr2 = {{3, 4, 7, 18, 20}, 10, 5};
    struct Array *arr3;

    std::cout << "arr1 : ";
    Display(arr1);

    std::cout << "arr2 :";
    Display(arr2);

    arr3 = Merge(&arr1, &arr2);
    std::cout << "arr3 : ";
    Display(*arr3);

    //{2,3,4,6,7,10,15,18,20,25}

    return 0;
}