#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int prec(char c)
{
    if (c == '^')
        return 3;
    if (c == '/' || c == '*')
        return 2;
    if (c == '+' || c == '-')
        return 1;
    return -1;
}

int isAlphanumeric(char c)
{
    return (c >= '0' && c <= '9') || (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z');
}

void InfixToPostfix(char exp[])
{

    char stack[100], result[100];
    int j = 0, top = -1, i;

    for (i = 0; exp[i] != '\0'; i++)
    {
        char c = exp[i];
        if (isAlphanumeric(c))
        {
            result[j++] = c;
        }
        else if (c == '(')
        {
            stack[++top] = c;
        }
        else if (c == ')')
        {
            while (top != -1 && stack[top] != '(')
            {
                result[j++] = stack[top--];
            }
            top--;
        }
        else
        {
            while (top != -1 && prec(c) <= prec(stack[top]))
                result[j++] = stack[top--];
            stack[++top] = c;
        }
    }
    while (top != -1)
        result[j++] = stack[top--];

    result[j] = '\0';
    printf("\nPostfix Expression: %s\n", result);
}

int main()
{

    char exp[100];

    printf("Enter an infix expression: ");
    scanf("%s", &exp);

    InfixToPostfix(exp);

    return 0;
}
