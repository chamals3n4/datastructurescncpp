#include <iostream>

int Fact(int n)
{
    if (n == 0)
        return 1;
    else
        return Fact(n - 1) * n;
}

int IFact(int n)
{
    int i, s = 1;
    for (i = 1; i <= n; i++)
        s = s * i;
    return s;
}

int main()
{
    std::cout << Fact(5) << std::endl;
    std::cout << IFact(5) << std::endl;
    return 0;
}