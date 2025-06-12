#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct{
    int arr[MAX];
    int top;
}Stack;

void _init_(Stack* s){
    s -> top = -1;
}

void push(Stack* s, int value){
    if(s -> top == MAX - 1){
        printf("Overflow!\n");
    }
    else{
        s -> top++;
        s -> arr[s -> top] = value;
        printf("%d is pushed", value);
    }
}

void pop(Stack* s){
    if(s -> top < 0){
        printf("Underflow!\n");
    }
    else{
        printf("%d is popped", s -> arr[s -> top]);
        s -> top--;
    }
}

void peek(Stack* s){
    if(s -> top < 0){
        printf("Stack is empty!");
    }
    else{
        printf("Top of Stack: %d", s -> arr[s -> top]);
    }
}

void display(Stack* s){
    if(s -> top < 0){
        printf("Stack is empty!");
    }
    else{
        printf("Stack: ");
        for(int i = 0; i < s -> top; i++){
            printf("%d ", s -> arr[i]);
        }
        printf("\n");
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