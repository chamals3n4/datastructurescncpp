#include <stdio.h>

#define ASCII_UPPERCASE_A 65
#define ASCII_UPPERCASE_Z 90
#define ASCII_LOWERCASE_A 97
#define ASCII_LOWERCASE_Z 122
#define ASCII_CASE_DIFFERENCE 32
#define ASCII_DIGIT_0 48
#define ASCII_DIGIT_9 57

// Function to toggle case of each character in a string
void toggleCase(char str[])
{
    int i;
    for (i = 0; str[i] != '\0'; i++)
    {
        if (str[i] >= ASCII_UPPERCASE_A && str[i] <= ASCII_UPPERCASE_Z)
        {
            str[i] += 32;
        }
        else if (str[i] >= ASCII_LOWERCASE_A && str[i] <= ASCII_LOWERCASE_Z)
        {
            str[i] -= ASCII_CASE_DIFFERENCE;
        }
    }
    printf("length is : %d\n", i);
    printf("%s\n", str);
}

// Func to count vowels and consonants in a string
void countVowelsandConsanants(char str[])
{
    int i;
    int vowels = 0, consonants = 0;
    for (i = 0; str[i] != '\0'; i++)
    {
        char ch = str[i];
        if (ch >= ASCII_UPPERCASE_A && ch <= ASCII_UPPERCASE_Z)
        {
            ch = ch + ASCII_CASE_DIFFERENCE;
        }
        if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
        {
            vowels++;
        }
        else if ((ch >= ASCII_LOWERCASE_A && ch <= ASCII_LOWERCASE_Z))
        {
            consonants++;
        }
    }
    printf("Vowels: %d\n", vowels);
    printf("Consonants: %d\n", consonants);
}

// Num of words
void numOfWord(char str[])
{
    int i, word = 0;
    for (i = 0; str[i] != '\0'; i++)
    {
        if (str[i] == ' ' && str[i - 1] != ' ')
            word++;
    }
    printf("Number of words : %d\n", word + 1);
}

// Validating String
int validate(char *name)
{
    int i;
    for (i = 0; name[i] != '\0'; i++)
    {
        char ch = name[i];
        if (ch >= ASCII_UPPERCASE_A && ch <= ASCII_UPPERCASE_Z)
        {
            ch = ch + ASCII_CASE_DIFFERENCE;
        }
        if (!(ch >= ASCII_LOWERCASE_A && ch <= ASCII_LOWERCASE_Z) && !(ch >= ASCII_DIGIT_0 && ch <= ASCII_DIGIT_9))
        {
            return 0;
        }
    }
    return 1;
}

// Reversing Array
void Reverse(char str[])
{
    char H[7];
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
    printf("Reverse - %s\n", H);
}

void SwapReverse(char str[])
{
    char t;
    int i, j;
    for (j = 0; str[j] != '\0'; j++)
    {
    }
    j = j - 1;
    for (i = 0; i < j; i++, j--)
    {
        t = str[i];
        str[i] = str[j];
        str[j] = t;
    }
    printf("SwapReverse - %s\n", str);
}

int main()
{
    char welcomMsg[] = "wELcomE";
    toggleCase(welcomMsg);

    char str[] = "How are you";
    countVowelsandConsanants(str);
    numOfWord(str);

    char name[] = "Anil321";
    if (validate(name))
        printf("Valid string\n");
    else
        printf("Invalid string\n");

    char rev[] = "Python";
    Reverse(rev);
    SwapReverse(rev);

    return 0;
}