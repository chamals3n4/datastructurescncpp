#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct Node
{
    int coeff;
    int exp;
    struct Node *next;
} *poly = NULL;

void create()
{
    struct Node *t = NULL, *last = NULL;
    int num;

    printf("enter number of terms : ");
    scanf("%d", &num);

    printf("enter each term with coeff and expo");
    for (int i = 0; i < num; i++)
    {
        t = (struct Node *)malloc(sizeof(struct Node));

        scanf("%d %d", &t->coeff, &t->exp);
        if (poly == NULL)
        {
            poly = last = t;
        }
        else
        {
            last->next = t;
            last = t;
        }
    }
}

void Display(struct Node *p)
{
    while (p)
    {
        printf("%dx%d", p->coeff, p->exp);
        p = p->next;
    }
    printf("\n");
}

long Eval(struct Node *p, int x)
{
    long val = 0;
    while (p)
    {
        val += p->coeff * (long)pow(x, p->exp);
        p = p->next;
    }
    return val;
}

int main()
{
    create();
    Display(poly);
    printf("%ld\n", Eval(poly, 1));

    return 0;
}