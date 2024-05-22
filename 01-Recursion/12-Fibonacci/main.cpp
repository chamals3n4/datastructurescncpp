#include <iostream>

// Recursive Version
int fib(int n)
{
    if (n <= 1)
    {
        return n;
    }
    else
    {
        return fib(n - 2) + fib(n - 1);
    }
}

// Iterative Version
int Ifib(int n)
{
    int t0 = 0, t1 = 1, s, i;
    for (i = 2; i <= n; i++)
    {
        s = t0 + t1;
        t0 = t1;
        t1 = s;
    }
    return s;
}

int main()
{
    std::cout << fib(7) << std::endl;
    std::cout << Ifib(7) << std::endl;
    return 0;
}