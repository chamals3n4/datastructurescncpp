#include <iostream>

// Fact using for nCr()
int fact(int n)
{
    if (n == 0)
        return 1;
    return fact(n - 1) * n;
}

// Without Recursion(fact is a recursion but nCr not a recursive function)
int nCr(int n, int r)
{
    int num, den;
    num = fact(n);
    den = fact(r) * fact(n - r);

    return num / den;
}

// Using Recursion
int NCR(int n, int r)
{
    if (r == 0 || n == r)
        return 1;
    return NCR(n - 1, r - 1) + NCR(n - 1, r);
}

int main()
{
    std::cout << nCr(5, 1) << std::endl;
    std::cout << NCR(5, 1) << std::endl;
}