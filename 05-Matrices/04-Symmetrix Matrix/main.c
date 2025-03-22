#include <stdio.h>
#include <stdlib.h>

struct Matrix{
    int *A;
    int n;
};

void Set(struct Matrix *m,int i,int j,int x){
    if(i>=j)
        m->A[i*(i-1)/2+j-1]=x;
}

int Get(struct Matrix m,int i,int j){
    if(i>=j)
        return m.A[i*(i-1)/2+j-1];
    else
        return m.A[j*(j-1)/2+i-1];
}

void Display(struct Matrix m){
    for(int i=1;i<=m.n;i++){
        for(int j=1;j<=m.n;j++){
            if(i>=j)
                printf("%d ",m.A[i*(i-1)/2+j-1]);
            else
                printf("%d ",m.A[j*(j-1)/2+i-1]);
        }
        printf("\n");
    }
}

int main(){
    struct Matrix m;
    printf("enter dimension \n");
    scanf("%d",&m.n);
    m.A = (int*)malloc(m.n*(m.n+1)/2*sizeof(int));

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

    printf("GET \n");
    printf("%d ",Get(m, 2, 4));
    printf("%d ",Get(m, 4, 2));

    return 0;
}
