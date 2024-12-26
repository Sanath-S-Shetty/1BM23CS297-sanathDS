 #include <stdio.h> 
#include <stdlib.h> 
 
#define MAX 5 
 
int queue[MAX]; 
int front = -1, rear = -1; 
 
void insert(int value) { 
    if ((rear + 1) % MAX == front) { 
        printf("Queue Overflow\n"); 
    } else { 
        if (front == -1) front = 0; 
        rear = (rear + 1) % MAX; 
        queue[rear] = value; 
        printf("%d inserted into queue\n", value); 
    } 
} 
 
void delete() { 
    if (front == -1) { 
        printf("Queue Empty\n"); 
    } else { 
        printf("%d deleted from queue\n", queue[front]); 
        if (front == rear) { 
            front = rear = -1; 
        } else { 
            front = (front + 1) % MAX; 
        } 
    } 
} 
 
void display() { 
    if (front == -1) { 
        printf("Queue is empty\n"); 
    } else { 
        printf("Queue elements: "); 
        int i = front; 
        while (1) { 
            printf("%d ", queue[i]); 
            if (i == rear) break; 
29 
 
            i = (i + 1) % MAX; 
        } 
        printf("\n"); 
    } 
} 
 
int main() { 
    int choice, value; 
 
    while (1) { 
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