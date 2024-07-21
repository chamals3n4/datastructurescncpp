#include <stdio.h>
#include <stdlib.h>
#include <iostream>

struct Array
{
    int *A;
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

int main()
{

    struct Array arr;
    int n, i;

    // printf("Enter size of an array");
    // scanf("%d", &arr.size);
    // arr.A = (int *)malloc(arr.size * sizeof(int));
    // arr.length = 0;

    std::cout << "Enter size of an array" << std::endl;
    std::cin >> arr.size;
    arr.A = new int[arr.size];
    arr.length = 0;

    std::cout << "Enter number of elements" << std::endl;
    std::cin >> n;

    std::cout << "Enter all the elements" << std::endl;
    for (i = 0; i < n; i++)
    {
        std::cin >> arr.A[i];
    }
    arr.length = n;

    Display(arr);

    return 0;
}