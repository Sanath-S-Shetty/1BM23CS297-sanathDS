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
 
void sortList(struct Node** head) { 
    if (*head == NULL) return; 
    struct Node* current = *head; 
    struct Node* index = NULL; 
    int temp; 
     
    while (current != NULL) { 
        index = current->next; 
        while (index != NULL) { 
            if (current->data > index->data) { 
                temp = current->data; 
                current->data = index->data; 
                index->data = temp; 
61 
 
            } 
            index = index->next; 
        } 
        current = current->next; 
    } 
} 
 
void reverseList(struct Node** head) { 
    struct Node* prev = NULL; 
    struct Node* current = *head; 
    struct Node* next = NULL; 
     
    while (current != NULL) { 
        next = current->next; 
        current->next = prev; 
        prev = current; 
        current = next; 
    } 
    *head = prev; 
} 
 
void concatenateLists(struct Node** head1, struct Node** head2) { 
    if (*head1 == NULL) { 
        *head1 = *head2; 
    } else { 
        struct Node* temp = *head1; 
        while (temp->next != NULL) { 
            temp = temp->next; 
        } 
        temp->next = *head2; 
    } 
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
62 
 
        printf("\n"); 
    } 
} 
 
int main() { 
    struct Node* head1 = NULL; 
    struct Node* head2 = NULL; 
    int choice, data; 
 
    while (1) { 
        printf("\n1. Insert into List 1\n2. Insert into List 2\n3. Sort List 1\n4. Reverse List 1\n5. 
Concatenate List 1 and List 2\n6. Display List 1\n7. Display List 2\n8. Exit\n"); 
        printf("Enter your choice: "); 
        scanf("%d", &choice); 
 
        switch (choice) { 
            case 1: 
                printf("Enter data for List 1: "); 
                scanf("%d", &data); 
                insertAtEnd(&head1, data); 
                break; 
            case 2: 
                printf("Enter data for List 2: "); 
                scanf("%d", &data); 
                insertAtEnd(&head2, data); 
                break; 
            case 3: 
                sortList(&head1); 
                break; 
            case 4: 
                reverseList(&head1); 
                break; 
            case 5: 
                concatenateLists(&head1, &head2); 
                break; 
            case 6: 
                display(head1); 
                break; 
            case 7: 
                display(head2); 
                break; 
            case 8: 
63 
 
                exit(0); 
            default: 
                printf("Invalid choice\n"); 
        } 
    } 
 
    return 0;
}