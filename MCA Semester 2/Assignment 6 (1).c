#include <stdio.h>
#include <ctype.h>

char STACK[100];
int Top = -1;

void Push(char x) {
    STACK[++Top] = x;
}

char Pop() {
    if (Top == -1)
        return -1;
    else
        return STACK[Top--];
}

int setPriority(char x) {
    if (x == '(')
        return 0;
    if (x == '+' || x == '-')
        return 1;
    if (x == '*' || x == '/')
        return 2;
    if (x == '^')
        return 3;
    return 0;
}

int main() {
    char Expression[100];
    char *e, x;
    printf("Enter infix expression which you want to convert in postfix : ");
    scanf("%s", Expression);
    printf("\n");
    printf("PostFix Expression: ");
    e = Expression;

    while (*e != '\0') {
        if (isalnum(*e))
            printf("%c ", *e);
        else if (*e == '(')
            Push(*e);
        else if (*e == ')')
        while ((x = Pop()) != '(')
                printf("%c ", x);
        else {
            while (setPriority(STACK[Top]) >= setPriority(*e))
                printf("%c ", Pop());
            Push(*e);
        }
        e++;
    }

    while (Top != -1)
        printf("%c ", Pop());

    printf("\n");
    return 0;
}