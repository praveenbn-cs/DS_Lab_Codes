// Program to convert infix expression to postfix expression

#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Returns the precedence of an operator in the stack
int F(char symbol)
{
    switch (symbol)
    {
        case '+': return 2;
        case '-': return 2;
        case '*': return 4;
        case '/': return 4;
        case '^': return 5;
        case '(': return 0;
        case '#': return -1;
        default:  return 8;
    }
}

// Returns the precedence of an incoming symbol
int G(char symbol)
{
    switch (symbol)
    {
        case '+': return 1;
        case '-': return 1;
        case '*': return 3;
        case '/': return 3;
        case '^': return 6;
        case '(': return 9;
        case ')': return 0;
        default:  return 7;
    }
}

// Converts the given infix expression into postfix form
void infix_postfix(char infix[], char postfix[])
{
    int top, j, i;
    char s[30], symbol;

    top = -1;
    s[++top] = '#';  // Marks the bottom of the stack
    j = 0;

    // Read the expression one symbol at a time
    for (i = 0; i < strlen(infix); i++)
    {
        symbol = infix[i];

        // Move operators from the stack to postfix when needed
        while (F(s[top]) > G(symbol))
        {
            postfix[j++] = s[top--];
        }

        // Push the symbol or remove the matching parenthesis
        if (F(s[top]) != G(symbol))
            s[++top] = symbol;
        else
            top--;
    }

    // Add the remaining operators to the postfix expression
    while (s[top] != '#')
        postfix[j++] = s[top--];

    postfix[j] = '\0';  // Marks the end of the postfix string
}

int main()
{
    char infix[30], postfix[30];

    // Read the infix expression from the user
    printf("Enter infix expression:\n");
    scanf("%29s", infix);

    infix_postfix(infix, postfix);

    // Print the converted expression
    printf("Postfix expression is: %s\n", postfix);

    return 0;
}
