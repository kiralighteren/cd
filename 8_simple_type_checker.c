// type_checker.c

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h> 

#define MAX 100

struct SymbolTable {
    char var[20];
    int declared;
} table[MAX];

int count = 0;

int isDeclared(char *var) {
    for (int i = 0; i < count; i++) {
        if (strcmp(table[i].var, var) == 0)
            return table[i].declared;
    }
    return 0;
}

void declareVar(char *var) {
    strcpy(table[count].var, var);
    table[count].declared = 1;
    count++;
}

int main() {
    char code[MAX][MAX];
    int n;

    printf("Enter number of lines of code: ");
    scanf("%d", &n);
    getchar();

    printf("Enter the code lines:\n");
    for (int i = 0; i < n; i++) {
        fgets(code[i], MAX, stdin);
        code[i][strcspn(code[i], "\n")] = 0;
    }

    for (int i = 0; i < n; i++) {
        char word1[20], word2[20];
        if (sscanf(code[i], "int %s", word1) == 1) {
            if (word1[strlen(word1) - 1] == ';')
                word1[strlen(word1) - 1] = '\0';
            declareVar(word1);
            printf("Line %d: Variable '%s' declared\n", i + 1, word1);
        }
        else if (sscanf(code[i], "%s = %s", word1, word2) == 2) {
            if (!isDeclared(word1))
                printf("Line %d: Error - Variable '%s' used before declaration\n", i + 1, word1);
            else if (isalpha(word2[0]) && !isDeclared(word2))
                printf("Line %d: Error - Variable '%s' used before declaration\n", i + 1, word2);
            else
                printf("Line %d: Assignment is semantically correct\n", i + 1);
        }
    }
    return 0;
}

###
gcc type_checker.c -o type_checker
./type_checker
# follow prompts; example input in PDF shows semantics checks
###
