#include <stdio.h>
#include <stdlib.h>

struct Array{
    int A[100];
    int size;
    int length;
};

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

void findPairOfElementSumK(struct Array arr,int k){
    for(int i=0;i<arr.length-1;i++){
        for(int j=i+1;j<arr.length;j++){
            if(arr.A[i]+arr.A[j]==k){
                printf("%d + %d = %d\n",arr.A[i],arr.A[j],k);
            }
        }
    }
}

void findPaidOfElementSUmKbyHash(struct Array arr,int k){
    int h=MAX(arr);
    int *H = (int *)calloc(h, sizeof(int));
    for(int i=0;i<arr.length;i++){
        if( H[k-arr.A[i]] != 0){
            printf("%d +  %d = %d",arr.A[i],k-arr.A[i],k);
        }
        H[arr.A[i]]++;
    }
}

// SORTED ARRAY
void findParOfElementSumKSOrted(struct Array arr,int k){
    int i=0;
    int j=arr.length-1;
    while (i<j) {
        if(arr.A[i]+arr.A[j]==k){
            printf("%d + %d = %d\n",arr.A[i],arr.A[j],k);
            i++;
            j--;
        }
        else if(arr.A[i]+arr.A[j] < k)
            i++;
        else
            j--;
    }
}

int main(){
    struct Array arr = {{6,7,8,10,4,7,5,2,9,5},15,10};
    struct Array arr1 = {{1,3,4,5,6,8,9,10,12,14},15,10};
    findPairOfElementSumK(arr,10);
    printf("-------------------------------------\n");
    //findPaidOfElementSUmKbyHash(arr,10);
    printf("--------------------------------------\n");
    findParOfElementSumKSOrted(arr1, 10);
    return 0;
}
