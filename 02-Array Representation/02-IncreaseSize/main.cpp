#include <iostream>

int main()
{
    int *p = new int[5];
    p[0] = 1;
    p[1] = 2;
    p[2] = 3;
    p[3] = 4;
    p[4] = 5;

    // Lets increase this array by creating new pointer on heap,

    int *q = new int[10];
    for (int i = 0; i < 5; i++)
    {
        q[i] = p[i];
    }

    delete[] p;
    p = q;
    q = NULL;
    p[5] = 75;

    for (int i = 0; i < 6; i++)
    {
        std::cout << p[i] << std::endl;
    }

    return 0;
}