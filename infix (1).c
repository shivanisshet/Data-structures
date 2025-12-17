#include <stdio.h>
#include <ctype.h>  
#include <string.h> 

#define MAX 100

char stack[MAX];
int top = -1;

void push(char c) {
    if (top == MAX - 1)
        printf("Stack Overflow\n");
    else
        stack[++top] = c;
}

char pop() {
    if (top == -1)
        return -1;
    else
        return stack[top--];
}

int precedence(char c) {
    if (c == '^')
        return 3;
    else if (c == '*' || c == '/')
        return 2;
    else if (c == '+' || c == '-')
        return 1;
    else
        return 0;
}

int main() {
    char exp[100];
    char *e, x;

    printf("Enter infix expression: ");
    scanf("%s", exp);

    printf("Postfix expression: ");
    e = exp;

    while (*e != '\0') {
        if (isalnum(*e))
            printf("%c", *e);
        else if (*e == '(')
            push(*e);
        else if (*e == ')') {
            while ((x = pop()) != '(')
                printf("%c", x);
        } else {
            while (precedence(stack[top]) >= precedence(*e))
                printf("%c", pop());
            push(*e);
        }
        e++;
    }

    while (top != -1)
        printf("%c", pop());

    printf("\n");
    return 0;
}

