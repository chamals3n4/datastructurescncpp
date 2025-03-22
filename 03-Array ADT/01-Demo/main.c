#include <stdio.h>
#include <stdlib.h>

struct Array
{
    int *A;
    int size;
    int length;
};

void display(struct Array arr)
{
    printf("Elements are\n");
    for (int i = 0; i < arr.length; i++)
        printf("%d ", arr.A[i]);
}

int main()
{
    struct Array arr;
    printf("Enter size of the array : ");
    scanf("%d", &arr.size);
    arr.A = (int *)malloc(arr.size * sizeof(int));
    arr.length = 0;
    int n;

    printf("Enter number of elements");
    scanf("%d", &n);

    printf("Enter all numbers : ");
    for (int i = 0; i < n; i++)
        scanf("%d", &arr.A[i]);
    arr.length = n;
    printf("\n");
    display(arr);

    return 0;
}