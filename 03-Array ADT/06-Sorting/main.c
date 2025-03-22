#include <stdio.h>

struct Array{
    int A[10];
    int size;
    int length;
};

void display(struct Array arr){
    for(int i=0;i<arr.length;i++)
        printf("%d ", arr.A[i]);
    printf("\n");
}

void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

void InsertSorted(struct Array *arr,int key){
    int i = arr->length-1;
    while (arr->A[i]>key) {
        arr->A[i+1]=arr->A[i];
        i--;
    }
    arr->A[i+1]=key;
    arr->length++;
}

void SortNegativenPositive(struct Array *arr){
    int i=0;
    int j=arr->length-1;
    while (i<j) {
        while (arr->A[i]<0) {i++;}
        while (arr->A[j]>0) {j--;}
        if(i<j)
            swap(&arr->A[i], &arr->A[j]);
    }
}


int isSorted(struct Array arr){
    for(int i=0;i<arr.length-1;i++){
        if(arr.A[i]>arr.A[i+1])
            return 0;
    }
    return 1;
}

int main(){
    struct Array arr = {{10,20,30,40,50},10,5};
    struct Array arr1 = {{10,25,22,65,50},10,5};
    struct Array arr2 = {{10,-5,12,65,-3},10,5};
    display(arr);
    InsertSorted(&arr, 25);
    display(arr);
    printf("%d ",isSorted(arr));
    printf("%d ",isSorted(arr1));

    printf("---------------------------------\n");
    display(arr2);
    SortNegativenPositive(&arr2);
    display(arr2);

    return 0;
}
