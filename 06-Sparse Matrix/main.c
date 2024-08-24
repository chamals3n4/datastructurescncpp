#include <stdio.h>
#include <stdlib.h>

struct Element
{
    int i; // row
    int j; // column
    int x; // index
};

struct Sparse
{
    // m*n dimension
    int m;
    int n;

    // num of elements
    int num;
    struct Element *e;
};

void Create(struct Sparse *s)
{
    printf("enter dimension - ");
    scanf("%d %d", &s->m, &s->n);
    printf("enter num of non zeros");
    scanf("%d", &s->num);

    s->e = (struct Element *)malloc(s->num * sizeof(struct Element));
    printf("enter all elements");
    int i;
    for (i = 0; i < s->num; i++)
    {
        scanf("%d %d %d", &s->e[i].i, &s->e[i].j, &s->e[i].x);
    }
}

void Display(struct Sparse s)
{
    int i, j, k = 0;
    for (i = 1; i <= s.m; i++)
    {
        for (j = 1; j <= s.n; j++)
        {
            if (i == s.e[k].i && j == s.e[k].j)
                printf("%d ", s.e[k++].x);
            else
                printf("0 ");
        }
        printf("\n");
    }
}

struct Sparse *Add(struct Sparse *s1, struct Sparse *s2)
{
    int i, j, k;
    i = j = k = 0;
    struct Sparse *sum;
    sum = (struct Sparse *)malloc(sizeof(struct Sparse));
    sum->e = (struct Element *)malloc((s1->num + s2->num) * sizeof(struct Element));

    while (i < s1->num && j < s2->num)
    {
        if (s1->e[i].i < s2->e[j].i)
            sum->e[k++] = s1->e[i++];
        else if (s1->e[i].i > s2->e[j].i)
            sum->e[k++] = s2->e[j++];
        else
        {
            if (s1->e[i].j < s2->e[j].j)
                sum->e[k++] = s1->e[i++];
            else if (s1->e[i].j > s2->e[j].j)
                sum->e[k++] = s2->e[j++];
            else
            {
                sum->e[k] = s1->e[i];
                sum->e[k++].x = s1->e[i++].x + s2->e[j++].x;
            }
        }
    }
    for (; i < s1->num; i++)
        sum->e[k++] = s1->e[i];
    for (; j < s2->num; j++)
        sum->e[k++] = s2->e[j];

    sum->m = s1->m;
    sum->n = s2->n;
    sum->num = k;

    return sum;
}

int main()
{
    struct Sparse s1, s2, *s3;
    Create(&s1);
    Create(&s2);

    s3 = Add(&s1, &s2);
    printf("-------------------------\n");
    printf("first matrix(s1)\n");
    Display(s1);
    printf("-------------------------\n\n");
    printf("second matrix(s2)\n");
    Display(s2);
    printf("-------------------------\n\n");
    printf("sum of s1 and s2 matrices(s3)\n");
    Display(*s3);
    printf("-------------------------\n");

    return 0;
}

// Kalana Muthumuni