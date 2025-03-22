#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *next;
} *top = NULL;

void push(int x)
{
    struct Node *t;
    t = (struct Node *)malloc(sizeof(struct Node));

    if (t == NULL)
        printf("stack is full\n");
    else
    {
        t->data = x;
        t->next = top;
        top = t;
    }
}

int pop()
{
    struct Node *t;
    int x = -1;

    if (top == NULL)
        printf("Stack is empty\n");
    else
    {
        t = top;
        top = top->next;
        x = t->data;
        free(t);
    }
    return x;
}

void Display()
{
    struct Node *p;
    p = top;
    while (p != NULL)
    {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

int stackTop()
{
    if (top != NULL)
        return top->data;
    return -1;
}

int isBalanced(char *exp)
{
    for (int i = 0; exp[i] != '\0'; i++)
    {
        if (exp[i] == '(' || exp[i] == '[' || exp[i] == '{')
            push(exp[i]);

        //  ( = 40   ) = 41
        //  [ = 91   ] = 93
        //  { = 123  } = 125
        else if (exp[i] == ')' || exp[i] == ']' || exp[i] == '}')
        {
            if (top == NULL)
                return 0;
            else if (exp[i] == stackTop() + 1 || exp[i] == stackTop() + 2)
                pop();
            else
                return 0;
        }
    }
    if (top == NULL)
        return 1;
    else
        return 0;
}

int isOperand1(char x)
{
    if (x == '+' || x == '-' || x == '*' || x == '/')
        return 0;
    else
        return 1;
}

int isOperand(char x)
{
    if (x == '+' || x == '-' || x == '*' || x == '/' || x == '^' || x == '(' || x == ')')
        return 0;
    return 1;
}

int precendence(char x)
{
    if (x == '+' || x == '-')
        return 1;
    else if (x == '*' || x == '/')
        return 2;
    return 0;
}

int outPre(char x)
{
    if (x == '+' || x == '-')
        return 1;
    else if (x == '*' || x == '/')
        return 3;
    else if (x == '^')
        return 6;
    else if (x == '(')
        return 7;
    else if (x == ')')
        return 0;
    else
        return -1;
}

int inPre(char x)
{
    if (x == '+' || x == '-')
        return 2;
    else if (x == '*' || x == '/')
        return 4;
    else if (x == '^')
        return 5;
    else if (x == '(')
        return 0;
    else
        return -1;
}

int length(char *s)
{
    int len = 0;
    for (int i = 0; s[i] != '\0'; i++)
        len++;
    return len;
}

// Infix to Postfix
char *InfixToPostfix(char *infix)
{
    char *postfix;
    int len = length(infix);
    postfix = (char *)malloc(sizeof(char) * (len + 2));

    int i = 0, j = 0;
    while (infix[i] != '\0')
    {
        if (isOperand(infix[i]))
            postfix[j++] = infix[i++];
        else
        {
            if (precendence(infix[i]) > precendence(top->data))
                push(infix[i++]);
            else
            {
                postfix[j++] = pop();
            }
        }
    }
    while (top != NULL)
    {
        postfix[j++] = pop();
    }
    postfix[j] = '\0';
    return postfix;
}

char *InfixToPostfixWithAssociativityParenthesis(char *infix)
{
    char *postfix;
    int len = length(infix);
    postfix = (char *)malloc(sizeof(char) * (len + 2));
    int i = 0, j = 0;
    push('#');
    while (infix[i] != '\0')
    {
        if (isOperand(infix[i]))
        {
            postfix[j++] = infix[i++];
        }
        else
        {
            if (top == NULL || outPre(infix[i]) > inPre(top->data))
                push(infix[i++]);
            else
            {
                if (outPre(infix[i]) == inPre(top->data))
                {
                    pop();
                    i++;
                }
                else
                    postfix[j++] = pop();
            }
        }
    }
    while (top != NULL)
    {
        if (top->data != '#')
            postfix[j++] = pop();
        else
            pop();
    }
    postfix[j] = '\0';
    return postfix;
}

int Eval(char *postfix)
{
    int x1, x2, r;
    for (int i = 0; postfix[i] != '\0'; i++)
    {
        if (isOperand1(postfix[i]))
        {
            push(postfix[i] - '0');
        }
        else
        {
            x2 = pop();
            x1 = pop();
            switch (postfix[i])
            {
            case '+':
                r = x1 + x2;
                break;
            case '-':
                r = x1 - x2;
                break;
            case '*':
                r = x1 * x2;
                break;
            case '/':
                r = x1 / x2;
                break;
            }
            push(r);
        }
    }
    return top->data;
}

int main()
{
    // char *exp = "((a+b)*(c-d))";
    // char *exp2 = "{([a+b]*[c-d])/e}}";
    // printf("%d ", isBalanced(exp2));

    char *infix = "a+b*c";
    char *infix2 = "((a+b)*c)-d^e^f";

    char *postfix2 = InfixToPostfixWithAssociativityParenthesis(infix2);
    printf("%s\n", postfix2);

    // char *postfix = InfixToPostfix(infix);
    // printf("%s \n", postfix);

    char *postfixeval = "234*+82/-";
    printf("result is  : %d", Eval(postfixeval));

    return 0;
}