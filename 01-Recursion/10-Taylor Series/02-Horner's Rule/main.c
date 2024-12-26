#include <stdio.h>

double e(int x, int n)
{
    static double s;
    if (n == 0)
        return s;
    s = 1 + (double)x / (double)n * s;
    // s = 1 + x * s / n; => without typecasting
    return e(x, n - 1);
}

double e2(double x, double n)
{
    double s = 1;
    double num = 1;
    double den = 1;
    for (int i = 1; i <= n; i++)
    {
        num *= x;
        den *= i;
        s += num / den;
    }
    return s;
}

int main()
{
    printf("%lf \n", e(1, 10));
    printf("%lf ", e2(1, 10));
    return 0;
}