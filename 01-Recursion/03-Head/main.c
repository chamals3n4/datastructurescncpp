#include <stdio.h>

void fun(int n)
{
    if (n > 0)
    {
        fun(n - 1);
        printf("%d ", n);
    }
}

void fun1(int n)
{
    int i = 1;
    while (i <= n)
    {
        printf("%d ", i);
        i++;
    }
}

int main()
{

    fun(3);
    fun1(3);
    return 0;
}