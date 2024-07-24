#include <stdio.h>
#include <stdlib.h>
#include <iostream>

class Array
{
private:
    int *A;
    int size;
    int length;
    void Swap(int *x, int *y);

public:
    Array()
    {
        size = 10;
        length = 0;
        A = new int[size];
    }
    Array(int sz)
    {
        size = sz;
        length = 0;
        A = new int[size];
    }
    ~Array()
    {
        delete[] A;
    }

    void Display();
    void Append(int x);
    void Insert(int index, int x);
    int Delete(int index);

    int LinearSearch(int key);
    int BinarySearch(int key);
    // int rBinSearch(int a[], int l, int h, int key);
    int Get(int index);
    void Set(int index, int x);
    int Max();
    int Min();
    int Sum();
    float Avg();
    void Reverse();
    void swapReverse();
    void InsertSort(int x);
    void Rearrange();
    struct Array *Merge(Array arr2);
    struct Array *Union(Array arr2);
    struct Array *Intersection(Array arr2);
    struct Array *Difference(Array arr2);
};
void Array::Display()
{
    int i;
    printf("\nElements are : ");
    for (i = 0; i < length; i++)
        printf("%d ", A[i]);
    printf("\n");
}

void Array::Append(int x)
{
    if (length < size)
        A[length++] = x;
}

void Array::Insert(int index, int x)
{
    int i;
    if (index >= 0 && index <= length)
    {
        for (i = length; i > index; i--)
            A[i] = A[i - 1];
        A[index] = x;
        length++;
    }
}

int Array::Delete(int index)
{
    int x = 0;
    int i;

    if (index >= 0 && index < length)
    {
        x = A[index];
        for (i = index; i < length - 1; i++)
            A[i] = A[i + 1];
        length--;
        return x;
    }

    return 0;
}

void Array::Swap(int *x, int *y)
{
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

// MovetoHead
int Array::LinearSearch(int key)
{
    int i;
    for (i = 0; i < length; i++)
    {
        if (key == A[i])
        {
            Swap(&A[i], &A[0]);
            return i;
        }
    }
    return -1;
}

int Array::BinarySearch(int key)
{
    int l, mid, h;
    l = 0;
    h = length - 1;

    while (l <= h)
    {
        mid = (l + h) / 2;
        if (key == A[mid])
            return mid;
        else if (key < A[mid])
            h = mid - 1;
        else
            l = mid + 1;
    }
    return -1;
}

// int rBinSearch(int a[], int l, int h, int key)
// {
//     int mid;
//     if (l <= h)
//     {
//         mid = (l + h) / 2;
//         if (key == a[mid])
//             return mid;
//         else if (key < a[mid])
//             return rBinSearch(a, l, mid - 1, key);
//         else
//             return rBinSearch(a, mid + 1, h, key);
//     }
//     return -1;
// }

int Array::Get(int index)
{
    if (index >= 0 && index < length)
        return A[index];
    return -1;
}

void Array::Set(int index, int x)
{
    if (index >= 0 && index < length)
        A[index] = x;
}

int Array::Max()
{
    int max = A[0];
    int i;
    for (i = 1; i < length; i++)
    {
        if (A[i] > max)
            max = A[i];
    }
    return max;
}

int Array::Min()
{
    int min = A[0];
    int i;
    for (i = 0; i < length; i++)
    {
        if (A[i] < min)
            min = A[i];
    }
    return min;
}

int Array::Sum()
{
    int s = 0;
    int i;
    for (i = 0; i < length; i++)
        s += A[i];

    return s;
}

float Array::Avg()
{
    return (float)Sum() / length;
}

void Array::Reverse()
{
    int *B;
    int i, j;

    // B = (int *)malloc(length * sizeof(int));
    B = new int[length];

    for (i = length - 1, j = 0; i >= 0; i--, j++)
        B[j] = A[i];
    for (i = 0; i < length; i++)
        A[i] = B[i];
}

void Array::swapReverse()
{
    int i, j;
    for (i = 0, j = length - 1; i < j; i++, j--)
        Swap(&A[i], &A[j]);
}

void Array::InsertSort(int x)
{
    int i = length - 1;
    if (length == size)
        return;
    while (i >= 0 && A[i] > x)
    {
        A[i + 1] = A[i];
        i--;
    }
    A[i + 1] = x;
    length++;
}

void Array::Rearrange()
{
    int i, j;
    i = 0;
    j = length - 1;

    while (i < j)
    {
        while (A[i] < 0)
            i++;
        while (A[j] >= 0)
            j--;
        if (i < j)
            Swap(&A[i], &A[j]);
    }
}

Array *Array::Merge(Array arr2)
{
    int i, j, k;

    // Array *arr3 = (struct Array *)malloc(sizeof(struct Array));
    Array *arr3 = new Array[length + arr2.length];

    while (i < length && j < arr2.length)
    {
        if (A[i] < arr2.A[i])
            arr3->A[k++] = A[i++];
        else
            arr3->A[k++] = arr2.A[j++];
    }
    for (; i < length; i++)
        arr3->A[k++] = A[i];
    for (; i < length; i++)
        arr3->A[k++] = A[i];

    arr3->length = length + arr2.length;
    arr3->size = 10;

    return arr3;
}

Array *Array::Union(Array arr2)
{
    int i, j, k;

    Array *arr4 = new Array[length + arr2.length];
    while (i < length && j < arr2.length)
    {
        if (A[i] < arr2.A[i])
            arr4->A[k++] = A[i++];
        else if (arr2.A[j] < A[i])
            arr4->A[k++] = arr2.A[j++];
        else
        {
            arr4->A[k++] = A[i++];
            j++;
        }
    }
    for (; i < length; i++)
        arr4->A[k++] = A[i];
    for (; i < length; i++)
        arr4->A[k++] = A[i];

    arr4->length = k;
    arr4->size = 10;

    return arr4;
}

Array *Array::Intersection(Array arr2)
{
    int i, j, k;

    Array *arr5 = new Array[length + arr2.length];
    while (i < length && j < arr2.length)
    {
        if (A[i] < arr2.A[i])
            i++;
        else if (arr2.A[j] < A[i])
            j++;
        else if (A[i] == arr2.A[j])
        {
            arr5->A[k++] = A[i++];
            j++;
        }
    }

    arr5->length = k;
    arr5->size = 10;

    return arr5;
}

// (A-B)
Array *Array::Difference(Array arr2)
{
    int i, j, k;
    i = j = k = 0;

    Array *arr6 = new Array[length + arr2.length];
    while (i < length && j < arr2.length)
    {
        if (A[i] < arr2.A[i])
            arr6->A[k++] = A[i++];
        else if (arr2.A[j] < A[i++])
            j++;
        else
        {
            i++;
            j++;
        }
    }
    for (; i < length; i++)
        arr6->A[k++] = A[i];

    arr6->length = k;
    arr6->size = 10;

    return arr6;
}

int main()
{
    Array *arr1;
    int ch, sz;
    int x;
    int index;

    std::cout << "Enter size of the Array :";

    std::cin >> sz;

    arr1 = new Array(sz);

    do
    {

        std::cout << "Menu" << std::endl;
        std::cout << "1. Insert<< std::endl;" << std::endl;
        std::cout << "2. Delete" << std::endl;
        std::cout << "3. Search" << std::endl;
        std::cout << "4. Sum" << std::endl;
        std::cout << "5. Display" << std::endl;
        std::cout << "6. Exit" << std::endl;

        std::cout << "Enter your choice : " << std::endl;
        std::cin >> ch;

        switch (ch)
        {
        case 1:
            std::cout << "Enter Element :";
            std::cin >> x;
            std::cout << "Enter Index";
            std::cin >> index;
            arr1->Insert(index, x);
            break;
        case 2:
            std::cout << "Enter Index";
            std::cin >> index;
            x = arr1->Delete(index);
            std::cout << "Deleted Element is : " << x << std::endl;
            break;
        case 3:
            std::cout << "Enter Element to Search";
            std::cin >> x;
            index = arr1->LinearSearch(x);
            std::cout << "Element index : " << index << std::endl;
            break;
        case 4:
            std::cout << "Sum is" << arr1->Sum() << std::endl;
            break;
        case 5:
            arr1->Display();
        }
    } while (ch < 6);

    return 0;
}