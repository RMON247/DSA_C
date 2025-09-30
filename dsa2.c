#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX 100

char stack[MAX];
int top = -1;

void push(char c) {
    stack[++top] = c;
}

char pop() {
    return stack[top--];
}

int precedence(char c) {
    if (c == '^') return 3;
    if (c == '*' || c == '/') return 2;
    if (c == '+' || c == '-') return 1;
    return -1;
}

void infixToPostfix(char infix[]) {
    char postfix[MAX];
    int i, k = 0;
    for (i = 0; infix[i] != '\0'; i++) {
        char c = infix[i];

        if (isalnum(c)) {               // Operand
            postfix[k++] = c;
        }
        else if (c == '(') {            // Left bracket
            push(c);
        }
        else if (c == ')') {            // Right bracket
            while (top != -1 && stack[top] != '(') {
                postfix[k++] = pop();
            }
            pop(); // Remove '('
        }
        else {                          // Operator
            while (top != -1 && precedence(stack[top]) >= precedence(c)) {
                postfix[k++] = pop();
            }
            push(c);
        }
    }
    while (top != -1) {
        postfix[k++] = pop();
    }
    postfix[k] = '\0';
    printf("Postfix Expression: %s\n", postfix);
}

int main() {
    char infix[MAX];
    printf("Enter Infix Expression: ");
    scanf("%s", infix);

    infixToPostfix(infix);

    return 0;
}