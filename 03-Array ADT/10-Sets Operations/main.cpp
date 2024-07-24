/*
Union Intersection and Difference upon set of elements
*/

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

struct Array *Union(struct Array *arr1, struct Array *arr2)
{
    int i, j, k;
    i = j = k = 0;
    struct Array *arr4 = new Array;

    while (i < arr1->length && j < arr2->length)
    {
        if (arr1->A[i] < arr2->A[j])
            arr4->A[k++] = arr1->A[i++];
        else if (arr2->A[j] < arr1->A[i])
            arr4->A[k++] = arr2->A[j++];
        else
        {
            // both are equal
            arr4->A[k++] = arr1->A[i++];
            j++;
        }
    }
    for (; i < arr1->length; i++)
        arr4->A[k++] = arr1->A[i++];
    for (; j < arr2->length; j++)
        arr4->A[k++] = arr2->A[j++];

    arr4->length = k;
    arr4->size = 20;

    return arr4;
}

struct Array *Intersection(struct Array *arr1, struct Array *arr2)
{
    int i, j, k;
    i = j = k = 0;
    struct Array *arr5 = new Array;

    while (i < arr1->length && j < arr2->length)
    {
        if (arr1->A[i] < arr2->A[j])
            i++;
        else if (arr2->A[j] < arr1->A[i])
            j++;
        else if (arr1->A[i] == arr2->A[j])
        {
            arr5->A[k++] = arr1->A[i++];
            j++;
        }
    }

    arr5->length = k;
    arr5->size = 20;

    return arr5;
}

struct Array *Difference(struct Array *arr1, struct Array *arr2)
{
    int i, j, k;
    i = j = k = 0;
    struct Array *arr6 = new Array;

    while (i < arr1->length && j < arr2->length)
    {
        if (arr1->A[i] < arr2->A[j])
            arr6->A[k++] = arr1->A[i++];
        else if (arr2->A[j] < arr1->A[i])
            j++;
        else
        {
            i++;
            j++;
        }
    }
    for (; i < arr1->length; i++)
        arr6->A[k++] = arr1->A[i++];

    arr6->length = k;
    arr6->size = 20;

    return arr6;
}

int main()
{
    struct Array arr1 = {{2, 6, 10, 15, 25}, 10, 5};
    struct Array arr2 = {{3, 6, 7, 15, 20}, 10, 5};
    struct Array *arr3; // Merge
    struct Array *arr4; // Union
    struct Array *arr5; // Intersection
    struct Array *arr6; // Difference

    std::cout << "arr1 : ";
    Display(arr1);

    std::cout << "arr2 : ";
    Display(arr2);

    arr3 = Merge(&arr1, &arr2);
    std::cout << "Merge : ";
    Display(*arr3);

    arr4 = Union(&arr1, &arr2);
    std::cout << "Union : ";
    Display(*arr4);

    arr5 = Intersection(&arr1, &arr2);
    std::cout << "Intersection : ";
    Display(*arr5);

    arr6 = Difference(&arr1, &arr2);
    std::cout << "Difference : ";
    Display(*arr6);

    return 0;
}