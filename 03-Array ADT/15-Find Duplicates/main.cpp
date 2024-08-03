#include <iostream>
#include <stdio.h>
#include <stdlib.h>

struct Array
{
    int A[20];
    int size;
    int length;
};

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

void FindDuplicatesSorted(struct Array arr)
{
    int lastDuplicate = 0;
    int i;
    std::cout << "Duplicates elements are : " << std::endl;
    for (i = 0; i < arr.length; i++)
    {
        if (arr.A[i] == arr.A[i + 1] && arr.A[i] != lastDuplicate)
        {
            std::cout << arr.A[i] << std::endl;
            lastDuplicate = arr.A[i];
        }
    }
}

void FindDuplicateCounts(struct Array arr)
{
    int i;
    for (i = 0; i < arr.length - 1; i++)
    {
        if (arr.A[i] == arr.A[i + 1])
        {
            int j = i + 1;
            while (arr.A[j] == arr.A[i])
                j++;
            std::cout << arr.A[i] << " is appearing - " << j - i << " times" << std::endl;
            ;
            i = j - 1;
        }
    }
}

void FindDuplicatedHashing(struct Array arr)
{
    int max = Max(arr);
    int min = Min(arr);
    int hash[max + 1] = {0};

    std::cout << "missing elements are ";
    int i;
    for (i = 0; i < arr.length; i++)
    {
        hash[arr.A[i]]++;
    }

    for (i = min; i < max + 1; i++)
    {
        if (hash[i] > 1)
        {
            std::cout << i << " - " << hash[i] << std::endl;
        }
    }
    // O(n)
}

void FindDuplicatesUnsorted(struct Array arr)
{
    int i;
    std::cout << "missing elements are ";
    for (i = 0; i < arr.length - 1; i++)
    {
        int count = 1;
        if (arr.A[i] != -1)
        {
            for (int j = i + 1; j < arr.length; j++)
            {
                if (arr.A[i] == arr.A[j])
                {
                    count++;
                    arr.A[j] = -1;
                }
            }
            if (count > 1)
            {
                std::cout << arr.A[i] << " - " << count << std::endl;
            }
        }
    }
}

void DuplicatedUnsortedHashing(struct Array arr)
{
    int max = Max(arr);
    int min = Min(arr);
    int hash[max + 1] = {0};

    std::cout << "missing elements are ";
    int i;
    for (i = 0; i < arr.length; i++)
    {
        hash[arr.A[i]]++;
    }
    for (i = min; i < max + 1; i++)
    {
        if (hash[i] > 1)
        {
            std::cout << i << " - " << hash[i] << std::endl;
        }
    }
}

int main()
{
    struct Array arr1 = {{3, 6, 8, 8, 10, 12, 15, 15, 15, 20}, 15, 10};
    struct Array arr2 = {{8, 3, 6, 4, 6, 5, 6, 8, 2, 7}, 15, 10};
    FindDuplicatesSorted(arr1);
    FindDuplicateCounts(arr1);
    FindDuplicatedHashing(arr1);
    FindDuplicatesUnsorted(arr2);
    DuplicatedUnsortedHashing(arr2);

    return 0;
}