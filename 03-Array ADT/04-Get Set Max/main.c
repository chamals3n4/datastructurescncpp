// GET SET MAX MIN SUM AVG
#include <stdio.h>

struct Array
{
    int A[10];
    int size;
    int length;
};

int Get(struct Array arr, int index)
{
    if (index >= 0 && index < arr.length)
        return arr.A[index];
    return -1;
}

int Set(struct Array *arr, int index, int key)
{
    if (index >= 0 && index < arr->length)
        arr->A[index] == key;
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

int Sum(struct Array arr)
{
    int sum = 0;
    for (int i = 0; i < arr.length; i++)
        sum += arr.A[i];
    return sum;
}

float Avg(struct Array arr)
{
    return (float)Sum(arr) / arr.length;
}

int main()
{
    struct Array arr = {{10, 20, 30, 40, 50}, 10, 5};
    printf("%d", Get(arr, 2));
    return 0;
}
