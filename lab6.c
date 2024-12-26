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
 
void deleteFirst(struct Node** head) { 
    if (*head == NULL) { 
        printf("List is empty\n"); 
        return; 
    } 
    struct Node* temp = *head; 
    *head = (*head)->next; 
    free(temp); 
} 
 
void deleteLast(struct Node** head) { 
    if (*head == NULL) { 
        printf("List is empty\n"); 
        return; 
    } 
50 
 
    if ((*head)->next == NULL) { 
        free(*head); 
        *head = NULL; 
        return; 
    } 
    struct Node* temp = *head; 
    while (temp->next->next != NULL) { 
        temp = temp->next; 
    } 
    free(temp->next); 
    temp->next = NULL; 
} 
 
void deleteElement(struct Node** head, int value) { 
    if (*head == NULL) { 
        printf("List is empty\n"); 
        return; 
    } 
    if ((*head)->data == value) { 
        deleteFirst(head); 
        return; 
    } 
    struct Node* temp = *head; 
    while (temp->next != NULL && temp->next->data != value) { 
        temp = temp->next; 
    } 
    if (temp->next == NULL) { 
        printf("Element not found\n"); 
        return; 
    } 
    struct Node* delNode = temp->next; 
    temp->next = temp->next->next; 
    free(delNode); 
} 
 
void display(struct Node* head) { 
    if (head == NULL) { 
        printf("List is empty\n"); 
    } else { 
        struct Node* temp = head; 
        printf("Linked List: "); 
        while (temp != NULL) { 
            printf("%d ", temp->data); 
51 
 
            temp = temp->next; 
        } 
        printf("\n"); 
    } 
} 
 
int main() { 
    struct Node* head = NULL; 
    int choice, data; 
 
    while (1) { 
        printf("\n1. Insert at end\n2. Delete first element\n3. Delete last element\n4. Delete 
specified element\n5. Display\n6. Exit\n"); 
        printf("Enter your choice: "); 
        scanf("%d", &choice); 
 
        switch (choice) { 
            case 1: 
                printf("Enter data: "); 
                scanf("%d", &data); 
                insertAtEnd(&head, data); 
                break; 
            case 2: 
                deleteFirst(&head); 
                break; 
            case 3: 
                deleteLast(&head); 
                break; 
            case 4: 
                printf("Enter element to delete: "); 
                scanf("%d", &data); 
                deleteElement(&head, data); 
                break; 
            case 5: 
                display(head); 
                break; 
            case 6: 
                exit(0); 
            default: 
                printf("Invalid choice\n"); 
        } 
    } 
 
52 
 
    return 0; 
} 
 
