#include <stdio.h> 
#include <stdlib.h> 
 
#define MAX 100 
 
int queue[MAX]; 
int front = -1, rear = -1; 
 
void insert(int value) { 
    if (rear == MAX - 1) { 
        printf("Queue Overflow\n"); 
    } else { 
        if (front == -1) front = 0; 
        queue[++rear] = value; 
        printf("%d inserted into queue\n", value); 
    } 
} 
 
void delete() { 
    if (front == -1 || front > rear) { 
        printf("Queue Empty\n"); 
    } else { 
        printf("%d deleted from queue\n", queue[front++]); 
        if (front > rear) front = rear = -1; 
    } 
} 
 
void display() { 
    if (front == -1 || front > rear) { 
        printf("Queue is empty\n"); 
    } else { 
        printf("Queue elements: "); 
        for (int i = front; i <= rear; i++) { 
            printf("%d ", queue[i]); 
        } 
        printf("\n"); 
    } 
} 
 
int main() { 
    int choice, value; 
 
    while (1) { 
22 
 
        printf("\n1. Insert 2. Delete 3. Display 4. Exit\n"); 
        printf("Enter your choice: "); 
        scanf("%d", &choice); 
 
        switch (choice) { 
            case 1: 
                printf("Enter value to insert: "); 
                scanf("%d", &value); 
                insert(value); 
                break; 
            case 2: 
                delete(); 
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