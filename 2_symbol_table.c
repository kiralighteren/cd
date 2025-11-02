#include <stdio.h>
#include <string.h>

struct Symbol {
    char name[20];
    char type[10];
    int value;
};

struct Symbol symTable[10];
int count = 0;

void insert(char *name, char *type, int value) {
    strcpy(symTable[count].name, name);
    strcpy(symTable[count].type, type);
    symTable[count].value = value;
    count++;
}

int search(char *name) {
    for (int i = 0; i < count; i++)
        if (strcmp(symTable[i].name, name) == 0) return i;
    return -1;
}

void delete(char *name) {
    int pos = search(name);
    if (pos != -1) {
        for (int i = pos; i < count-1; i++)
            symTable[i] = symTable[i+1];
        count--;
    }
}

void modify(char *name, int newValue) {
    int pos = search(name);
    if (pos != -1) symTable[pos].value = newValue;
}

void display() {
    printf("\nSymbol Table:\n");
    for (int i = 0; i < count; i++)
        printf("%s\t%s\t%d\n", symTable[i].name, symTable[i].type, symTable[i].value);
}

int main() {
    insert("x", "int", 10);
    insert("y", "float", 20);
    display();

    printf("\nSearch 'x': %d\n", search("x"));
    modify("x", 100);
    display();
    delete("y");
    display();
    return 0;
}
