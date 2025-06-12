#include <stdio.h>
#define MAX 100

int stack[MAX];
int top = -1;

void push(int value){
    if(top >= MAX - 1){
        printf("Overflow\n");
    }
    else{
        top++;
        stack[top] = value;
        printf("%d is pushed", value);
    }
}

void pop(){
    if(top < 0){
        printf("Underflow\n");
    }
    else{
        printf("%d is popped", stack[top]);
        top--;
    }
}

void peek(){
    if(top < 0){
        printf("Stack is emptyn");
    }
    else{
        printf("Top element is: ", stack[top]);
    }
}

void display(){
    if(top < 0){
        printf("Stack is empty");
    }
    else{
        printf("Stack elements: ");
        for(int i = 0; i <= top; i++){
            printf("%d ", stack[i]);
        }
        printf("\n");
    }
}

int main(){
    int choice, value;
    
    while(1){
        printf("\n---Stack Menu---\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Display\n");
        printf("4. Peek\n");
        printf("5. Exit\n");
        scanf("%d", &choice);

        if(choice == 1){
            printf("Enter value to push: ");
            scanf("%d", &value);
            push(value);
        }
        else if(choice == 2){
          pop();
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
            printf("Invalid Choice\n");
        }
    }

    return 0;
}

void delete(){
    if(front == -1){
        printf("Underflow\n");
    }
    if(front == rear){
        front = rear = -1;
    }
    else{
        front++;
    }

    int gp = 0;
    int pos = 0;

    for(int i = front; i <= rear; i++){
        if(gp < Pnum[i]){
            gp = Pnum[i];
            pos = i;
        }
    }

    for(int i = pos; i <= rear - 1; i++){
        Pqueue[i] = Pqueue[i+1];
        Pnum[i] = Pnum[i+1];
    }
    rear++;
}