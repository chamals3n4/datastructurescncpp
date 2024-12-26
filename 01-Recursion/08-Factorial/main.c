#include <stdio.h>

int fun(int n){
    if(n==0)
        return 1;
    else
        return fun(n-1)*n;
}

int fun1(int n){
    int f=1;
    for(int i=1;i<=n;i++)
        f=f*i;
    return f;
}


int main(){
    printf("%d ",fun(5));
    printf("%d ",fun1(5));
    return 0;
}