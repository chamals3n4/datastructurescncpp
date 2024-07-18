#include <iostream>
#include <stdio.h>
#include <stdlib.h>

int main()
{
    // Creating Array on Stack
    int A[5];
    int i;
    for (i = 0; i < 5; i++)
    {
        std::cout << &A[i] << std::endl;
    }

    // Creating Array on Heap

    // C++
    int *p;
    p = new int[5];

    p[0] = 1;
    p[1] = 2;
    p[2] = 3;
    p[3] = 4;
    p[4] = 5;

    for (int x = 0; x < 5; x++)
    {
        std::cout << p[x] << std::endl;
    }
    delete[] p;

    // C
    int *q;
    q = (int *)malloc(5 * sizeof(int));

    q[0] = 10;
    q[1] = 20;
    q[2] = 30;
    q[3] = 40;
    q[4] = 50;

    for (int k = 0; k < 5; k++)
    {
        printf("%d\n", q[k]);
    }
    free(q);

    return 0;
}