// Sum of Natural Numbers using Recursion

#include <iostream>

// Performance #3
int Sum(int n)
{
    if (n == 0)
        return 0;
    else
        return Sum(n - 1) + n;
}

// Performance #2
int ISum(int n)
{
    int i, s = 0;
    for (i = 1; i <= n; i++)
        s = s + i;
    return s;
}

// Performance #1
int CSum(int n)
{
    return n * (n + 1) / 2;
}

int main()
{
    std::cout << Sum(5) << std::endl;
    std::cout << ISum(5) << std::endl;
    std::cout << CSum(5) << std::endl;

    return 0;
}