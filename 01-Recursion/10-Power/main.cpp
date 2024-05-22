#include <iostream>

// Performance #2
int pow(int m, int n)
{
    if (n == 0)
        return 1;
    return pow(m, n - 1) * m;
}

// Performance #1
int Pow(int m, int n)
{
    if (n == 0)
        return 1;
    if (n % 2 == 0)
        return Pow(m * m, n / 2);
    else
        return m * Pow(m * m, (n - 1) / 2);
}

int main()
{
    std::cout << pow(5, 2) << std::endl;
    std::cout << Pow(5, 2) << std::endl;

    return 0;
}