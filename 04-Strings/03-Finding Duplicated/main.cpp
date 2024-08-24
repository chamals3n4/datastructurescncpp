#include <stdio.h>
#include <iostream>

void FindDuplicates(char str[])
{
    int i;
    printf("duplicate elephants are\n");

    for (i = 0; str[i] != '\0'; i++)
    {
        int count = 1;
        if (str[i] != -1)
        {
            for (int j = i + 1; str[j] != '\0'; j++)
            {
                if (str[i] == str[j])
                {
                    count++;
                    str[j] = -1;
                }
            }
            if (count > 1)
            {
                printf("%c - %d\n", str[i], count);
            }
        }
    }
}

void FindDuplicateHasing(char str[])
{
    int H[26] = {0}, i;
    for (i = 0; str[i] != '\0'; i++)
    {
        H[str[i] - 'a']++;
    }
    for (i = 0; i < 26; i++)
    {
        if (H[i] > 1)
        {
            printf("%c - %d Times", i + 97, H[i]);
        }
    }
}

void FindDuplicatedBits(char str[])
{
    long int h = 0;
    long int x = 0;
    int i;
    for (i = 0; str[i] != '\0'; i++)
    {
        x = 1;
        x = x << (str[i] - 97);
        if ((x & h) > 0)
        {
            printf("%c is duplicate \n", str[i]);
        }
        else
        {
            h = x | h;
        }
    }
}

int main()
{
    char str[] = "finding";
    // FindDuplicates(str);
    // FindDuplicateHasing(str);
    FindDuplicatedBits(str);

    return 0;
}