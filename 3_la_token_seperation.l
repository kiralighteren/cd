### lexer.l

%{
#include <stdio.h>
%}

%%

[0-9]+          { printf("Number: %s\n", yytext); }
[a-zA-Z][a-zA-Z0-9]* { printf("Identifier: %s\n", yytext); }
[ \t\n]         ;
.               { printf("Operator: %s\n", yytext); }

%%

int main() {
    yylex();
    return 0;
}

int yywrap() {
    return 1;
}

###
flex lexer.l
gcc lex.yy.c -o lexer -ll
echo "a = b + 123" | ./lexer
###
