#include <stdio.h>

double e(double x, double n)
{
    static double p = 1, f = 1;
    double r = 0;
    if (n == 0)
        return 1;
    else
    {
        r = e(x, n - 1);
        p = p * x;
        f = f * n;
        return r + p / f;
    }
}

int main()
{
    printf("%f ", e(1, 10));
    return 0;
}