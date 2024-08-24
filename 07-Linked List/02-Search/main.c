/*
we cannot performe binary search on linkedlist bcz we cannt diretly goin
to middle of a linked list
soo in linked list use linear search
*/

#include <stdio.h>
#include <stdlib.h>
#include <iostream>

struct Node
{
    int data;
    struct Node *next;
} *first;

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
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

struct Node *Search(struct Node *p, int key)
{
    while (p != NULL)
    {
        if (key == p->data)
            return (p);
        p = p->next;
    }
    return NULL;
}

// improved version of linear search(Move to Head)
struct Node *ImprovedSearch(struct Node *p, int key)
{
    struct Node *q = NULL;
    while (p != NULL)
    {
        if (key == p->data)
        {
            q->next = p->next;
            p->next = first;
            first = p;

            return p;
        }
        q = p;
        p = p->next;
    }
    return NULL;
}

struct Node *RSearch(struct Node *p, int key)
{
    if (p == 0)
        return NULL;
    if (key == p->data)
        return p;
    return RSearch(p->next, key);
}

int main()
{
    int A[] = {3, 5, 7, 10, 15};
    Create(A, 5);
    Display(first);
    struct Node *temp;
    temp = ImprovedSearch(first, 15);
    if (temp)
        printf("key found - %d\n", temp->data);
    else
        printf("key not found\n");

    Display(first);
    return 0;
}