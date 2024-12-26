#include <stdio.h> 
#include <stdlib.h> 
 
struct Node { 
    int data; 
    struct Node* next; 
}; 
 
struct Node* createNode(int data) { 
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node)); 
    newNode->data = data; 
    newNode->next = NULL; 
    return newNode; 
} 
 
void push(struct Node** top, int data) { 
    struct Node* newNode = createNode(data); 
    newNode->next = *top; 
    *top = newNode; 
} 
 
int pop(struct Node** top) { 
    if (*top == NULL) { 
        printf("Stack Underflow\n"); 
        return -1; 
    } 
    struct Node* temp = *top; 
    int data = temp->data; 
    *top = (*top)->next; 
    free(temp); 
    return data; 
} 
 
void displayStack(struct Node* top) { 
    if (top == NULL) { 
        printf("Stack is empty\n"); 
    } else { 
        printf("Stack: "); 
        while (top != NULL) { 
            printf("%d ", top->data); 
            top = top->next; 
        } 
73 
 
        printf("\n"); 
    } 
} 
 
void enqueue(struct Node** front, struct Node** rear, int data) { 
    struct Node* newNode = createNode(data); 
    if (*rear == NULL) { 
        *front = *rear = newNode; 
    } else { 
        (*rear)->next = newNode; 
        *rear = newNode; 
    } 
} 
 
int dequeue(struct Node** front, struct Node** rear) { 
    if (*front == NULL) { 
        printf("Queue Underflow\n"); 
        return -1; 
    } 
    struct Node* temp = *front; 
    int data = temp->data; 
    *front = (*front)->next; 
    if (*front == NULL) { 
        *rear = NULL; 
    } 
    free(temp); 
    return data; 
} 
 
void displayQueue(struct Node* front) { 
    if (front == NULL) { 
        printf("Queue is empty\n"); 
    } else { 
        printf("Queue: "); 
        while (front != NULL) { 
            printf("%d ", front->data); 
            front = front->next; 
        } 
        printf("\n"); 
    } 
} 
 
int main() { 
74 
 
    struct Node* stackTop = NULL; 
    struct Node* queueFront = NULL; 
    struct Node* queueRear = NULL; 
    int choice, data; 
 
    while (1) { 
        printf("\n1. Push to Stack 2. Pop from Stack 3. Display Stack\n"); 
        printf("4. Enqueue to Queue 5. Dequeue from Queue 6. Display Queue 7. Exit\n"); 
        printf("Enter your choice: "); 
        scanf("%d", &choice); 
 
        switch (choice) { 
            case 1: 
                printf("Enter data to push: "); 
                scanf("%d", &data); 
                push(&stackTop, data); 
                break; 
            case 2: 
                data = pop(&stackTop); 
                if (data != -1) { 
                    printf("Popped: %d\n", data); 
                } 
                break; 
            case 3: 
                displayStack(stackTop); 
                break; 
            case 4: 
                printf("Enter data to enqueue: "); 
                scanf("%d", &data); 
                enqueue(&queueFront, &queueRear, data); 
                break; 
            case 5: 
                data = dequeue(&queueFront, &queueRear); 
                if (data != -1) { 
                    printf("Dequeued: %d\n", data); 
                } 
                break; 
            case 6: 
                displayQueue(queueFront); 
                break; 
            case 7: 
                exit(0); 
            default: 
75 
 
                printf("Invalid choice\n"); 
        } 
    } 
 
    return 0; 
} 
 
 
