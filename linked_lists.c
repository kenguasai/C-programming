#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *link;
};

struct node *head = NULL, *temp = NULL, *ptr = NULL;

void insert_beg() {
    temp = (struct node*)malloc(sizeof(struct node));

    printf("Enter the element:\n");
    scanf("%d", &temp->data);
    temp->link = NULL;

    if(head == NULL) head = temp;
    else {
        temp->link = head;
        head = temp;
    }
}

void insert_end() {
    temp = (struct node*)malloc(sizeof(struct node));
    printf("Enter the element:\n");
    scanf("%d", &temp->data);
    temp->link = NULL;

    if(head == NULL) head = temp;
    else {
        ptr = head;
        while (ptr->link!=NULL) {
            ptr = ptr->link;
        }
        ptr->link = temp;
    } 
}

void display_ll() {
    if(head == NULL) printf("Empty\n");
    else {
        // Analogous to i = 0 in for loop
        ptr = head;
        while (ptr!= NULL) {
            printf("%d-->", ptr->data);
            ptr = ptr->link;
        }
        printf("\n");
    }
}

void delete_beg() {
    if(head == NULL) printf("Linked list is empty\n");
    else {
        ptr = head;
        head = head->link;
        free(ptr);
    }
}

void delete_end() {
    if(head == NULL) printf("Linked list empty\n");
    else {
        ptr = head;
        while (ptr->link!= NULL) {
            temp = ptr;
            ptr = ptr->link;
        }
        
        temp->link = NULL;
        free(ptr);
    }
}

void insert_location() {
    int pos = 0, count = 0;
    printf("Enter the position:\n");
    scanf("%d", &pos);
    ptr = head;

    while (ptr != NULL) {
        count++;
        ptr = ptr->link;
    }
    
    if(pos == 1) insert_beg();
    else if(pos == count + 1) insert_end();
    else if(pos > 1 && pos <= count) {
        temp = (struct node *)malloc(sizeof(struct node));
        printf("Enter the data:\n");
        scanf("%d", &temp->data);
        temp->link = NULL;

        ptr = head;
        for (int i = 2; i <= count; i++) {
            if(pos == i) {
                temp->link = ptr->link;
                ptr->link = temp;
            } else ptr = ptr->link; 
        }
    } else printf("Invalid position\n");
}

void delete_location() {
    int pos = 0, count = 0;
    printf("Enter the position:\n");
    scanf("%d", &pos);

    ptr = head;
    while (ptr != NULL) {
        count++;
        ptr = ptr->link;
    }

    if (pos == 1) delete_beg();
    else if (pos > 1 && pos < count) {
        ptr = head;
        for (int i = 0; i < pos; i++) {
            temp = ptr;
            ptr = ptr->link;
        }
        temp->link = ptr->link;
        free(ptr);
        
    } else printf("Invalid position\n");
}

void main() {
    int ch;

    while (1) {
        printf("1. Insert at beginning\n2. Insert at end\n3. Delete at beginning\n4. Delete at end\n5. Insert at location\n6. Delete at location\n7. Display elements\n8. Exit\n");
        scanf("%d", &ch);
        switch (ch) {
            case 1: insert_beg();
                break;
            
            case 2: insert_end();
                break;
            
            case 3: delete_beg();
                break;

            case 4: delete_end();
                break;

            case 5: insert_location();
                break;

            case 6: delete_location();
                break;

            case 7: display_ll();
                break;

            case 8: exit(0);
                break; 

            default:
                break;
        }
    }
    
}


