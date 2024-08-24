#include <iostream>

// Using recursion #2
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

// x and n both and int, soo instead of typecasting double ->  s = 1 + x * s / n;

int main()
{
    std::cout << e(1, 10) << std::endl;
    std::cout << Ie(1, 10) << std::endl;
    return 0;
}