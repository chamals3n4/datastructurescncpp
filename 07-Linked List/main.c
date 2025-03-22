#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct Node
{
    int data;
    struct Node *next;
} *first = NULL, *second = NULL, *third = NULL;

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

void create2(int A[], int n)
{
    struct Node *t, *last;
    second = (struct Node *)malloc(sizeof(struct Node));
    second->data = A[0];
    second->next = NULL;
    last = second;

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

void RDisplay(struct Node *p)
{
    if (p != NULL)
    {
        printf("%d ", p->data);
        RDisplay(p->next);
    }
}

int count(struct Node *p)
{
    int l = 0;
    while (p != NULL)
    {
        l++;
        p = p->next;
    }
    return l;
}

int RCount(struct Node *p)
{
    if (p == 0)
        return 0;
    else
        return RCount(p->next) + 1;
}

int Sum(struct Node *p)
{
    int s = 0;
    while (p != NULL)
    {
        s += p->data;
        p = p->next;
    }
    return s;
}

int RSum(struct Node *p)
{
    if (p == 0)
        return 0;
    else
        return RSum(p->next) + p->data;
}

int Max(struct Node *p)
{
    int max = INT_MIN;
    while (p != NULL)
    {
        if (p->data > max)
            max = p->data;
        p = p->next;
    }
    return max;
}

int Min(struct Node *p)
{
    int min = INT_MAX;
    while (p != NULL)
    {
        if (p->data < min)
            min = p->data;
        p = p->next;
    }
    return min;
}

struct Node *LinearSearch(struct Node *p, int key)
{
    while (p != NULL)
    {
        if (p->data == key)
            return p;
        p = p->next;
    }
    return NULL;
}

struct Node *RLinearSearch(struct Node *p, int key)
{
    if (p == NULL)
        return NULL;
    if (p->data == key)
        return p;
    else
        return RLinearSearch(p->next, key);
}

struct Node *LinearSearchMovetoHead(struct Node *p, int key)
{
    struct Node *q = NULL;
    while (p != NULL)
    {
        if (p->data == key)
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

void Insert(struct Node *p, int index, int ele)
{
    if (index < 0 || index > count(p))
        return;
    struct Node *t;
    t = (struct Node *)malloc(sizeof(struct Node));
    t->data = ele;
    if (index == 0)
    {
        t->next = first;
        first = t;
    }
    else
    {
        for (int i = 0; i < index - 1; i++)
            p = p->next;
        t->next = p->next;
        p->next = t;
    }
}

void InserLast(int ele)
{
    struct Node *t, *last;
    t = (struct Node *)malloc(sizeof(struct Node));
    t->data = ele;
    t->next = NULL;

    if (first == NULL)
    {
        first = last = t;
    }
    else
    {
        last = first;
        while (last->next)
        {
            last = last->next;
        }
        last->next = t;
        last = t;
    }
}

void SortedInsert(struct Node *p, int ele)
{
    struct Node *t, *q = NULL;

    t = (struct Node *)malloc(sizeof(struct Node));
    t->data = ele;
    t->next = NULL;

    if (first == NULL)
        first = t;
    else
    {
        while (p && p->data < ele)
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

int Delete(struct Node *p, int index)
{
    struct Node *q = NULL;
    int x = -1;
    if (index < 1 || index > count(p))
        return -1;
    if (index == 1)
    {
        q = first;
        x = q->data;
        first = first->next;
        free(q);
        return x;
    }
    else
    {
        for (int i = 0; i < index - 1; i++)
        {
            q = p;
            p = p->next;
        }
        q->next = p->next;
        x = p->data;
        free(p);
        return x;
    }
}

int isSorted(struct Node *p)
{
    int x = INT_MIN;
    while (p != NULL)
    {
        if (p->data < x)
            return 0;
        x = p->data;
        p = p->next;
    }
    return 1;
}

void removeDuplicate(struct Node *p)
{
    struct Node *q = p->next;
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

void ReverseElements(struct Node *p)
{
    int *A, i = 0;
    struct Node *q = first;
    A = (int *)malloc(sizeof(int) * count(p));
    while (q != NULL)
    {
        A[i] = q->data;
        q = q->next;
        i++;
    }
    q = p;
    i--;
    while (q != NULL)
    {
        q->data = A[i];
        q = q->next;
        i--;
    }
}

void ReverseLinks(struct Node *p)
{
    struct Node *q = NULL, *r = NULL;

    while (p != NULL)
    {
        r = q;
        q = p;
        p = p->next;
        q->next = r;
    }
    first = q;
}

void RecursiveReverse(struct Node *q, struct Node *p)
{
    if (p)
    {
        RecursiveReverse(p, p->next);
        p->next = q;
    }
    else
        first = q;
}

void Concat(struct Node *p, struct Node *q)
{
    third = p;
    while (p->next != NULL)
        p = p->next;
    p->next = q;
}

void Merge(struct Node *p, struct Node *q)
{
    struct Node *last;
    if (p->data < q->data)
    {
        third = last = p;
        p = p->next;
        last->next = NULL;
    }
    else
    {
        third = last = q;
        q = q->next;
        last->next = NULL;
    }
    while (p != NULL && q != NULL)
    {
        if (p->data < q->data)
        {
            last->next = p;
            last = p;
            p = p->next;
            last->next = NULL;
        }
        else
        {
            last->next = q;
            last = q;
            q = q->next;
            last->next = NULL;
        }
    }
    if (p != NULL)
        last->next = p;
    else
        last->next = q;
}

int isLoop(struct Node *f)
{
    struct Node *p, *q;
    p = q = f;
    do
    {
        p = p->next;
        q = q->next;
        q = q != NULL ? q->next : q;
    } while (p && q && p != q);
    if (p == q)
        return 1;
    else
        return 0;
}

int main()
{
    struct Node *t1, *t2;
    int A[] = {10, 20, 30, 40, 50};
    create(A, 5);

    // LOOP ( from 50->30 )
    t1 = first->next->next;
    t2 = first->next->next->next->next;
    t2->next = t1;
    printf("%d ", isLoop(first));

    return 0;
}
