#include <stdio.h>
#include <stdlib.h>

int main()
{
    int A[3][4] = {{
                       1,
                       2,
                       3,
                       4,
                   },
                   {
                       5,
                       13,
                       57,
                       188,
                   },
                   {
                       13,
                       81,
                       76,
                       23,
                   }};
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            printf("%d \n", A[i][j]);
        }
        printf("\n");
    }

    int *B[3];
    int **C;
    B[0] = (int *)malloc(4 * sizeof(int));
    B[1] = (int *)malloc(4 * sizeof(int));
    B[2] = (int *)malloc(4 * sizeof(int));

    C = (int **)malloc(sizeof(int *));
    C[0] = (int *)malloc(sizeof(int));
    C[1] = (int *)malloc(sizeof(int));
    C[2] = (int *)malloc(sizeof(int));

    return 0;
}