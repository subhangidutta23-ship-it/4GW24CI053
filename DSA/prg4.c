#include <stdio.h>
#include <stdlib.h>

void evaluate(void);
void push(char);
char pop(void);
int prec(char);

char infix[30], postfix[30], stack[30];
int top = -1;

int main()
{
    printf("\nEnter the valid infix expression: ");
    scanf("%s", infix);

    evaluate();

    printf("\nThe entered infix expression is: %s\n", infix);
    printf("The corresponding postfix expression is: %s\n", postfix);

    return 0;
}

void evaluate()
{
    int i, j = 0;
    char symbol, temp;

    push('#');

    for (i = 0; infix[i] != '\0'; i++)
    {
        symbol = infix[i];

        switch (symbol)
        {
            case '(':
                push(symbol);
                break;

            case ')':
                temp = pop();
                while (temp != '(')
                {
                    postfix[j++] = temp;
                    temp = pop();
                }
                break;

            case '+':
            case '-':
            case '*':
            case '/':
            case '^':
            case '$':
                while (prec(stack[top]) >= prec(symbol))
                {
                    postfix[j++] = pop();
                }
                push(symbol);
                break;

            default:
                postfix[j++] = symbol;
        }
    }

    while (top > 0)
    {
        postfix[j++] = pop();
    }

    postfix[j] = '\0';
}

void push(char item)
{
    top++;
    stack[top] = item;
}

char pop(void)
{
    return stack[top--];
}

int prec(char symbol)
{
    switch (symbol)
    {
        case '#':
            return -1;
        case '(':
        case ')':
            return 0;
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
        case '%':
            return 2;
        case '^':
        case '$':
            return 3;
        default:
            return -1;
    }
}
