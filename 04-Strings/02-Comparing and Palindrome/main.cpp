#include <stdio.h>

void Comp(char A[], char B[])
{
    int i, j;
    for (i = 0, j = 0; A[i] != '\0' && B[j] != '\0'; i++, j++)
    {
        if (A[i] != B[j])
            break;
    }
    if (A[i] == B[j])
        printf("Equal\n");
    else if (A[i] < B[j])
        printf("Smaller\n");
    else
        printf("Greater\n");
}

void Palindrome(char str[])
{
    char H[6];
    int i;
    for (i = 0; str[i] != '\0'; i++)
    {
    }
    i = i - 1;
    int j;
    for (j = 0; i >= 0; i--, j++)
    {
        H[j] = str[i];
    }
    H[j] = '\0';

    for (i = 0, j = 0; str[i] != '\0' && H[j] != '\0'; i++, j++)
    {
        if (str[i] != H[j])
            break;
    }
    if (str[i] == H[j])
        printf("this is palindrome\n");
    else
        printf("this is not a palindrome\n");
}

int main()
{
    char A[] = "Painter";
    char B[] = "Painting";
    Comp(A, B);

    char P[] = "madam";
    Palindrome(P);

    return 0;
}