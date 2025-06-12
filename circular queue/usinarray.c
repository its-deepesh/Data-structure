#include <stdio.h>
#define MAX 100

typedef struct{
    int front, rear;
    int queue[MAX];
}CircularQueue;

void _init_(CircularQueue* q){
    q -> front = q -> rear = -1;
}

int isFull(CircularQueue* q){
    return(q -> front == 0 && q -> rear == MAX - 1) || (q -> rear == (q -> front - 1 + MAX) % MAX);
}

int isEmpty(CircularQueue* q){
    return q -> front == -1;
}

void enqueue(CircularQueue* q, int value){
    if(isFull(q)){
        printf("Queue is Full!\n");
        return;
    }
    if(isEmpty(q)){
        q -> front = q -> rear = 0;
    }
    else{
        q -> rear = (q -> rear + 1) % MAX;
    }
    q -> queue[q -> rear] = value;
    printf("Inserted %d\n", value);
}

int dequeue(CircularQueue* q){
    if(isEmpty(q)){
        printf("Queue is Empty!\n");
        return -1;
    }

    int data = q -> queue[q -> front];
    printf("Deleted %d\n", data);

    if(q -> front == q -> rear){
        q -> front = q -> rear = -1;
    }
    else{
        q -> front = (q -> front + 1) % MAX;
    }
    return data;
}

void display(CircularQueue* q){
    if(isEmpty(q)){
        printf("Queue is Empty!\n");
        return;
    }
    printf("Queue: ");
    int i = q -> front;
    while(1){
        printf("%d", q -> queue[i]);
        if(i == q -> rear){
            break;
        }
        i = (i + 1) % MAX;
    }
    printf("-> \n");
    printf("\n");
}

int main(){
    int choice, value;
    CircularQueue q;
    _init_(&q);

    while(1){
        printf("---Queue Menu---\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter operation to use(1 , 2, 3, 4): ");
        scanf("%d", &choice);

        if(choice  == 1){
            printf("Enter value: ");
            scanf("%d", &value);
            enqueue(&q, value);
        }
        else if(choice == 2){
            dequeue(&q);
        }
        else if(choice == 3){
            display(&q);
        }
        else if(choice == 4){
            printf("Exiting...\n");
            break;
        }
        else{
            printf("Invalid Choice!");
        }
    }

    return 0;
}