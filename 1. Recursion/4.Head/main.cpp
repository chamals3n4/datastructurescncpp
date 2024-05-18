#include <iostream>

// Recursion
void fun(int n)
{
    if (n > 0)
    {
        fun(n - 1);
        std::cout << n << std::endl;
    }
}

// Loop
void Ifun(int n)
{
    int i = 1;
    while (i <= n)
    {
        std::cout << i << std::endl;
        i++;
    }
}

int main()
{
    int n = 3;
    fun(n);
    Ifun(n);

    return 0;
}