// Lower Triangular Matrix using C++ Class

#include <iostream>

class LowerTriangular
{
private:
    int *A;
    int n;

public:
    LowerTriangular()
    {
        n = 2;
        A = new int[2 * (2 + 1) / 2];
    }
    LowerTriangular(int n)
    {
        this->n = n;
        A = new int[n * (n + 1) / 2];
    }
    ~LowerTriangular()
    {
        delete[] A;
    }

    void Set(int i, int j, int x);
    int Get(int i, int j);
    void Display();
    int GetDimension() { return n; }
};

void LowerTriangular::Set(int i, int j, int x)
{
    if (i >= j)
        // column major formula
        // A[i * (i - 1) / 2 + j - 1] = x;

        // row major formula
        A[n * (j - 1) + (j - 2) / 2 + i - j] = x;
}

int LowerTriangular::Get(int i, int j)
{
    if (i >= j)
        // column major formula
        // return A[i * (i - 1) / 2 + j - 1];

        // row major formula
        return A[n * (j - 1) + (j - 2) / 2 + i - j];
    return 0;
}

void LowerTriangular::Display()
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (i >= j)

                // column major formula
                //  std::cout << A[i * (i - 1) / 2 + j - 1] << " ";

                // row major formula
                std::cout << A[n * (j - 1) + (j - 2) / 2 + i - j] << " ";

            else
                std::cout << "0 ";
        }
        std::cout << std::endl;
    }
}

int main()
{

    int d;
    std::cout << "enter dimension : ";
    std::cin >> d;
    LowerTriangular ltm(d);

    int x;
    std::cout << "enter all elements";
    for (int i = 1; i <= d; i++)
    {
        for (int j = 1; j <= d; j++)
        {
            std::cin >> x;
            ltm.Set(i, j, x);
        }
    }

    ltm.Display();
    return 0;
}