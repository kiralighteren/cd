// control_check.c

#include <stdio.h>
#include <string.h>

int isValidFor(char *s) { return strstr(s, "for(") == s || strstr(s, "for (") == s; }
int isValidWhile(char *s) { return strstr(s, "while(") == s || strstr(s, "while (") == s; }
int isValidIf(char *s) { return strstr(s, "if(") == s || strstr(s, "if (") == s; }
int isValidElseIf(char *s) { return strstr(s, "else if(") == s || strstr(s, "else if (") == s; }
int isValidElse(char *s) { return strstr(s, "else") == s; }
int isValidSwitch(char *s) { return strstr(s, "switch(") == s || strstr(s, "switch (") == s; }

int main() {
    char input[200];
    printf("Enter a C control structure statement:\n");
    fgets(input, sizeof(input), stdin);
    input[strcspn(input, "\n")] = '\0';

    if (isValidFor(input))
        printf("Valid 'for' loop syntax.\n");
    else if (isValidWhile(input))
        printf("Valid 'while' loop syntax.\n");
    else if (isValidElseIf(input))
        printf("Valid 'else if' structure.\n");
    else if (isValidIf(input))
        printf("Valid 'if' structure.\n");
    else if (isValidElse(input))
        printf("Valid 'else' structure.\n");
    else if (isValidSwitch(input))
        printf("Valid 'switch' case structure.\n");
    else
        printf("Invalid or unrecognized control structure syntax.\n");

    return 0;
}

###
gcc control_check.c -o control_check
echo "for(i=0;i<10;i++)" | ./control_check
# Output: Valid 'for' loop syntax.
###
