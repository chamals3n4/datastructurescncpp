#include <stdio.h>
#include <stdlib.h>

struct Array
{
    int A[10];
    int size;
    int length;
};

void display(struct Array arr)
{
    for (int i = 0; i < arr.length; i++)
        printf("%d ", arr.A[i]);

    printf("\n");
}

void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

void reverse(struct Array *arr)
{
    int *B;
    int i, j;
    B = (int *)malloc(arr->length * sizeof(int));
    for (i = arr->length - 1, j = 0; i >= 0; i--, j++)
    {
        B[j] = arr->A[i];
    }
    for (int i = 0; i < arr->length; i++)
        arr->A[i] = B[i];
}

void reverseswap(struct Array *arr)
{
    int i, j;

    for (i = 0, j = arr->length - 1; i >= 0; i--, j++)
    {
        swap(&arr->A[i], &arr->A[j]);
    }
}

// HOME WORK-1
void leftshift(struct Array *arr){
    for(int i=0;i<arr->length;i++){
        arr->A[i]=arr->A[i+1];
    }
    arr->A[arr->length-1]=0;
}

// HOME WORK-2
void leftrotate(struct Array *arr){
    int e = arr->A[0];
    for(int i=0;i<arr->length;i++){
        arr->A[i]=arr->A[i+1];
    }
    arr->A[arr->length-1]=e;
}

int main()
{
    struct Array arr = {{10, 20, 30, 40, 50}, 10, 5};
    struct Array arr1 = {{22, 33, 44, 55, 66}, 10, 5};

    display(arr);
    leftshift(&arr);
    //reverseswap(&arr);
    // reverse(&arr);
    display(arr);
    leftshift(&arr);
    display(arr);
    leftshift(&arr);
    display(arr);
    leftshift(&arr);


    printf("left rotate\n");
    display(arr1);
    leftrotate(&arr1);
    display(arr1);
    return 0;
}
