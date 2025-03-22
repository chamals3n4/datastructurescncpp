#include <stdio.h>
#include <stdlib.h>

struct Array{
    int A[100];
    int size;
    int length;
};

void display(struct Array arr){
    for(int i=0;i<arr.length;i++)
        printf("%d ",arr.A[i]);
    printf("\n");
}

int MAX(struct Array arr){
    int max = arr.A[0];
    for(int i=0;i<arr.length;i++){
        if(arr.A[i]>max)
            max=arr.A[i];
    }
    return max;
}

int MIN(struct Array arr){
    int min = arr.A[0];
    for(int i=0;i<arr.length;i++){
        if(arr.A[i]<min)
            min=arr.A[i];
    }
    return min;
}
void findDuplicates(struct Array arr){
    int lastDuplicates = 0;
    for(int i=0;i<arr.length;i++){
        if(arr.A[i]==arr.A[i+1] && arr.A[i]!=lastDuplicates){
            printf("%d\n",arr.A[i]);
            lastDuplicates=arr.A[i];
        }
    }
}

void findDuplicates2(struct Array arr){
    for(int i=0;i<arr.length;i++){
        if(arr.A[i]==arr.A[i+1]){
            int j=i+1;
            while(arr.A[j]==arr.A[i])j++;
            printf("%d is appearing %d times\n",arr.A[i],j-i);
            i=j-1;
        }
    }
}

//using HASHING
void findDuplicatesUsingHash(struct Array arr){
    int l=MIN(arr);
    int h=MAX(arr);
    
    // Automatically initializes to 0
    int *H = (int *)calloc(h, sizeof(int)); // this is called HASH TABLE

    for (int i = 0; i < arr.length; i++){
        H[arr.A[i]]++;
    }

    for(int i=0;i<=h;i++){
        if(H[i]>1)
            printf("%d is appearing %d times",i,H[i]);
    }
}

//unsorted array




int main(){
    struct Array arr={{3,6,8,8,10,12,7,15,15,15},15,10};
    struct Array arr1={{8,3,6,4,6,5,8,7,7},15,9};

    display(arr);
    findDuplicates(arr);
    printf("---------------------------------------\n");
    findDuplicates2(arr);
    printf("---------------------------------------\n");
    findDuplicatesUsingHash(arr1);
    return 0;
}
