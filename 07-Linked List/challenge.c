#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
} *first = NULL;

void create(int A[], int n)
{
    struct Node *t, *last;
    first = (struct Node *)malloc(sizeof(struct Node));
    first->data = A[0];
    first->next = NULL;
    last = first;
    for (int i = 1; i < n; i++)
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
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

// 01.Finding Middle Element of a Linked List
void FindMiddle(struct Node *p)
{
    struct Node *q = first;
    while (q)
    {
        q = q->next;
        if (q)
            q = q->next;
        if (q)
            p = p->next;
    }
    printf("%d ", p->data);
}

int main()
{
    int A[] = {10, 20, 30, 40, 50, 60, 70};
    create(A, 7);
    FindMiddle(first);

    return 0;
}