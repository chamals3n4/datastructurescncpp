#include <iostream>

class Element
{
public:
    int i;
    int j;
    int x;
};

class Sparse
{
private:
    int m;
    int n;
    int num;
    Element *ele;

public:
    Sparse(int m, int n, int num)
    {
        this->m = m;
        this->n = n;
        this->num = num;
        ele = new Element[this->num];
    }
    ~Sparse()
    {
        delete[] ele;
    }

    Sparse operator+(Sparse &s);

    friend std::istream &operator>>(std::istream &is, Sparse &s);
    friend std::ostream &operator<<(std::ostream &os, Sparse &s);
};

Sparse Sparse::operator+(Sparse &s)
{
    int i, j, k;
    // if (m != s.m || n != s.n)
    //     return NULL;
    Sparse *sum = new Sparse(m, n, num + s.num);

    i = j = k = 0;
    while (i < num && j < s.num)
    {
        if (ele[i].i < s.ele[j].i)
            sum->ele[k++] = ele[i++];
        else if (ele[i].i > s.ele[j].i)
            sum->ele[k++] = s.ele[j++];
        else
        {
            if (ele[i].j < s.ele[j].j)
                sum->ele[k++] = ele[i++];
            else if (ele[i].j > s.ele[j].j)
                sum->ele[k++] = s.ele[j++];
            else
            {
                sum->ele[k] = ele[i];
                sum->ele[k++].x = ele[i++].x + s.ele[j++].x;
            }
        }
    }
    for (; i < num; i++)
        sum->ele[k++] = ele[i];
    for (; j < s.num; j++)
        sum->ele[k++] = s.ele[j];
    sum->num = k;

    return *sum;
}

// void read
std::istream &operator>>(std::istream &is, Sparse &s)
{
    std::cout << "enter non-zero elements";
    for (int i = 0; i < s.num; i++)
        std::cin >> s.ele[i].i >> s.ele[i].j >> s.ele[i].x;

    return is;
}

// void display
std::ostream &operator<<(std::ostream &os, Sparse &s)
{
    int k = 0;
    for (int i = 0; i < s.m; i++)
    {
        for (int j = 0; j < s.n; j++)
        {
            if (s.ele[k].i == i && s.ele[k].j == j)
                std::cout << s.ele[k++].x << " ";
            else
                std::cout << "0 ";
        }
        std::cout << std::endl;
    }

    return os;
}

int main()
{
    Sparse s1(5, 5, 5);
    Sparse s2(5, 5, 5);

    // std::cin >> s1;
    // std::cout << s1;

    std::cin >> s1;
    std::cin >> s2;

    Sparse sum = s1 + s2;

    std::cout << "first matrix" << std::endl
              << s1;
    std::cout << "second matrix" << std::endl
              << s2;
    std::cout << "sum matrix" << std::endl
              << sum;

    return 0;
}