#include <iostream>

// Using recursion
double e(int x, int n)
{
    static double s;
    if (n == 0)
        return s;
    s = 1 + x * s / n;
    return e(x, n - 1);
}

// Using Loop
double Ie(int x, int n)
{
    double s = 1;
    for (; n > 0; n--)
    {
        s = 1 + x * s / n;
    }
    return s;
}

int main()
{
    std::cout << e(1, 10) << std::endl;
    std::cout << Ie(1, 10) << std::endl;
    return 0;
}