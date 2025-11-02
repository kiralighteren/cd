// tac.c

#include <stdio.h>
#include <string.h>
#include <ctype.h>

int tempCount = 1;

void generateTAC(char exp[]) {
    char stack[50][10];
    int top = -1;

    for (int i = 0; i < strlen(exp); i++) {
        char symbol = exp[i];
        if (isalnum(symbol)) {
            char operand[10];
            sprintf(operand, "%c", symbol);
            strcpy(stack[++top], operand);
        }
        else if (symbol == '+' || symbol == '-' || symbol == '*' || symbol == '/') {
            if (top < 1) {
                printf("Invalid Expression\n");
                return;
            }
            char op2[10], op1[10], result[10];
            strcpy(op2, stack[top--]);
            strcpy(op1, stack[top--]);
            sprintf(result, "t%d", tempCount++);
            printf("%s = %s %c %s\n", result, op1, symbol, op2);
            strcpy(stack[++top], result);
        }
    }
    if (top == 0)
        printf("Final Result: %s\n", stack[top]);
    else
        printf("Invalid Expression\n");
}

int main() {
    char postfix[50];
    printf("Enter the postfix expression: ");
    scanf("%s", postfix);
    printf("\nThree Address Code:\n");
    generateTAC(postfix);
    return 0;
}

###
gcc tac.c -o tac
./tac
# input: ab+c*
###
