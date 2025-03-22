#include <stdio.h>
#include <stdlib.h>

int main()
{
    int A[5] = {2, 4, 6, 8, 10};
    int *p;
    p = (int *)malloc(5 * sizeof(int));
    p[0] = 20;
    p[1] = 40;
    p[2] = 60;
    p[3] = 80;
    p[4] = 100;

    for (int i = 0; i < 4; i++)
        printf("%d ", A[i]);
    printf("\n");
    for (int i = 0; i < 4; i++)
        printf("%d ", p[i]);

    return 0;
}