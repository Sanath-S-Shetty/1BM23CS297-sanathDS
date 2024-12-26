#include <stdio.h> 
#include <stdlib.h> 
 
#define MAX 100 
 
int stack[MAX]; 
int top = -1; 
 
void push(int value) { 
    if (top == MAX - 1) { 
        printf("Stack Overflow\n"); 
    } else { 
        stack[++top] = value; 
        printf("%d pushed to stack\n", value); 
    } 
} 
 
void pop() { 
    if (top == -1) { 
        printf("Stack Underflow\n"); 
    } else { 
        printf("%d popped from stack\n", stack[top--]); 
    } 
} 
 
void display() { 
    if (top == -1) { 
        printf("Stack is empty\n"); 
    } else { 
        printf("Stack elements: "); 
        for (int i = top; i >= 0; i--) { 
            printf("%d ", stack[i]); 
        } 
        printf("\n"); 
    } 
} 
 
int main() { 
    int choice, value; 
 
    while (1) { 
        printf("\n1. Push\n2. Pop\n3. Display\n4. Exit\n"); 
6 
 
        printf("Enter your choice: "); 
        scanf("%d", &choice); 
 
        switch (choice) { 
            case 1: 
                printf("Enter value to push: "); 
                scanf("%d", &value); 
                push(value); 
                break; 
            case 2: 
                pop(); 
                break; 
            case 3: 
                display(); 
                break; 
            case 4: 
                exit(0); 
            default: 
                printf("Invalid choice\n"); 
        } 
    } 
 
    return 0; 
}