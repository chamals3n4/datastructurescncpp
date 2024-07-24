#include <iostream>

template <class T>
class Array
{
private:
    T *A;
    int size;
    int length;

public:
    Array()
    {
        size = 20;
        A = new T[size];
        length = 0;
    }
    Array(int sz)
    {
        size = sz;
        A = new T[sz];
        length = 0;
    }
    ~Array()
    {
        delete[] A;
    }

    void Display();
    void Insert(int index, T x);
    T Delete(int index);
};

template <class T>
void Array<T>::Display()
{
    int i;
    for (i = 0; i < length; i++)
    {
        std::cout << A[i] << " ";
        std::cout << std::endl;
    }
}

template <class T>
void Array<T>::Insert(int index, T x)
{
    int i;
    if (index >= 0 && index <= length)
    {
        for (i = length; i > index; i--)
            A[i] = A[i - 1];
        A[index] = x;
        length++;
    }
}

template <class T>
T Array<T>::Delete(int index)
{
    int x = 0;
    int i;

    if (index >= 0 && index < length)
    {
        x = A[index];
        for (i = index; i < length - 1; i++)
            A[i] = A[i + 1];
        length--;
        return x;
    }

    return 0;
}

int main()
{

    Array<float> arr(10);

    int i;
    float j;
    for (i = 0, j = 6.6; i < 6; i++, j--)
    {
        arr.Insert(i, j);
    }

    arr.Display();

    std::cout << arr.Delete(5) << std::endl;
    arr.Display();

    return 0;
}