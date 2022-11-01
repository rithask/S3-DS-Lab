// Using stack convert an infix expression to a postfix expression and evaluate the postfix expression

/*
ALGORITHM

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX 100

typedef struct stack
{
    int top;
    char data[MAX];
}stack;

void push(stack *s, char c)
{
    if(s->top == MAX-1)
    {
        printf("Stack Overflow\n");
        return;
    }
    s->top++;
    s->data[s->top] = c;
}

char pop(stack *s)
{
    if(s->top == -1)
    {
        printf("Stack Underflow\n");
        return -1;
    }
    char c = s->data[s->top];
    s->top--;
    return c;
}

int isOperator(char c)
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

void infixToPostfix(char *infix, char *postfix)
{
    stack s;
    s.top = -1;
    int i = 0, j = 0;
    while(infix[i] != '\0')
    {
        if(isalnum(infix[i]))
            postfix[j++] = infix[i++];
        else if(infix[i] == '(')
        {
            push(&s, infix[i]);
            i++;
        }
        else if(infix[i] == ')')
        {
            while(s.data[s.top] != '(')
                postfix[j++] = pop(&s);
            pop(&s);
            i++;
        }
        else if(isOperator(infix[i]))
        {
            if(precedence(infix[i]) > precedence(s.data[s.top]))
                push(&s, infix[i++]);
            else
                postfix[j++] = pop(&s);
        }
    }
    while(s.top != -1)
        postfix[j++] = pop(&s);
    postfix[j] = '\0';
}

int evaluatePostfix(char *postfix)
{
    stack s;
    s.top = -1;
    int i = 0;
    while(postfix[i] != '\0')
    {

        if(isdigit(postfix[i]))
            push(&s, postfix[i] - '0');
        else
        {
            int op2 = pop(&s);
            int op1 = pop(&s);
            switch(postfix[i])
            {
                case '+': push(&s, op1 + op2); break;
                case '-': push(&s, op1 - op2); break;
                case '*': push(&s, op1 * op2); break;
                case '/': push(&s, op1 / op2); break;
                case '^': push(&s, op1 ^ op2); break;
            }
        }
        i++;
    }
    return pop(&s);
}

int main()
{
    char infix[MAX], postfix[MAX];
    printf("Enter the infix expression: ");
    scanf("%s", infix);
    infixToPostfix(infix, postfix);
    printf("Postfix expression: %s\n", postfix);
    // printf("Value of the expression: %d\n", evaluatePostfix(postfix));
    return 0;
}