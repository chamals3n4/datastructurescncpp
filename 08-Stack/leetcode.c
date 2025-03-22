#include <stdlib.h>
#include <string.h>
bool isValid(char *s)
{
    int length = strlen(s);
    char *stack = malloc(sizeof(char) * length);
    int top = -1;
    for (int i = 0; s[i] != '\0'; i++)
    {
        if (s[i] == '(' || s[i] == '{' || s[i] == '[')
            stack[++top] = s[i];
        else if (s[i] == ')' || s[i] == '}' || s[i] == ']')
        {
            if (top == -1)
                return false;
            else if (s[i] - stack[top] == 1 || s[i] - stack[top] == 2)
                stack[top--];
            else
                return false;
        }
    }
    bool isValid = (top == -1);
    return isValid
}

int main()
{
    return 0;
}