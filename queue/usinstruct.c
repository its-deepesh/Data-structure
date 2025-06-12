#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct{
    int queue[MAX];
    int front;
    int rear;
}Queue;

void _init_(Queue* q){
    q -> front = -1;
    q -> rear = -1;
}

void enqueue(Queue* q, int value){
    if(q -> rear == MAX - 1){
        printf("Overflow!\n");
    }
    else{
        if(q -> front == -1){
            q -> front = 0;
        }
        q -> rear++;
        q -> queue[q -> rear] = value;
        printf("%d is enqueued\n", value);
    }
}

void dequeue(Queue* q){
    if(q -> front == -1 || q -> front > q -> rear){
        printf("Underflow!\n");
    }
    else{
        printf("%d is dequeued\n", q -> queue[q -> front]);
        q -> front++;
    }
}

void peek(Queue* q){
    if(q -> front == -1 || q -> front > q -> rear){
        printf("Queue is Empty!\n");
    }
    else{
        printf("Top of Queue: %d", q -> front);
    }
}

void display(Queue* q){
    if(q -> front == -1 || q -> front > q -> rear){
        printf("Queue is Empty!\n");
    }
    else{
        printf("Queue: ");
        for(int i = q -> front; i <= q -> rear; i++){
            printf("%d ", q -> queue[i]);
        }
        printf("\n");
    }
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