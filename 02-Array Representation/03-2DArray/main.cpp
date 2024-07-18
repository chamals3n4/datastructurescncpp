#include <iostream>

int main()
{
    // Method 1
    int A[3][4] = {{1, 2, 3, 4}, {2, 4, 6, 8}, {1, 3, 5, 7}};

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; i < 4; j++)
            std::cout << A[i][j] << std::endl;
    }

    // Method 2;
    int *B[3];
    B[0] = (int *)malloc(4 * sizeof(int));
    B[1] = (int *)malloc(4 * sizeof(int));
    B[2] = (int *)malloc(4 * sizeof(int));

    /*
        -- C++ --

        int *B[3];
        B[0] = new int[4];
        B[1] = new int[4];
        B[2] = new int[4];
    */
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; i < 4; j++)
            std::cout << B[i][j] << std::endl;
    }

    // Method 3
    int **C;

    C = (int **)malloc(3 * sizeof(int));
    C[0] = (int *)malloc(4 * sizeof(int));
    C[1] = (int *)malloc(4 * sizeof(int));
    C[2] = (int *)malloc(4 * sizeof(int));

    /*
        -- C++ --
        int **C;
        C = new int *[3];
        C[0] = new int[4];
        C[1] = new int[4];
        C[2] = new int[4];
    */
    return 0;
}