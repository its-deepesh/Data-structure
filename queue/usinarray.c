#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int queue[MAX];
int front = -1; 
int rear = -1;

void enqueue(int value){
    if(rear == MAX - 1){
        printf("Overflow!\n");
    }
    else{ 
        if(front == -1){
            front = 0;
        }
        rear++;
        queue[rear] = value;
        printf("%d is enqueued\n", value);
    }   
}

void dequeue(){
    if(front == -1 || front > rear){
        printf("Underflow!\n");
    }
    else{
        printf("%d is dequeued\n", queue[front]);
        front++;
    }
}

void peek(){
    if(front == -1 || front > rear){
        printf("Queue is Empty!\n");
    }
    else{
        printf("Top of Queue: %d", front);
    }
}

void display(){
    if(front == -1 || front > rear){
        printf("Queue is empty!\n");
    }
    else{
        printf("Queue: ");
        for(int i = front; i <= rear; i++){
            printf("%d ", queue[i]);
        }
        printf("\n");
    }
}

int main(){
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
            enqueue(value);
        }
        else if(choice == 2){
            dequeue();
        }
        else if(choice == 3){
            display();
        }
        else if(choice == 4){
            peek();
        }
        else if(choice == 5){
            printf("Exiting...\n");
            break;
        }
        else{
            printf("Invalid Choice!");
        }
    }

    return 0;
}