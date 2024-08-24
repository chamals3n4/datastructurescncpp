#include <stdio.h>
#include <stdlib.h>

struct Matrix
{
    int *A;
    int n;
};

void Set(struct Matrix *m, int i, int j, int x)
{
    if (i <= j)
        // m->A[m->n * (i - 1) - ((i - 2) * (i - 1) / 2) + (j - 1)] = x;
        m->A[j * (j - 1) / 2 + i - 1] = x;
}

int Get(struct Matrix m, int i, int j)
{
    if (i <= j)
        // return m.A[m.n * (i - 1) - ((i - 2) * (i - 1) / 2) + (j - 1)];
        return m.A[j * (j - 1) / 2 + i - 1];
    else
        return 0;
}

void Display(struct Matrix m)
{
    int i, j;
    for (i = 1; i <= m.n; i++)
    {
        for (j = 1; j <= m.n; j++)
        {
            if (i <= j)
                // row major formula
                // printf("%d ", m.A[m.n * (i - 1) - ((i - 2) * (i - 1) / 2) + (j - 1)]);
                printf("%d ", m.A[j * (j - 1) / 2 + i - 1]);
            else
                printf("0 ");
        }
        printf("\n");
    }
}

int main()
{
    struct Matrix m;
    printf("enter dimension : ");
    scanf("%d", &m.n);

    // allocating mememory for no of non-zero elements[ n*(n-1)/2 ]
    m.A = (int *)malloc(m.n * (m.n + 1) / 2 * sizeof(int));
    printf("enter all elements");
    int i, j, x;
    for (i = 1; i <= m.n; i++)
    {
        for (j = 1; j <= m.n; j++)
        {
            scanf("%d", &x);
            Set(&m, i, j, x);
        }
    }
    printf("\n\n");
    Display(m);
    return 0;
}