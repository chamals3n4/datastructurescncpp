#include <stdio.h>
#include <stdlib.h>
#include <iostream>
struct Node
{
    int data;
    struct Node *next;
} *first;

void create(int A[], int n)
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

void display(struct Node *p)
{
    while (p != NULL)
    {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

int count(struct Node *p)
{
    int l = 0;
    while (p)
    {
        l++;
        p = p->next;
    }
    return l;
}

void insert(struct Node *p, int index, int x)
{
    int i;
    struct Node *t;
    if (index < 0 || index > count(p))
        return;
    t = (struct Node *)malloc(sizeof(struct Node));
    t->data = x;
    if (index == 0)
    {
        t->next = first;
        first = t;
    }
    else
    {
        for (i = 0; i < index - 1; i++)
            p = p->next;
        t->next = p->next;
        p->next = t;
    }
}

// creating linked list by inserting at last
void insertLast(int x)
{
    struct Node *t, *last;
    t = (struct Node *)malloc(sizeof(struct Node));
    t->data = x;
    t->next = NULL;

    if (first == NULL)
        first = last = t;
    last->next = t;
    last = t;
}

void SortedInsert(struct Node *p, int x)
{
    struct Node *t, *q = NULL;
    t = (struct Node *)malloc(sizeof(struct Node));
    t->data = x;
    t->next = NULL;

    if (first == NULL)
        first = t;
    else
    {
        while (p && p->data < x)
        {
            q = p;
            p = p->next;
        }
        if (p == first)
        {
            t->next = first;
            first = t;
        }
        else
        {
            t->next = q->next;
            q->next = t;
        }
    }
}

int main()
{
    int A[] = {8, 3, 9, 7, 6};
    create(A, 5);
    display(first);
    insert(first, 4, 10);
    display(first);

    // even using insert function we can create a linked list

    // for (int i = 0; i < 6; i++)
    // {
    //     insert(first, i, (i + 1));
    // }

    // for (int i = 0; i < 3; i++)
    // {
    //     insertLast(A[i]);
    // }
    // display(first);

    // SortedInsert(first, 35);
    // display(first);

    return 0;
}
