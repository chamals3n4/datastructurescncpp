#include <stdio.h>

// excessive recursion - recursvive func calling itself multiple times O(2^n)
int fib(int n)
{
    if (n <= 1)
        return n;
    return fib(n - 2) + fib(n - 1);
}

// O(n)
int fib2(int n)
{
    int t0 = 0, t1 = 1, sum;
    if (n <= 1)
        return n;
    for (int i = 2; i <= n; i++)
    {
        sum = t0 + t1;
        t0 = t1;
        t1 = sum;
    }
    return sum;
}

int F[10];
// O(n) - Memoizations
int fib3(int n)
{
    if (n <= 1)
    {
        F[n] = n;
        return n;
    }
    else
    {
        if (F[n - 2] == -1)
            F[n - 2] = fib3(n - 2);
        if (F[n - 1] == -1)
            F[n - 1] = fib3(n - 1);
        F[n] = F[n - 2] + F[n - 1];
        return F[n - 2] + F[n - 1];
    }
}

int main()
{
    printf("%d ", fib(7));
    printf("%d ", fib2(7));

    for (int i = 0; i < 10; i++)
        F[i] = -1;

    printf("%d ", fib3(7));
    return 0;
}