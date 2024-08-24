#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define TRUE 1
#define FALSE 0

struct Node
{
    int data;
    struct Node *next;
} *first;

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

void display(struct Node *p)
{
    while (p != NULL)
    {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

int isSorted(struct Node *p)
{
    int x = INT32_MIN;
    while (p != NULL)
    {
        if (p->data < x)
            return FALSE;
        x = p->data;
        p = p->next;
    }
    return TRUE;
}

// removing duplicates elements from a sorted linked list
void removeDuplicated(struct Node *p)
{
    p = first;
    struct Node *q = first->next;

    while (q != NULL)
    {
        if (p->data != q->data)
        {
            p = q;
            q = q->next;
        }
        else
        {
            p->next = q->next;
            free(q);
            q = p->next;
        }
    }
}

int main()
{
    int A[] = {1, 2, 3, 4, 5};
    create(A, 5);
    display(first);
    isSorted(first);

    if (isSorted(first))
        printf("linked list is sorted\n");
    else
        printf("linked list is not sorted\n");

    printf("-------------------------------\n");

    int D[] = {3, 5, 5, 8, 8, 8};
    create(D, 6);
    display(first);
    removeDuplicated(first);
    display(first);

    return 0;
}
