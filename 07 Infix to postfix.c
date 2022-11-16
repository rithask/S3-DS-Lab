// Using stack convert an infix expression to a postfix expression
// and evaluate the postfix expression

/*
ALGORITHM

Algorithm for main
1. Start
2. Declare variables
3. Display Enter infix expression
4. Read infix expression
5. Call infix_to_postfix() function
6. Display postfix expression
7. Display result
8. Stop

Algorithm for push
1. Start
2. If top is equal to size - 1, display Stack overflow
3. Else
    3.1. Increment top
    3.2. Set stack[top] = data
4. Stop

Algorithm for pop
1. Start
2. If top is equal to -1, display Stack underflow
3. Else
    3.1. Set data = stack[top]
    3.2. Decrement top
    3.3. Return data
4. Stop

Algorithm to check if the character is an operator
1. Start
2. If character is equal to + or - or * or / or % or ^
    2.1. Return 1
3. Else
    3.1. Return 0
4. Stop

Algorithm to check the precedence of the operator
1. Start
2. If operator is equal to + or -
    2.1. Return 1
3. Else if operator is equal to * or /
    3.1. Return 2
4. Else if operator is equal to ^
    4.1. Return 3
5. Else
    5.1. Return 0
6. Stop

Algorithm to convert infix to postfix
1. Start
2. Set i = 0, j = 0
3. Push '(' to stack
4. Push ')' to infix
5. Set item = infix[i]
6. While item is not equal to '\0'
    6.1. If item is alphabet or digit
        6.1.1. Set postfix[j] = item
        6.1.2. Increment j
    6.2. Else if item is '('
        6.2.1. Push item to stack
    6.3. Else if item is ')'
        6.3.1. Set temp = pop()
        6.3.2. While temp is not equal to '('
            i. Set postfix[j] = temp
            ii. Increment j
    6.4. Else if item is operator
        6.4.1. Set temp = pop()
        6.4.2. While precedence of temp is greater than or equal to precedence of item
            i. Set postfix[j] = temp
            ii. Increment j
            iii. Set temp = pop()
        6.4.3. Push temp to stack
        6.4.4. Push item to stack
    6.5. Increment i
    6.6. Set item = infix[i]
7. Set postfix[j] = '\0'
8. Stop
*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define SIZE 100

char stack[SIZE];
int top = -1;

void push(char c);
char pop();
int is_operator(char c);
int precedence(char c);
void infix_to_postfix(char *infix, char *postfix);

int main()
{
    char infix[SIZE], postfix[SIZE];
    printf("Enter infix expression: ");
    scanf("%s", infix);
    infix_to_postfix(infix, postfix);
    printf("Postfix expression: %s\n", postfix);
    return 0;
}

void push(char c)
{
    if(top == SIZE-1)
    {
        printf("Stack Overflow\n");
        return;
    }
    top++;
    stack[top] = c;
}

char pop()
{
    if(top == -1)
    {
        printf("Stack Underflow\n");
        return -1;
    }
    char c = stack[top];
    top--;
    return c;
}

int is_operator(char c)
{
    if(c == '+' || c == '-' || c == '*' || c == '/' || c == '^')
        return 1;
    return 0;
}

int precedence(char c)
{
    if(c == '^')
        return 3;
    else if(c == '*' || c == '/')
        return 2;
    else if(c == '+' || c == '-')
        return 1;
    else
        return 0;
}

void infix_to_postfix(char *infix, char *postfix)
{
    int i = 0, j = 0;
    char c;
    char item = infix[i];
    push('(');
    strcat(infix, ")");

    while(item != '\0')
    {
        if(isalnum(item))
            postfix[j++] = item;
        else if(item == '(')
        {
            push(item);
        }
        else if(item == ')')
        {
            while((c = pop()) != '(')
                postfix[j++] = c;
        }
        else if (is_operator(item) == 1)
        {
            char x = pop();
            while(is_operator(x) == 1 && precedence(x) >= precedence(item))
            {
                postfix[j++] = x;
                x = pop();
            }
            push(x);
            push(item);
        }
        i++;
        item = infix[i];
    }
    postfix[j] = '\0';
}