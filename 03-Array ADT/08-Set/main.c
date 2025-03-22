#include <stdio.h>
#include <stdlib.h>

struct Array{
    int A[10];
    int size;
    int length;
};

void display(struct Array arr){
    for(int i=0;i<arr.length;i++)
        printf("%d ",arr.A[i]);
    printf("\n");
}

struct Array * UNION(struct Array *arr1,struct Array *arr2){
    int i,j,k;
    i=j=k=0;
    struct Array *arr3 = (struct Array*)malloc(sizeof(struct Array));
    
    while(i<arr1->length && j<arr2->length){
        if(arr1->A[i]==arr2->A[j]){
            arr3->A[k++]=arr1->A[i++];
            j++;
        }
        else if(arr1->A[i] < arr2->A[j])
            arr3->A[k++]=arr1->A[i++];
        else
            arr3->A[k++]=arr2->A[j++];
    }
    for(;i<arr1->length;i++)
        arr3->A[k++]=arr1->A[i];
    for(;j<arr2->length;j++)
        arr3->A[k++]=arr2->A[j];

    arr3->length = k;
    arr3->size = 10;

    return arr3;
}

struct Array * Intersection (struct Array *arr1,struct Array *arr2){
    int i,j,k;
    i=j=k=0;
    struct Array *arr3 = (struct Array *)malloc(sizeof(struct Array));
    
    while (i<arr1->length && j<arr2->length) {
        if(arr1->A[i]<arr2->A[j])
            i++;
        else if(arr2->A[j]<arr1->A[i])
            j++;
        else if(arr1->A[i] == arr2->A[j]){
            arr3->A[k++]=arr1->A[i++];
            j++;
        }
    }
    arr3->length=k;
    arr3->size=10;

    return arr3;
}

struct Array * Difference(struct Array *arr1,struct Array *arr2){
    int i,j,k;
    i=j=k=0;
    struct Array *arr3 = (struct Array *)malloc(sizeof(struct Array));

    while (i<arr1->A[i] && j<arr2->A[j]) {
        if(arr1->A[i]<arr2->A[j]){
            arr3->A[k++]=arr1->A[i++];
        }
        else if(arr2->A[j] < arr1->A[i])
            j++;
        else{
            i++;
            j++;
        }
    }
    for(;i<arr1->A[i];i++)
        arr3->A[k++]=arr1->A[i];

    arr3->length=k;
    arr3->size=10;

    return  arr3;
}

int main(){
    struct Array arr1= {{3,4,5,6,10},10,5};
    struct Array arr2= {{2,4,5,7,12},10,5};
    struct Array *arr3;

    display(arr1);
    display(arr2);

    //arr3 = UNION(&arr1,&arr2);
    //arr3 = Intersection(&arr1,&arr2);
    arr3 = Difference(&arr1,&arr2);
    display(*arr3);

    return 0;
}
