#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct Node{
    int data;
    struct Node* next;
}Node;

typedef struct{
    Node* front;
    Node* rear;
}Queue;

void _init_(Queue* q){
    q -> front = q -> rear = NULL;
}

void enqueue(Queue* q, int value){
    Node* newNode = (Node*)malloc(sizeof(Node));
    if(!newNode){
        printf("Memory Allocation failed!\n");
        return;
    }
    newNode -> data = value;
    newNode -> next = NULL;

    if(q -> rear == NULL){
        q -> front = q -> rear = newNode;
    }
    else{
        q -> rear -> next = newNode;
        q -> rear = newNode;
    }
    printf("%d is enqueued\n", value);
}

void dequeue(Queue* q){
    if(q -> front == NULL){
        printf("Underflow!\n");
    }
    Node* temp = q -> front;
    printf("%d is dequeued\n", temp -> data);
    q -> front = temp -> next;

    if(q -> front == NULL){
        q -> rear = NULL;
    }
    free(temp);
}

void peek(Queue* q){
    if(q -> front == NULL){
        printf("Queue is Empty!\n");
    }
    else{
        printf("Front of Queue: %d", q -> front -> data);
    }
}

void display(Queue* q){
    if(q -> front == NULL){
        printf("Queue is Empty!\n");
    }
    Node* temp = q -> front;
    printf("Queue: ");
    while(temp != NULL){
        printf("%d ", temp -> data);
        temp = temp -> next;
    }
    printf("\n");
}

int main(){
    Queue queue;
    _init_(&queue);
    int choice, value;

    while(1){
        printf("---Queue Menu---\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Peek\n");
        printf("5. Exit\n");
        printf("Enter operation to use(1 , 2, 3, 4): ");
        scanf("%d", &choice);

        if(choice  == 1){
            printf("Enter value: ");
            scanf("%d", &value);
            enqueue(&queue, value);
        }
        else if(choice == 2){
            dequeue(&queue);
        }
        else if(choice == 3){
            display(&queue);
        }
        else if(choice == 4){
            peek(&queue);
        }
        else if(choice == 5){
            printf("Exiting...\n");
            break;
        }
        else{
            printf("Invalid Choice!");
        }
        printf("\n");
    }

    return 0;
}