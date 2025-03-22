#include <stdio.h>
#include <stdlib.h>

struct Matrix{
    int *A;
    int n;
};

void Set(struct Matrix *m,int i,int j,int x){
    if(i<=j)
        m->A[(i-1)-((i-2)*(i-1))/2+(j-1)]=x;
}

int Get(struct Matrix m,int i,int j){
    if(i<=j)
        return m.A[(i-1)-((i-2)*(i-1))/2+(j-1)];
    else
        return 0;
}

void Display(struct Matrix m){
    for(int i=1;i<=m.n;i++){
        for(int j=1;j<=m.n;j++){
            if(i<=j)
                printf("%d ",m.A[(i-1)-((i-2)*(i-1))/2+(j-1)]);
            else
                printf("0 ");
        }
        printf("\n");
    }
}

int main(){
    struct Matrix m;
    printf("enter dimension \n");
    scanf("%d",&m.n);
    m.A = (int*)malloc(m.n*(m.n+1)/2*sizeof(int));
    Set(&m, 1, 1, 1);
    Set(&m, 1, 2, 2);
    Set(&m, 1, 3, 3);
    Set(&m, 2, 2, 4);
    Set(&m, 2, 3, 5);
    Set(&m, 3, 3, 6);

    printf("enter elements\n");
    int x;
    
    for(int i=1;i<=m.n;i++){
        for(int j=1;j<=m.n;j++){
            scanf("%d",&x);
            Set(&m,i,j,x);
        }
    }

    printf("\n\n");

    Display(m);

    return 0;
}
