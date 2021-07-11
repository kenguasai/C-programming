#include<stdio.h>
#include<stdlib.h>

int top = -1;
char s[30];

void push(char x) {
    top++;
    s[top] = x;
}

int precedence(char x) {
    if(x == '^') return 4;
    else if(x == '*' || x == '/') return 3;
    else if(x == '+' || x == '-') return 2;
    else return 1;
}

char pop() {
    char item;
    item = s[top];
    top--;
    return item;
}

int is_operator(char x) {
    if (x == '*' || x == '+' || x == '-' || x == '/' || x == '^')
        return 1;
    else return 0;
}

void main() {
    int i = 0, j = 0;
    char infix[30], item, postfix[30], a;
    printf("Enter an infix expression\n");
    gets(infix);

    while (infix[i] != 0) {
        item = infix[i];

        if(item == '(') {
            push(item);
        } else if(isalnum(item)) {
            postfix[j] = item;
            j++;
        } else if(is_operator(item) == 1) {
            if (item != '^') {
                while (top != -1 && precedence(s[top]) > precedence(item)) {
                    postfix[j] = pop();
                    j++;
                }
                push(item);
            }
        } else if(item == ')') {
            while (s[top] != '(') {
                postfix[j] = pop();
                j++;
            }
            a = pop();
        }

        i++;
    }

    while (top != -1) {
        postfix[j] = pop();
        j++;
    }
    
    
    postfix[i] = '\0';
    printf("Postfix expression is :");
    puts(postfix);
}