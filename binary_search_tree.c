#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *lchild, *rchild;
};

struct node *root = NULL, *temp = NULL, *curr = NULL, *parent = NULL;

void create() {
    temp = (struct node *)malloc(sizeof(struct node));
    printf("Enter the data:\n");
    scanf("%d", &temp->data);

    temp->lchild = NULL;
    temp->rchild = NULL;

    if(root == NULL) root = temp;
    else {
        // i 
        curr = root;
        while (curr) {
            // k
            parent = curr;
            if(curr->data == temp ->data) {
                printf("Node already exists\n");
                break;
            } else if (curr->data < temp->data) {
                // traversing right
                curr = curr->rchild;
            } else if (curr->data > temp->data) {
                //  traversing left
                curr = curr->lchild;
            }
        }

        if(parent -> data < temp->data) {
            parent->rchild = temp;
        } else {
            parent->lchild = temp;
        }
    }
}

void inorder(struct node *tree) {
    if(tree != NULL) {
        inorder(tree->lchild);
        printf("%d-->", tree->data);
        inorder(tree->rchild);
    }
}

void main() {
    int ch;
    while (1) {
        printf("1. Insert\n2. Print\n3. Exit\n");
        scanf("%d", &ch);
        switch (ch) {
            case 1: create();
                break;
            
            case 2: inorder(root);
                printf("\n");
                break;

            case 3: exit(0);
                break;

            default: printf("Enter valid choice");
                break;
        }
    }
    
}