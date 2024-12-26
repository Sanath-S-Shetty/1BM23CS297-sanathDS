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
 
void insertAtBeginning(struct Node** head, int data) { 
    struct Node* newNode = createNode(data); 
    newNode->next = *head; 
    *head = newNode; 
} 
 
void insertAtEnd(struct Node** head, int data) { 
    struct Node* newNode = createNode(data); 
    if (*head == NULL) { 
        *head = newNode; 
    } else { 
        struct Node* temp = *head; 
        while (temp->next != NULL) { 
            temp = temp->next; 
        } 
        temp->next = newNode; 
    } 
} 
 
void insertAtPosition(struct Node** head, int data, int pos) { 
    struct Node* newNode = createNode(data); 
    if (pos == 1) { 
        newNode->next = *head; 
        *head = newNode; 
        return; 
    } 
 
    struct Node* temp = *head; 
39 
 
    for (int i = 1; i < pos - 1 && temp != NULL; i++) { 
        temp = temp->next; 
    } 
 
    if (temp == NULL) { 
        printf("Position out of range\n"); 
        return; 
    } 
 
    newNode->next = temp->next; 
    temp->next = newNode; 
} 
 
void display(struct Node* head) { 
    if (head == NULL) { 
        printf("List is empty\n"); 
    } else { 
        struct Node* temp = head; 
        printf("Linked List: "); 
        while (temp != NULL) { 
            printf("%d ", temp->data); 
            temp = temp->next; 
        } 
        printf("\n"); 
    } 
} 
 
int main() { 
    struct Node* head = NULL; 
    int choice, data, pos; 
 
    while (1) { 
        printf("\n1. Insert at beginning\n2. Insert at end\n3. Insert at position\n4. Display\n5. 
Exit\n"); 
        printf("Enter your choice: "); 
        scanf("%d", &choice); 
 
        switch (choice) { 
            case 1: 
                printf("Enter data: "); 
                scanf("%d", &data); 
                insertAtBeginning(&head, data); 
                break; 
40 
 
            case 2: 
                printf("Enter data: "); 
                scanf("%d", &data); 
                insertAtEnd(&head, data); 
                break; 
            case 3: 
                printf("Enter data and position: "); 
                scanf("%d %d", &data, &pos); 
                insertAtPosition(&head, data, pos); 
                break; 
            case 4: 
                display(head); 
                break; 
            case 5: 
                exit(0); 
            default: 
                printf("Invalid choice\n"); 
        } 
    } 
 
    return 0; 
} 
 