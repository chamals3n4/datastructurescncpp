#include <iostream>

void funB(int n);

void funA(int n)
{
    if (n > 0)
    {
        std::cout << n << std::endl;
        funB(n - 1);
    }
}

void funB(int n)
{
    if (n > 0)
    {
        std::cout << n << std::endl;
        funA(n / 2);
    }
}

int main()
{
    funA(20);
}