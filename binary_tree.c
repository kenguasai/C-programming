#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *lchild, *rchild;
};

struct node *root = NULL, *temp = NULL;

int is_lchild(struct node *tree) {
    printf("Do you want to create l-child of %d\n1. Yes\t2. No\n", tree->data);
    int l;
    scanf("%d", &l);
    if(l == 1) return 1;
    else return 0;
}

int is_rchild(struct node *tree) {
    printf("Do you want to create r-child of %d\n1. Yes\t2. No\n", tree->data);
    int r;
    scanf("%d", &r);
    if(r == 1) return 1;
    else return 0;
}

void create(struct node *tree) {

    if(is_lchild(tree) == 1) {
        temp = (struct node *)malloc(sizeof(struct node));
        printf("Enter the data:\n");
        scanf("%d", &temp->data);
        tree->lchild = temp;
        create(temp);
    } else {
        tree->lchild = NULL;
    }

    if(is_rchild(tree) == 1) {
        temp = (struct node *)malloc(sizeof(struct node));
        printf("Enter the data:\n");
        scanf("%d", &temp->data);
        tree->rchild = temp;
        create(temp);
    } else {
        tree->rchild = NULL;
    }

}

void inorder(struct node *tree) {
    if(tree != NULL) {
        inorder(tree->lchild);
        printf("%d-->", tree->data);
        inorder(tree->rchild);
    }
}

void postorder(struct node *tree) {
    if(tree != NULL) {
        postorder(tree->lchild);
        postorder(tree->rchild);
        printf("%d-->", tree->data);
    }
}

void preorder(struct node *tree) {
    if(tree != NULL) {
        printf("%d-->", tree->data);
        preorder(tree->lchild);
        preorder(tree->rchild);
    }
}

void main() {
    root = (struct node *)malloc(sizeof(struct node));
    printf("Enter the root element:\n");
    scanf("%d", &root->data);

    create(root);

    printf("Inorder\n");
    inorder(root);
    printf("\nPreorder\n");
    preorder(root);
    printf("\nPostorder\n");
    postorder(root);

}
