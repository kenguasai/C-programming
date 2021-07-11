#include<stdio.h>
#include<math.h>
#include<stdlib.h>
char postfix[30], var;
int top = -1, ditem, i = 0, item = 0, s[30], op1 = 0, op2 = 0, res = 0;

int is_operand(char x) {
    if(x >= 'A' && x <= 'Z' || x >= 'a' && x <= 'z') return 1;
    else return 0;
}

void push(int x) {
    top++;
    s[top] = x;
}

int pop() {
    ditem = s[top];
    top --;
    return ditem;
}


void main() {
    printf("Enter the postfix expression:\n");
    gets(postfix);
    while (postfix[i] != 0) {
        var = postfix[i];
        if(is_operand(var)) {
            printf("Enter the value of %c:\n", var);
            scanf("%d", &item);
            push(item);
        } else {
            op1 = pop();
            op2 = pop();
            switch (var) {
                case '+': res = op1 + op2;
                    push(res);
                    break;
                
                case '-': res = op2 - op1;
                    push(res);
                    break;
                
                case '*': res = op1 * op2;
                    push(res);
                    break;

                case '/': res = op1 / op2;
                    push(res);
                    break;    
                
                case '^': res = pow(op1,  op2);
                    push(res);
                    break;    

                default:
                    break;
            }
        }
        i++;
    }
    
    res = pop();
    printf("The result is %d", res);
}