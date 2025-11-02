%{
#include <stdio.h>
int vowels = 0, consonants = 0;
%}

%%

[AEIOUaeiou]          { vowels++; }
[A-Za-z]              { consonants++; }
[ \t\n]+              ;    /* ignore spaces, tabs, and newlines */
.                     ;    /* ignore any other characters */

%%

int yywrap() { return 1; }

int main() {
    printf("Enter a string: ");
    yylex();
    printf("\nTotal vowels: %d\n", vowels);
    printf("Total consonants: %d\n", consonants);
    return 0;
}

###
flex vowels.l
gcc lex.yy.c -o vowels -ll
echo "Hello World" | ./vowels
# Output: Total vowels: 3  Total consonants: 7
###
