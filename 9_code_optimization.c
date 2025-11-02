#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

struct Instruction {
    char result[10];
    char arg1[10];
    char op[5];
    char arg2[10];
};

int isConstant(char *str) {
    for (int i = 0; str[i] != '\0'; i++) {
        if (!isdigit(str[i]))
            return 0;
    }
    return 1;
}

int main() {
    int n;
    printf("Enter number of intermediate code statements: ");
    scanf("%d", &n);

    struct Instruction ic[20];
    printf("\nEnter the intermediate code in format (result = arg1 op arg2):\n");
    for (int i = 0; i < n; i++) {
        printf("Instruction %d: ", i + 1);
        scanf("%s = %s %s %s", ic[i].result, ic[i].arg1, ic[i].op, ic[i].arg2);
    }

    printf("\n=== Before Optimization ===\n");
    for (int i = 0; i < n; i++)
        printf("%s = %s %s %s\n", ic[i].result, ic[i].arg1, ic[i].op, ic[i].arg2);

    // Optimization Phase
    for (int i = 0; i < n; i++) {
        // Constant Folding
        if (isConstant(ic[i].arg1) && isConstant(ic[i].arg2)) {
            int val1 = atoi(ic[i].arg1);
            int val2 = atoi(ic[i].arg2);
            int res = 0;

            if (strcmp(ic[i].op, "+") == 0) res = val1 + val2;
            else if (strcmp(ic[i].op, "-") == 0) res = val1 - val2;
            else if (strcmp(ic[i].op, "*") == 0) res = val1 * val2;
            else if (strcmp(ic[i].op, "/") == 0 && val2 != 0) res = val1 / val2;

            sprintf(ic[i].arg1, "%d", res);
            strcpy(ic[i].op, "");
            strcpy(ic[i].arg2, "");
        }

        // Constant Propagation
        for (int j = i + 1; j < n; j++) {
            if (strcmp(ic[i].op, "") == 0) {
                if (strcmp(ic[j].arg1, ic[i].result) == 0)
                    strcpy(ic[j].arg1, ic[i].arg1);
                if (strcmp(ic[j].arg2, ic[i].result) == 0)
                    strcpy(ic[j].arg2, ic[i].arg1);
            }
        }
    }

    // Dead Code Elimination
    int used[20] = {0};
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
            if (strcmp(ic[i].result, ic[j].arg1) == 0 ||
                strcmp(ic[i].result, ic[j].arg2) == 0)
                used[i] = 1;

    printf("\n=== After Optimization ===\n");
    for (int i = 0; i < n; i++) {
        if (used[i] || i == n - 1) {
            if (strcmp(ic[i].op, "") == 0)
                printf("%s = %s\n", ic[i].result, ic[i].arg1);
            else
                printf("%s = %s %s %s\n", ic[i].result, ic[i].arg1, ic[i].op, ic[i].arg2);
        }
    }
    return 0;
}
