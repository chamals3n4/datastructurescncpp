// Student Challenge

#include <stdio.h>
#include <stdlib.h>
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
    {
        std::cout << arr.A[i] << " ";
    }
    std::cout << std::endl;
}

int Sum(struct Array arr)
{
    int s = 0;
    int i;
    for (i = 0; i < arr.length; i++)
    {
        s += arr.A[i];
    }
    return s;
}

int Max(struct Array arr)
{
    int max = arr.A[0];
    for (int i = 1; i < arr.length; i++)
    {
        if (arr.A[i] > max)
            max = arr.A[i];
    }
    return max;
}

int Min(struct Array arr)
{
    int min = arr.A[0];
    for (int i = 1; i < arr.length; i++)
    {
        if (arr.A[i] < min)
            min = arr.A[i];
    }
    return min;
}

// when the elements are first and natural numbers
int findMissingSorted(struct Array arr)
{
    int n = arr.A[arr.length - 1];
    int ncr = n * (n + 1) / 2;

    int sum = Sum(arr);

    return ncr - sum;
}

// when the elements are not first and natural numbers
void findMissingSortedNonNatural(struct Array arr)
{
    int l = arr.A[0];
    int n = arr.length;
    int diff = l - 0;
    int i;
    for (i = 0; i < n; i++)
    {
        if (arr.A[i] - i != diff)
        {
            std::cout << "missing element is : " << diff + i << std::endl;
            break;
        }
    }
}

// multiple missing elements
void multipleMissingElements(struct Array arr)
{
    int l = arr.A[0];
    int n = arr.length;
    int diff = l - 0;
    int i;

    std::cout << "missing elements are : ";

    for (i = 0; i < n; i++)
    {
        if (arr.A[i] - i != diff)
        {
            while (diff < arr.A[i] - i)
            {
                std::cout << i + diff << " ";
                diff++;
            }
        }
    }
    std::cout << std::endl;
}

// missing elements in unsorted array
void missingElementsUnsorted(struct Array arr)
{
    int max = Max(arr);
    int min = Min(arr);
    int hash[arr.size + 5] = {0};

    int i;
    for (i = 0; i < arr.length; i++)
    {
        hash[arr.A[i]]++;
    }

    // print missing elements
    std::cout << "missing elements are : ";
    for (i = min; i <= max; i++)
    {
        if (hash[i] == 0)
        {
            std::cout << i << " ";
        }
    }
    std::cout << std::endl;
}

int main()
{

    struct Array arr1 = {{1, 2, 3, 4, 5, 6, 8, 9, 10, 11, 12}, 15, 11};
    std::cout << "missing element : " << findMissingSorted(arr1) << std::endl;

    struct Array arr2 = {{6, 7, 8, 9, 10, 11, 13, 14, 15, 16, 14}, 15, 11};
    findMissingSortedNonNatural(arr2);

    struct Array arr3 = {{6, 7, 8, 9, 11, 12, 15, 16, 17, 18, 19}, 15, 11};
    multipleMissingElements(arr3);

    struct Array arr4 = {{3, 7, 4, 9, 12, 6, 11, 2, 10}, 20, 9};
    missingElementsUnsorted(arr4);

    return 0;
}