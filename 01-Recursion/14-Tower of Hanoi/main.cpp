#include <iostream>

/*
A - FROM
B - USING
C - TO
*/

void TOH(int n, int A, int B, int C)
{
    if (n > 0)
    {
        TOH(n - 1, A, C, B);
        std::cout << "Move from " << A << "to" << C << std::endl;
        TOH(n - 1, B, A, C);
    }
}

int main()
{
    TOH(3, 1, 2, 3);
    return 0;
}