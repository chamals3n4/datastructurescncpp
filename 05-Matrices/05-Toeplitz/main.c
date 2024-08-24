#include <stdio.h>
#include <stdlib.h>

/*
    elements - n+n-1
    case 1 - if i<=j index j-i
    case 2 - if i>j index n+i-j-1
*/

struct Matrix
{
    int *A;
    int n;
};

void Set(struct Matrix *m, int i, int j, int x)
{
    if (i <= j)
        m->A[j - i] = x;
    else
        m->A[m->n + i - j - 1] = x;
}

int Get(struct Matrix *m, int i, int j)
{
    if (i <= j)
        return m->A[j - i];
    else
        return m->A[m->n + i - j - 1];
}

void Display(struct Matrix *m)
{
    int i, j;
    for (i = 1; i <= m->n; i++)
    {
        for (j = 1; j <= m->n; j++)
        {
            if (i <= j)
                printf("%d", m->A[j - i]);
            else if (i > j)
                printf("%d", m->A[m->n + i - j - 1]);
            else
                printf("0");
        }
        printf("\n");
    }
};

int main()
{
    struct Matrix m;
    int i, j, x;
    printf("enter dimension : ");
    scanf("%d", &m.n);

    // no of non-zero elements = n+n-1
    m.A = (int *)malloc((2 * m.n - 1) * sizeof(int));
    printf("enter all elements");
    for (i = 1; i <= m.n; i++)
    {
        for (j = 1; j <= m.n; j++)
        {
            scanf("%d", &x);
            Set(&m, i, j, x);
        }
    }

    Display(&m);

    return 0;
}
