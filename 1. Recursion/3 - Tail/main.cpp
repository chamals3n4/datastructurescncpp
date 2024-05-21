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

int main()
{
    fun(3);
    Ifun(3);
    return 0;
}