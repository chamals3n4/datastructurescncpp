#include <stdio.h>

// Tail
void fun(int n)
{
    if (n > 0)
    {
        printf("%d ", n);
        fun(n - 1);
    }
}

// Head
void fun1(int n)
{
    if (n > 0)
    {
        fun1(n - 1);
        printf("%d ", n);
    }
}

int main()
{
    int x = 3;
    // fun(x);
    fun1(x);
    return 0;
}