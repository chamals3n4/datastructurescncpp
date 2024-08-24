#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *A, n, ch, x;
    int i, j;
    printf("enter dimension : ");
    scanf("%d", &n);
    A = (int *)malloc(n * sizeof(int));
    do
    {
        printf("Menu\n");
        printf("1. CREATE\n");
        printf("2. GET\n");
        printf("3. SET\n");
        printf("4. DISPLAY\n");
        printf("5. Exit\n");

        printf("Enter your choice : ");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            for (i = 0; i < n; i++)
                scanf("%d", &A[i]);
            break;
        case 2:
            printf("enter indices - ");
            scanf("%d %d", &i, &j);
            if (i == j)
                printf("%d", A[i - 1]);
            else
                printf("0");
            break;
        case 3:
            printf("enter column row and element");
            scanf("%d%d%d", &i, &j, &x);
            if (i == j)
                A[i - 1] = x;
            break;
        case 4:
            for (i = 1; i < n; i++)
            {
                for (j = 1; j < n; j++)
                {
                    if (i == j)
                        printf("%d", A[i - 1]);
                    else
                        printf("0");
                }
                printf("\n");
            }
            break;
        }
    } while (ch < 5);
}