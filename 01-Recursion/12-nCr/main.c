// combination formula
#include <stdio.h>

int fact(int n)
{
    if (n == 0)
        return 1;
    return fact(n - 1) * n;
}

int nCr(int n, int r)
{
    int num, den;
    num = fact(n);
    den = fact(r) * fact(n - r);
    return num / den;
}

int nCrV2(int n, int r)
{
    if (n == r || r == 0)
        return 1;
    return nCrV2(n - 1, r - 1) + nCrV2(n - 1, r);
}

int main()
{
    printf("%d \n", nCr(5, 1));
    printf("%d \n", nCrV2(5, 1));
    return 0;
}