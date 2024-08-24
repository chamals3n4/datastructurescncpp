#include <iostream>

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

void findPairWithSum(struct Array arr, int k)
{
    int i;
    for (i = 0; i < arr.length - 1; i++)
    {
        for (int j = i + 1; j < arr.length; j++)
        {
            if (arr.A[i] + arr.A[j] == 10)
            {
                std::cout << arr.A[i] << " + " << arr.A[j] << " = " << k << std::endl;
            }
        }
    }
}

void findPairWithSumHashing(struct Array arr, int k)
{
    int max = Max(arr);
    int hash[max + 1] = {0};
    std::cout << "missing elements are " << std::endl;
    int i;
    for (i = 0; i < arr.length; i++)
    {
        int complement = k - arr.A[i];
        if (complement >= 0 && complement <= max && hash[complement] != 0)
        {
            std::cout << arr.A[i] << " + " << complement << " = " << k << std::endl;
        }
        hash[arr.A[i]]++;
    }
}

void findPairWithSumSorted(struct Array arr, int k)
{
    int i = 0;
    int j = arr.length - 1;
    while (i < j)
    {
        if (arr.A[i] + arr.A[j] == k)
        {
            std::cout << arr.A[i] << " + " << arr.A[j] << " = " << k << std::endl;
            i++;
            j--;
        }
        else if (arr.A[i] + arr.A[j] < k)
            i++;
        else
            j--;
    }
}

void MinMax(struct Array arr)
{
    int min = arr.A[0];
    int max = arr.A[0];
    int i;
    for (i = 0; i < arr.length; i++)
    {
        if (arr.A[i] < min)
            min = arr.A[i];
        else if (arr.A[i] > max)
            max = arr.A[i];
    }
    std::cout << "Max is : " << max << std::endl;
    std::cout << "Min is : " << min << std::endl;
}

int main()
{
    struct Array arr1 = {{6, 3, 8, 10, 16, 7, 5, 2, 9, 14}, 15, 10};
    findPairWithSum(arr1, 10);
    findPairWithSumHashing(arr1, 10);

    struct Array arr2 = {{1, 3, 4, 5, 6, 8, 9, 10, 12, 14}, 15, 10};
    findPairWithSumSorted(arr2, 10);

    struct Array arr3 = {{5, 8, 3, 9, 6, 2, 10, 7, -1, 4}, 15, 10};
    MinMax(arr3);
    return 0;
}