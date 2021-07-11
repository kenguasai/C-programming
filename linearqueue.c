#include<stdio.h>
#include<stdlib.h>
#define SIZE 5
int rear = -1, front = -1, q[SIZE];

void enqueue() {
    if (rear == SIZE -1) printf("Linear queue is full\n");
    else {
        if(rear == -1) front = 0;
        rear ++;
        printf("Enter the element:\n");
        scanf("%d", &q[rear]);
    }
}

void dequeue() {
    if(front == -1) printf("Linear queue is empty\n");
    else {
        printf("Deleted item is %d\n", q[front]);
        if (front == rear) front = rear = -1;
        else {
            front++;
        }
    } 
}

void display() {
    if(front == -1) printf("Linear queue is empty\n");
    else {
        for (int i = front; i <= rear; i++) {
            printf("%d-->", q[i]);
        }
        printf("\n");
    }
}

void main() {
    int ch;

    while (1) {
        printf("1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n");
        scanf("%d", &ch);
        switch (ch) {
            case 1: enqueue();
                break;
        
            case 2: dequeue();
                break;

            case 3: display();
                break;

            case 4: exit(0);
                break;

            default: printf("Enter valid option\n");
                break;
        }
    }
}