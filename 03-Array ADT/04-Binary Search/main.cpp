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

// Iterative Version
int iBinSearch(struct Array arr, int key)
{
    int l, h, mid;
    l = 0;
    h = arr.length - 1;

    while (l <= h)
    {
        mid = (l + h) / 2;
        if (key == arr.A[mid])
            return mid;
        else if (key < arr.A[mid])
            h = mid - 1;
        else
            l = mid + 1;
    }

    return -1;
}

int rBinSearch(int a[], int l, int h, int key)
{
    int mid;

    if (l <= h)
    {
        mid = (l + h) / 2;
        if (key == a[mid])
            return mid;
        else if (key < a[mid])
            return rBinSearch(a, l, mid - 1, key);
        else
            return rBinSearch(a, mid + 1, h, key);
    }
    return -1;
}

// int rBinSearch(struct Array arr, int l, int h, int key)
// {
//     int mid;

//     if (l <= h)
//     {
//         mid = (l + h) / 2;
//         if (key == arr.A[mid])
//             return mid;
//         else if (key < arr.A[mid])
//             return rBinSearch(arr, l, mid - 1, key);
//         else
//             return rBinSearch(arr, mid + 1, h, key);
//     }
//     return -1;
// }

int main()
{

    struct Array arr = {{2, 3, 4, 5, 6}, 10, 5};

    Display(arr);
    // std::cout << iBinSearch(arr, 5) << std::endl;
    std::cout << rBinSearch(arr.A, 0, arr.length - 1, 5) << std::endl;
    // std::cout << rBinSearch(arr, 0, arr.length - 1, 5) << std::endl;
    Display(arr);

    return 0;
}