#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *p, *q;
    p = (int *)malloc(5 * sizeof(int));
    p[0] = 20;
    p[1] = 40;
    p[2] = 60;
    p[3] = 80;
    p[4] = 100;

    q = (int *)malloc(10 * sizeof(int));

    for (int i = 0; i < 4; i++)
        q[i] = p[i];
    free(p);
    p = q;
    q = NULL;

    return 0;
}