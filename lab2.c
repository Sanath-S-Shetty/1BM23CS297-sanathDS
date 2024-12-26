#include <stdio.h> 
#include <ctype.h> 
#include <stdlib.h> 
#include <string.h> 
 
#define MAX 100 
 
char stack[MAX]; 
int top = -1; 
 
void push(char c) { 
    if (top == MAX - 1) { 
        printf("Stack Overflow\n"); 
        exit(1); 
    } else { 
        stack[++top] = c; 
    } 
} 
 
char pop() { 
    if (top == -1) { 
        printf("Stack Underflow\n"); 
        exit(1); 
    } else { 
        return stack[top--]; 
    } 
} 
 
int precedence(char op) { 
    if (op == '+' || op == '-') return 1; 
    if (op == '*' || op == '/') return 2; 
    if (op == '^') return 3; 
    return 0; 
} 
 
void infixToPostfix(char infix[], char postfix[]) { 
    int i = 0, j = 0; 
    char c; 
 
    while (infix[i] != '\0') { 
        c = infix[i]; 
        if (isalnum(c)) { 
            postfix[j++] = c; 
14 
 
        } else if (c == '(') { 
            push(c); 
        } else if (c == ')') { 
            while (top != -1 && stack[top] != '(') { 
                postfix[j++] = pop(); 
            } 
            if (top == -1) { 
                printf("Invalid expression: Unmatched parenthesis\n"); 
                exit(1); 
            } 
            pop(); 
        } else { 
            while (top != -1 && precedence(stack[top]) >= precedence(c) && stack[top] != '(') { 
                postfix[j++] = pop(); 
            } 
            push(c); 
        } 
        i++; 
    } 
 
    while (top != -1) { 
        if (stack[top] == '(') { 
            printf("Invalid expression: Unmatched parenthesis\n"); 
            exit(1); 
        } 
        postfix[j++] = pop(); 
    } 
    postfix[j] = '\0'; 
} 
 
int main() { 
    char infix[] = "a+b*(c^d-e)^(f+g*h)-c"; 
    char postfix[MAX]; 
 
    infixToPostfix(infix, postfix); 
 
    printf("Infix Expression: %s\n", infix); 
    printf("Postfix Expression: %s\n", postfix); 
 
    return 0; 
} 