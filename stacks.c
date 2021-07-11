#include<stdio.h>
#define SIZE 5
#include<stdlib.h>

int s[SIZE], top = -1, item, ditem;

void push() {
    if(top == SIZE - 1) printf("Stack is full\n");
    else {
        printf("Enter new element\n");
        scanf("%d", &item);
        top ++;
        s[top] = item;
    }
}

void pop() {
    if(top == -1) printf("Underflow\n");
    else {
        ditem = s[top];
        top--;
        printf("Deleted item is %d\n", ditem);
    }
}

void display() {
    if(top == -1) printf("Empty stack\n");
    else {
        for (int i = 0; i <= top; i++) {
            printf("%d-->", s[i]);
        }
        printf("\n");
    }
}

void main() {
    
    int ch;
    while (1) {
        printf("1. Push\n2. Pop\n3. Display\n4. Exit\n");
        scanf("%d", &ch);
        switch (ch) {
            case 1:
                push();
                break;
            
            case 2:
                pop();
                break;
            
            case 3:
                display();
                break;
            
            case 4:
                exit(0);
                break;    

            default: printf("Enter valid option");
                break;
        }
    }
    
}