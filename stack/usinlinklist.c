#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node* next;
}Node;

typedef struct{
    Node* top;
}Stack;

void _init_(Stack* s){
    s -> top = NULL;
}

void push(Stack* s, int value){
    Node* newNode = (Node*)malloc(sizeof(Node));
    if(!newNode){
        printf("Overflow!\n");
        return;
    }
    newNode -> data = value;
    newNode -> next = s -> top;
    s -> top = newNode;
    printf("%d is pushed", value);
}

void pop(Stack* s){
    if(s -> top == NULL){
        printf("Underflow!\n");
        return;
    }
    Node* temp = s -> top;
    printf("%d is popped", temp -> data);
    s -> top = temp -> next;
    free(temp);
}

void display(Stack* s){
    if(s -> top == NULL){
        printf("Stack is Empty!\n");
        return;
    }
    Node* temp = s -> top;
    printf("Stack: ");
    while(temp != NULL){
        printf("%d ", temp -> data);
        temp = temp -> next;
    }
    printf("\n");
}

void peek(Stack* s){
    if(s -> top == NULL){
        printf("Stack is Empty!\n");
        return;
    }
    else{
        printf("Top of stack: %d\n", s -> top -> data);
    }
}

int main(){
    Stack stack;
    _init_(&stack);
    int choice, value;

    while(1){
        printf("\n---Stack Menu---\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        scanf("%d", &choice);

        if(choice == 1){
            printf("Enter value to push: ");
            scanf("%d", &value);
            push(&stack, value);
        }
        else if(choice == 2){
          pop(&stack);
        }
        else if(choice == 3){
            peek(&stack);
        }
        else if(choice == 4){
            display(&stack);
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