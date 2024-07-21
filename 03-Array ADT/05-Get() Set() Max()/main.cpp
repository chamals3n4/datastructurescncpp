#include <iostream>

struct Array
{
    int A[10];
    int size;
    int length;
};

void Display(struct Array arr)
{
    for (int i = 0; i < arr.length; i++)
    {
        std::cout << arr.A[i] << " ";
    }
    std::cout << std::endl;
}

int Get(struct Array arr, int index)
{
    if (index >= 0 && index < arr.length)
        return arr.A[index];
    return -1;
}

void Set(struct Array *arr, int index, int x)
{
    if (index >= 0 && index < arr->length)
    {
        arr->A[index] = x;
    }
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

int iSum(struct Array arr)
{
    int total = 0;
    for (int i = 0; i < arr.length; i++)
    {
        total += arr.A[i];
    }
    return total;
}

int rSum(struct Array arr, int n)
{
    if (n < 0)
        return 0;
    return rSum(arr, n - 1) + arr.A[n];
}

float Avg(struct Array arr)
{
    return (float)iSum(arr) / arr.length;
}
int main()
{
    struct Array arr = {{2, 3, 4, 5, 6}, 10, 5};
    Display(arr);

    std::cout << "Get index 2: " << Get(arr, 2) << std::endl;
    Set(&arr, 2, 50);
    Display(arr);
    std::cout << "Max: " << Max(arr) << std::endl;
    std::cout << "Min: " << Min(arr) << std::endl;
    std::cout << "Iterative Sum: " << iSum(arr) << std::endl;
    std::cout << "Recursive Sum: " << rSum(arr, arr.length - 1) << std::endl;
    std::cout << "Average: " << Avg(arr) << std::endl;

    return 0;
}
