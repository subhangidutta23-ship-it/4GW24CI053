#include <stdio.h>
#include <ctype.h>
#include <math.h>

#define MAX 100

int stack[MAX];
int top = -1;

void push(int val)
{
    stack[++top] = val;
}

int pop(void)
{
    return stack[top--];
}

int power(int base, int exp)
{
    int result = 1;
    for (int i = 0; i < exp; i++)
        result *= base;
    return result;
}

int evaluatePostfix(char *exp)
{
    int i;

    for (i = 0; exp[i] != '\0'; i++)
    {
        char ch = exp[i];

        if (isdigit(ch))
        {
            push(ch - '0');
        }
        else
        {
            int val2 = pop();
            int val1 = pop();
            int result;

            switch (ch)
            {
            case '+': result = val1 + val2; break;
            case '-': result = val1 - val2; break;
            case '*': result = val1 * val2; break;
            case '/': result = val1 / val2; break;
            case '%': result = val1 % val2; break;
            case '^': result = power(val1, val2); break;
            default:
                printf("Invalid operator\n");
                return -1;
            }
            push(result);
        }
    }
    return pop();
}

int main()
{
    char exp[MAX];

    printf("Enter postfix expression: ");
    scanf("%s", exp);

    printf("Result = %d\n", evaluatePostfix(exp));

    return 0;
}
