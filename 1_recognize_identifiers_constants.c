#include <stdio.h>
#include <ctype.h>
#include <string.h>

int isIdentifier(char *str) {
    if (!isalpha(str[0]) && str[0] != '_') return 0;
    for (int i = 1; str[i]; i++)
        if (!isalnum(str[i]) && str[i] != '_') return 0;
    return 1;
}

int isConstant(char *str) {
    for (int i = 0; str[i]; i++)
        if (!isdigit(str[i])) return 0;
    return 1;
}

int main() {
    char tokens[][20] = {"abc", "123", "var1", "45", "test_123", "78"};
    int n = 6;

    printf("Lexical Analysis:\n");
    for (int i = 0; i < n; i++) {
        if (isIdentifier(tokens[i]))
            printf("%s -> Identifier\n", tokens[i]);
        else if (isConstant(tokens[i]))
            printf("%s -> Constant\n", tokens[i]);
    }
    return 0;
}
