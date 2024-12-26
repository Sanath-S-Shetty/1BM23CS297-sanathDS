#include <stdio.h> 
#include <stdlib.h> 
 
typedef struct Node { 
    int data; 
    struct Node* prev; 
    struct Node* next; 
} Node; 
 
Node* createNode(int data) { 
    Node* newNode = (Node*)malloc(sizeof(Node)); 
    newNode->data = data; 
    newNode->prev = NULL; 
    newNode->next = NULL; 
    return newNode; 
} 
 
void insertAtBeginning(Node** head, int data) { 
    Node* newNode = createNode(data); 
    if (*head != NULL) { 
        newNode->next = *head; 
        (*head)->prev = newNode; 
    } 
    *head = newNode; 
} 
 
void insertAtEnd(Node** head, int data) { 
    Node* newNode = createNode(data); 
    if (*head == NULL) { 
        *head = newNode; 
        return; 
    } 
    Node* temp = *head; 
    while (temp->next != NULL) { 
        temp = temp->next; 
    } 
    temp->next = newNode; 
    newNode->prev = temp; 
} 
 
void insertAtPosition(Node** head, int data, int position) { 
    if (position == 1) { 
        insertAtBeginning(head, data); 
84 
 
        return; 
    } 
    Node* newNode = createNode(data); 
    Node* temp = *head; 
    for (int i = 1; i < position - 1 && temp != NULL; i++) { 
        temp = temp->next; 
    } 
    if (temp == NULL) { 
        return; 
    } 
    newNode->next = temp->next; 
    if (temp->next != NULL) { 
        temp->next->prev = newNode; 
    } 
    temp->next = newNode; 
    newNode->prev = temp; 
} 
 
void displayList(Node* head) { 
    Node* temp = head; 
    while (temp != NULL) { 
        printf("%d ", temp->data); 
        temp = temp->next; 
    } 
    printf("\n"); 
} 
 
int main() { 
    Node* head = NULL; 
    int choice, data, position; 
    while (1) { 
        printf("\nMenu:\n"); 
        printf("1. Insert at beginning\n"); 
        printf("2. Insert at end\n"); 
        printf("3. Insert at specific position\n"); 
        printf("4. Display list\n"); 
        printf("5. Exit\n"); 
        printf("Enter your choice: "); 
        scanf("%d", &choice); 
        switch (choice) { 
            case 1: 
                printf("Enter data to insert at beginning: "); 
                scanf("%d", &data); 
85 
 
                insertAtBeginning(&head, data); 
                break; 
            case 2: 
                printf("Enter data to insert at end: "); 
                scanf("%d", &data); 
                insertAtEnd(&head, data); 
                break; 
            case 3: 
                printf("Enter data to insert: "); 
                scanf("%d", &data); 
                printf("Enter position to insert at: "); 
                scanf("%d", &position); 
                insertAtPosition(&head, data, position); 
                break; 
            case 4: 
                printf("List contents: "); 
                displayList(head); 
                break; 
            case 5: 
                exit(0); 
            default: 
                printf("Invalid choice, please try again.\n"); 
        } 
    } 
    return 0; 
}