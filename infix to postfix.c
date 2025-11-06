#include <stdio.h>
#define MAX 20
char stk[MAX];
int top = -1;
int isEmpty() 
{
    return top == -1;
}
int isFull()
{
    return top == MAX - 1;
}
char peek() 
{
    return stk[top];
}
char pop() 
{
    if (isEmpty())
        return -1;
    else
		return stk[top--];
}
void push(char oper)
{
    if (isFull())
        printf("Stack Full!\n");
    else
        stk[++top] = oper;
}
int checkIfOperand(char ch) 
{
    return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z');
}
int precedence(char ch) 
{
    switch (ch) 
	{
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        case '^':
            return 3;
    }
    return -1;
}
void convertInfixToPostfix(char* infix) 
{
    int i, j = 0;
    char postfix[MAX];
    for (i = 0; infix[i]; ++i) 
	{
        if (checkIfOperand(infix[i]))
            postfix[j++] = infix[i];
        else if (infix[i] == '(')
            push(infix[i]);
        else if (infix[i] == ')') 
		{
            while (!isEmpty() && peek() != '(')
                postfix[j++] = pop();
            if (!isEmpty() && peek() == '(')
                pop();
        } 
		else
		{
            while (!isEmpty() && precedence(infix[i]) <= precedence(peek()))
                postfix[j++] = pop();
            push(infix[i]);
        }
    }
    while (!isEmpty())
        postfix[j++] = pop();
    postfix[j] = '\0';
    printf("Postfix expression: %s\n", postfix);
}
int main()
{
    char infix[15];
    printf("Enter an infix expression: ");
    scanf("%s", infix);
    convertInfixToPostfix(infix);
    return 0;
}

