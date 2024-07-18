#include <iostream>

void fun(int n)
{
    if (n > 0)
    {
        std::cout << n << std::endl;
        fun(n - 1);
    }
}

void Ifun(int n)
{
    while (n > 0)
    {
        std::cout << n << std::endl;
        n--;
    }
}

void IncFn(int n)
{
    if (n < 5)
    {
        std::cout << n << std::endl;
        IncFn(n + 1);
    }
}

int main()
{
    fun(3);
    Ifun(3);
    IncFn(1);
    return 0;
}