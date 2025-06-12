#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node* next;
}Node;

Node* creatNode(int value){
    Node* newNode = (Node*)malloc(sizeof(Node));
    if(!newNode){
        printf("Memory allocation failed!\n");
        return NULL;
    }
    newNode -> data = value;
    newNode -> next = NULL;
    return newNode;
}

void InsertAtBeg(Node** head, int value){
    Node* newNode = creatNode(value);
    newNode -> next = *head;
    *head = newNode;
}

void InsertAtEnd(Node** head, int value){
    Node* newNode = creatNode(value);
    if(*head == NULL){
        *head = newNode;
        return;
    }
    Node* temp = *head;
    while(temp -> next != NULL){
        temp = temp -> next;
    }
    temp -> next = newNode;
}

void InsertAtPos(Node** head, int value, int pos){
    if(pos < 1){
        printf("Invalid position!\n");
        return;
    }
    else if(pos == 1){
        InsertAtBeg(head, value);
        return;
    }
    Node* newNode = creatNode(value);
    Node* temp = *head;
    for(int i = 0; i < pos - 1; i++){
        if(temp == NULL){
            printf("Position out of bound!\n");
            free(newNode);
            return;
        }
        temp = temp -> next;
    }
    if(temp == NULL){
        printf("Position out of bound!\n");
        free(newNode);
        return;
    }
    newNode -> next = temp -> next;
    temp -> next = newNode;
}

void DeleteFromEnd(Node** head){
    if(*head == NULL){
        printf("List is Empty!\n");
        return;
    }
    if((*head) -> next == NULL){
        free(*head);
        *head = NULL;
        return;
    }
    Node* temp = *head;
    while(temp -> next -> next != NULL){
        temp = temp -> next;
    }
    free(temp -> next);
    temp -> next = NULL;
}

void DeleteFromBeg(Node** head){
    if(*head == NULL){
        printf("List is Empty!\n");
        return;
    }
    Node* temp = *head;
    *head = temp -> next;
    free(temp);
}

void DeleteFromPos(Node** head, int pos){
    if(*head == NULL){
        printf("List is Empty!\n");
        return;
    }
    if(pos < 1){
        printf("Invalid position\n");
        return;
    }
    if(pos == 1){
        DeleteFromBeg(head);
        return;
    }
    Node* temp = *head;
    for(int i = 0; i < pos - 1; i++){
        if(temp == NULL || temp -> next == NULL){
            printf("Position out of bounds\n");
            return;
        }
        temp = temp -> next;
    }
    Node* nodeToDelete = temp -> next;
    if(nodeToDelete == NULL){
        printf("Position out of bounds\n");
        return;
    }
    temp -> next = nodeToDelete -> next;
    free(nodeToDelete);
}

void display(Node** head){
    if(*head == NULL){
        printf("List is Empty!\n");
        return;
    }
    Node* temp = *head;
    printf("Link List: ");
    while(temp != NULL){
        printf("%d -> ", temp -> data);
        temp = temp -> next;
    }
    printf("NULL\n");
}

int main() {
    Node* head = NULL;
    int choice, data, position;

    while (1) {
        printf("\n--- Linked List Menu ---\n");
        printf("1. Insert at beginning\n");
        printf("2. Insert at end\n");
        printf("3. Insert at position\n");
        printf("4. Delete from beginning\n");
        printf("5. Delete from end\n");
        printf("6. Delete from position\n");
        printf("7. Traverse\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data: ");
                scanf("%d", &data);
                InsertAtBeg(&head, data);
                break;

            case 2:
                printf("Enter data: ");
                scanf("%d", &data);
                InsertAtEnd(&head, data);
                break;

            case 3:
                printf("Enter data and position: ");
                scanf("%d %d", &data, &position);
                InsertAtPos(&head, data, position);
                break;

            case 4:
                DeleteFromBeg(&head);
                break;

            case 5:
                DeleteFromEnd(&head);
                break;

            case 6:
                printf("Enter position: ");
                scanf("%d", &position);
                DeleteFromPos(&head, position);
                break;

            case 7:
                display(&head);
                break;

            case 0:
                printf("Exiting...\n");
                exit(0);

            default:
                printf("Invalid choice! Try again.\n");
        }
    }

    return 0;
}