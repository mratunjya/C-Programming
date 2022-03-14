#include <stdio.h>
#include <string.h>

char STACK[100];

int top = -1;

void Push(char chr) {
    top = top + 1;
    STACK[top] = chr;
}

char Pop() {
    if (top == -1) {
        return '\n';
    }
    else {
        char t;
        t = STACK[top];
        top = top - 1;
        return t;
    }
}

int main() {
    char chr, rev_chr;

    printf("\nHey User, Would you like to reverse a string?\n");
    printf("I can reverse a string for you.\n");
    printf("Let's Try Out, Enter your String: ");

    while (chr != '\n') {
        scanf("%c", &chr);
        if (chr != '\n')
            Push(chr);
    }

    printf("\nReversing the String ....\n");

    while (rev_chr != '\n') {
        rev_chr = Pop();
        printf("%c", rev_chr);
    }

    printf("\nReversed Successfully!\n");
    printf("\nWould you like to give a feedback? Try Adding a Private comment on Google Classroom\n");
}