#include <iostream>

// Tail Recursion
void fun1(int n)
{
    if (n > 0)
    {
        std::cout << n << std::endl;
        fun1(n - 1);
    }
}

// Head Recursion
void fun2(int n)
{
    if (n > 0)
    {
        fun2(n - 1);
        std::cout << n << std::endl;
    }
}

int main()
{
    int x = 3;
    fun1(x);
    fun2(x);

    return 0;
}