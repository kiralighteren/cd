### machine_gen.c

#include <stdio.h>
#include <string.h>

struct Instruction {
    char result[10];
    char arg1[10];
    char op[5];
    char arg2[10];
};

int main() {
    int n;
    printf("Enter number of intermediate code instructions: ");
    scanf("%d", &n);

    struct Instruction ic[20];
    printf("\nEnter intermediate code in the format (result = arg1 op arg2):\n");
    for (int i = 0; i < n; i++) {
        printf("Instruction %d: ", i + 1);
        scanf("%s = %s %s %s", ic[i].result, ic[i].arg1, ic[i].op, ic[i].arg2);
    }

    printf("\n=== Generated Machine Code ===\n");
    for (int i = 0; i < n; i++) {
        printf("LOAD %s\n", ic[i].arg1);
        if (strcmp(ic[i].op, "+") == 0)
            printf("ADD %s\n", ic[i].arg2);
        else if (strcmp(ic[i].op, "-") == 0)
            printf("SUB %s\n", ic[i].arg2);
        else if (strcmp(ic[i].op, "*") == 0)
            printf("MUL %s\n", ic[i].arg2);
        else if (strcmp(ic[i].op, "/") == 0)
            printf("DIV %s\n", ic[i].arg2);
        else
            printf("NOP // Unknown operation\n");
        printf("STORE %s\n\n", ic[i].result);
    }
    return 0;
}

###
gcc machine_gen.c -o machine_gen
./machine_gen
# enter intermediate code lines like: T1 = A + B
###
