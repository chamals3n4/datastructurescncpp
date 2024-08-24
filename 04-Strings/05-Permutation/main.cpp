#include <stdio.h>

void perm(char s[], int k)
{
    static int A[10] = {0};
    static char RES[10] = {0};

    int i;

    if (s[k] == '\0')
    {
        RES[k] = '\0';
        printf("%s\n", RES);
        return;
    }

    for (i = 0; s[i] != '\0'; i++)
    {
        if (A[i] == 0)
        {
            RES[k] = s[i];
            A[i] = 1;
            perm(s, k + 1);
            A[i] = 0;
        }
    }
}

void Swap(int x, int y)
{
    int temp;
    temp = x;
    x = y;
    y = temp;
}

void SWAPperm(char s[], int l, int h)
{
    int i;
    if (i == h)
    {
        printf("%s", s);
        return;
    }
    else
    {
        for (i = l; i <= h; i++)
        {
            Swap(s[l], s[i]);
            SWAPperm(s, l + 1, h);
            Swap(s[l], s[i]);
        }
    }
}

int main()
{
    char s[] = "ABC";
    perm(s, 0);
    return 0;
}