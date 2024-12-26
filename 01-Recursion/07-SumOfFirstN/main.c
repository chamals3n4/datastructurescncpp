#include <stdio.h>

int fun1(int n){
    return n*(n+1)/2;
}

int fun2(int n){
    int s = 0;
    for(int i=1;i<=n;i++){
        s+=i;
    }
    return s;
}

int fun3(int n){
    if(n==0)
        return 0;
    else
        return fun3(n-1)+n;
}


int main(){
    printf("%d ",fun1(5));
    printf("%d ",fun2(5));
    printf("%d ",fun3(5));
    return 0;
}