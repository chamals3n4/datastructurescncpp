#include <iostream>
using namespace std;
class Symetric_matrix
{
private:
    int *A;
    int n;

public:
    Symetric_matrix()
    {
        n = 4;
        A = new int[n * (n + 1) / 2];
    }
    Symetric_matrix(int n)
    {
        this->n = n;
        A = new int[n * (n + 1) / 2];
    }
    ~Symetric_matrix()
    {
        delete[] A;
    }
    void set(int i, int j, int x);
    int get(int i, int j);
    void display();
};
void Symetric_matrix ::set(int i, int j, int x)
{
    if (i >= j)
        A[i * (i - 1) / 2 + (j - 1)] = x;
}
int Symetric_matrix ::get(int i, int j)
{
    if (i >= j)
        return A[i * (i - 1) / 2 + (j - 1)];
    else
        return get(j, i); // changes
}
void Symetric_matrix::display()
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (i >= j) // changes
                cout << A[i * (i - 1) / 2 + (j - 1)] << " ";
            else // changes
                cout << A[j * (j - 1) / 2 + (i - 1)] << " ";
        }
        cout << endl;
    }
}
int main()
{
    int d;
    cout << "Enter the diamentions of the Matrix :- ";
    cin >> d;
    class Symetric_matrix m(d);
    int flag;
    for (int i = 1; i <= d; i++)
    {
        for (int j = 1; j <= d; j++)
        {
            cin >> flag;
            m.set(i, j, flag);
        }
    }
    cout << endl
         << endl;
    m.display();
    cout << endl
         << m.get(1, 3) << endl
         << m.get(3, 1) << endl
         << m.get(2, 3);
}