#include <stdio.h>

struct Array{
    int A[100];
    int size;
    int length;
};

int main(){
    struct Array arr = {{5,8,3,4,6,2,10,7,-1,4},15,10};
    int min = arr.A[0];
    int max = arr.A[0];

    for(int i=0; i<arr.length; i++){
        if(arr.A[i] < min)
            min=arr.A[i];
        else if(arr.A[i] > max)
            max=arr.A[i];
    }
    printf("MAX - %d\n",max);
    printf("MIN - %d\n",min);

    return 0;
}
