#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX 100

char stack[MAX][10];
int top = -1;
int tempVar = 1;

void push(char *str) { strcpy(stack[++top], str); }
char* pop() { return stack[top--]; }
int isOperator(char c) { return (c == '+' || c == '-' || c == '*' || c == '/'); }

int main() {
    char postfix[100];
    printf("Enter postfix expression: ");
    fgets(postfix, sizeof(postfix), stdin);

    for (int i = 0; postfix[i] != '\0'; i++) {
        if (isspace((unsigned char)postfix[i])) continue;

        if (isalnum((unsigned char)postfix[i])) {
            char operand[2] = { postfix[i], '\0' };
            push(operand);
        } else if (isOperator(postfix[i])) {
            char operand2[10], operand1[10], temp[10];
            strcpy(operand2, pop());
            strcpy(operand1, pop());
            sprintf(temp, "T%d", tempVar++);

            printf("LOAD %s\n", operand1);
            switch (postfix[i]) {
                case '+': printf("ADD %s\n", operand2); break;
                case '-': printf("SUB %s\n", operand2); break;
                case '*': printf("MUL %s\n", operand2); break;
                case '/': printf("DIV %s\n", operand2); break;
            }
            printf("STORE %s\n", temp);
            push(temp);
        }
    }
    printf("\nFinal Result stored in: %s\n", pop());
    return 0;
}

###
gcc postfix_to_machine.c -o postfix_to_machine
# Example:
printf "A B C * + D /" | ./postfix_to_machine
###
