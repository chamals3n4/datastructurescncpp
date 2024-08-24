#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

struct Node
{
    int data;

    // self referential pointer AKA aliya hodawela meme eka
    struct Node *next;
} *first = NULL;

void Create(int A[], int n)
{
    int i;
    struct Node *t, *last;
    first = (struct Node *)malloc(sizeof(struct Node));
    first->data = A[0];
    first->next = NULL;
    last = first;

    for (i = 1; i < n; i++)
    {
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = A[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
}

void Display(struct Node *p)
{
    while (p != NULL)
    {
        printf("%d", p->data);
        p = p->next;
    }
    printf("\n");
}
void DisplayR(struct Node *p)
{
    if (p != NULL)
    {
        printf("%d", p->data);
        Display(p->next);
    }
    printf("\n");
}

int count(struct Node *p)
{
    int c = 0;
    while (p)
    {
        c++;
        p = p->next;
    }
    return c;
}

int countR(struct Node *p)
{
    if (p == 0)
        return 0;
    else
        return countR(p->next) + 1;
}

int sum(struct Node *p)
{
    int sum = 0;
    while (p)
    {
        sum = sum + p->data;
        p = p->next;
    }
    return sum;
}

int sumR(struct Node *p)
{
    if (p == 0)
        return 0;
    else
        return sumR(p->next) + p->data;
}

int Max(struct Node *p)
{
    int max = INT32_MIN;
    while (p)
    {
        if (p->data > max)
            max = p->data;
        p = p->next;
    }
    return max;
}

int MaxR(struct Node *p)
{
    int x = 0;
    if (p == 0)
        return INT32_MIN;

    x = MaxR(p->next);
    if (x > p->data)
        return x;
    else
        return p->data;
}

int main()
{
    int A[] = {3, 5, 7, 10, 15};
    Create(A, 5);
    Display(first);
    DisplayR(first);

    printf("length is %d\n", countR(first));

    printf("sum is %d\n", sumR(first));

    printf("max is %d\n", MaxR(first));
    return 0;
}