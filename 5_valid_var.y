%{
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
int yylex();
void yyerror(char *s);
%}

%token VALID INVALID

%%

input: VALID   { printf("Valid Variable\n"); }
     | INVALID { printf("Invalid Variable\n"); }
     ;

%%

void yyerror(char *s) {
    printf("%s\n", s);
}

/* A simple scanner implemented in C (not using Flex) */
int yylex() {
    char input[100];
    if (scanf("%s", input) != 1) return 0;

    if (isalpha(input[0])) {
        int valid = 1;
        for (int i = 1; input[i]; i++)
            if (!isalnum(input[i])) valid = 0;
        return valid ? VALID : INVALID;
    }
    return INVALID;
}

int main() {
    printf("Enter variable name: ");
    yyparse();
    return 0;
}

###
yacc -d var_parser.y
gcc y.tab.c -o var_parser
echo "var123" | ./var_parser
###
