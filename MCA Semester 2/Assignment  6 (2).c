#include <stdio.h>
#include <string.h>

char STACK[100];

int Top = -1;

void Push(char chr) {
    if (Top == 99) {
        printf("Stack is OverFlow...\n");
        return;
    }
    else {
        Top = Top + 1;
        STACK[Top] = chr;
    }
}

char Pop() {
    if (Top == -1) {
        return '\n';
    }
    else {
        char temp = STACK[Top];
        Top = Top - 1;
        return temp;
    }
}


int setPriority(char chr) {
    if (chr == '+' || chr == '-')
        return 1;
    else if (chr == '*' || chr == '/')
        return 2;
    else if (chr == '^')
        return 3;
    else
        return 0;
}

int main() {
    char Expression[100];
    int ExpLen = strlen(Expression);
    printf("Enter infix expression which you want to convert in postfix: ");
    scanf("%s", Expression);

    char Prefix_Expression[100];
    int Prefix_Top = -1;

    for (int i = ExpLen - 1; i >= 0; i--) {
        if (Expression[i] == ')')
            Push(Expression[i]);
        else if (Expression[i] == '(') {
            while (STACK[Top] != ')') {
                Prefix_Top = Prefix_Top + 1;
                Prefix_Expression[Prefix_Top] = Pop();
            }
            Pop();
        }
        else if (Expression[i] == '^' || Expression[i] == '/' || Expression[i] == '*' || Expression[i] == '+' || Expression[i] == '-') {
            while (Top != -1 && (setPriority(STACK[Top]) == setPriority(Expression[i]))) {
                if (STACK[Top] == '^' && Expression[i] == '^') {
                    char chr = Pop();
                    Prefix_Top = Prefix_Top + 1;
                    Prefix_Expression[Prefix_Top] = chr;
                }
                else
                    break;
            }
            while (Top != -1 && (setPriority(STACK[Top]) > setPriority(Expression[i]))) {
                char chr = Pop();
                Prefix_Top = Prefix_Top + 1;
                Prefix_Expression[Prefix_Top] = chr;
            }
            Push(Expression[i]);
        }
        else {
            Prefix_Top = Prefix_Top + 1;
            Prefix_Expression[Prefix_Top] = Expression[i];
        }
    }

    while (Top != -1) {
        char chr = Pop();
        Prefix_Top = Prefix_Top + 1;
        Prefix_Expression[Prefix_Top] = chr;
    }

    printf("Prefix Expression: ");

    while (Prefix_Top != -1) {
        // Printing the Prefix Expression
        printf("%c", Prefix_Expression[Prefix_Top]);
        Prefix_Top = Prefix_Top - 1;
    }
}