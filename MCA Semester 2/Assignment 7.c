#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

struct STACK {
    char DATA[100];
};

struct STACK Postfix[100];

char STACK[100];

int Top = -1;

void InfixPush(char ch) {
    if (Top == 99) {
        printf("\nOverflow\n");
        return;
    }
    else {
        Top = Top + 1;
        STACK[Top] = ch;
    }
}

char InfixPop() {
    if (Top == -1)
        return '\n';
    else {
        char temp = STACK[Top];
        Top = Top - 1;
        return temp;
    }
}

int setPriority(char ch) {
    if (ch == '+' || ch == '-')
        return 1;
    else if (ch == '*' || ch == '/')
        return 2;
    else if (ch == '^')
        return 3;
    else
        return 0;
}

void Push(char DATA[]) {
    if (Top == 99) {
        printf("\nOverflow\n");
        return;
    }
    else {
        Top = Top + 1;
        strcpy(Postfix[Top].DATA, DATA);
    }
}

char *Pop() {
    if (Top == -1) {
        char *temp = malloc(1 * sizeof(char));
        temp[0] = '\n';
        return temp;
    }
    else {
        char *temp = malloc(100 * sizeof(char));
        strcpy(temp, Postfix[Top].DATA);
        Top = Top - 1;
        return temp;
    }
}

void convertInfixtoPostFix(char Infix[]) {
    for (int i = 0; Infix[i] != '\0'; i++) {
        if (Infix[i] == ' ')
            continue;

        if (Infix[i] == '(')
            InfixPush(Infix[i]);
        else if (Infix[i] == ')') {
            while (STACK[Top] != '(')
                printf("%c", InfixPop());
            InfixPop();
        }
        else if ( Infix[i] == '^' || Infix[i] == '/' || Infix[i] == '*' || Infix[i] == '+' || Infix[i] == '-') {
            while (Top != -1 && (setPriority(STACK[Top]) >= setPriority(Infix[i]))) {
                if (STACK[Top] == '^' && Infix[i] == '^')
                    break;
                else {
                    char ch = InfixPop();
                    printf("%c", ch);
                }
            }
            InfixPush(Infix[i]);
        }
        else
            printf("%c", Infix[i]);
    }

    while (Top != -1) {
        char ch = InfixPop();
        printf("%c", ch);
    }
}

void convertInfixtoPrefix(char Infix[]) {
    char Prefix[100];
    int Prefix_Top = -1;

    for (int i = strlen(Infix) - 1; i >= 0; i--) {
        if (Infix[i] == ')')
            InfixPush(Infix[i]);
        else if (Infix[i] == '(') {
            while (STACK[Top] != ')') {
                Prefix_Top = Prefix_Top + 1;
                Prefix[Prefix_Top] = InfixPop();
            }
            InfixPop();
        }
        else if (Infix[i] == '^' || Infix[i] == '/' || Infix[i] == '*' || Infix[i] == '+' || Infix[i] == '-') {
            while (Top != -1 && (setPriority(STACK[Top]) == setPriority(Infix[i]))) {
                if (STACK[Top] == '^' && Infix[i] == '^') {
                    char ch = InfixPop();
                    Prefix_Top = Prefix_Top + 1;
                    Prefix[Prefix_Top] = ch;
                }
                else
                    break;
            }
            while (Top != -1 && (setPriority(STACK[Top]) > setPriority(Infix[i]))) {
                char ch = InfixPop();
                Prefix_Top = Prefix_Top + 1;
                Prefix[Prefix_Top] = ch;
            }
            InfixPush(Infix[i]);
        }
        else {
            Prefix_Top = Prefix_Top + 1;
            Prefix[Prefix_Top] = Infix[i];
        }
    }

    while (Top != -1) {
        char ch = InfixPop();
        Prefix_Top = Prefix_Top + 1;
        Prefix[Prefix_Top] = ch;
    }

    while (Prefix_Top != -1) {
        char ch = Prefix[Prefix_Top];
        Prefix_Top = Prefix_Top - 1;
        printf("%c", ch);
    }
}

void postfix_to_infix(char Postfix[]) {
    int i = 0;

    char *temp_a;
    char *temp_b;

    while (Postfix[i] != '\0') {
        char Result[100];
        if ( Postfix[i] == '^' || Postfix[i] == '/' || Postfix[i] == '*' || Postfix[i] == '+' || Postfix[i] == '-') {
            temp_b = Pop();
            temp_a = Pop();

            switch (Postfix[i]) {
                case '+':
                    strcpy(Result, temp_a);
                    strcat(Result, "+");
                    strcat(Result, temp_b);
                    Push(Result);
                    break;
                case '-':
                    strcpy(Result, temp_a);
                    strcat(Result, "-");
                    strcat(Result, temp_b);
                    Push(Result);
                    break;
                case '*':
                    strcpy(Result, temp_a);
                    strcat(Result, "*");
                    strcat(Result, temp_b);
                    Push(Result);
                    break;
                case '/':
                    strcpy(Result, temp_a);
                    strcat(Result, "/");
                    strcat(Result, temp_b);
                    Push(Result);
                    break;
                case '^':
                    strcpy(Result, temp_a);
                    strcat(Result, "^");
                    strcat(Result, temp_b);
                    Push(Result);
                    break;
            }
        }
        else {
            char temp[2] = {Postfix[i]};
            Push(temp);
        }
        i = i + 1;
    }

    char *temp = Pop();

    printf("%s", temp);
}

void convertPrefixtoInfix(char Postfix[]) {
    int i = strlen(Postfix) - 1;

    char *temp_a;
    char *temp_b;

    while (i >= 0) {
        char Result[100];
        if (Postfix[i] == '^' || Postfix[i] == '/' || Postfix[i] == '*' || Postfix[i] == '+' || Postfix[i] == '-') {
            temp_a = Pop();
            temp_b = Pop();

            switch (Postfix[i]) {
                case '^':
                    strcpy(Result, temp_a);
                    strcat(Result, "^");
                    strcat(Result, temp_b);
                    Push(Result);
                    break;
                case '/':
                    strcpy(Result, temp_a);
                    strcat(Result, "/");
                    strcat(Result, temp_b);
                    Push(Result);
                    break;
                case '*':
                    strcpy(Result, temp_a);
                    strcat(Result, "*");
                    strcat(Result, temp_b);
                    Push(Result);
                    break;
                case '+':
                    strcpy(Result, temp_a);
                    strcat(Result, "+");
                    strcat(Result, temp_b);
                    Push(Result);
                    break;
                case '-':
                    strcpy(Result, temp_a);
                    strcat(Result, "-");
                    strcat(Result, temp_b);
                    Push(Result);
                    break;
            }
        }
        else {
            char temp[2] = {Postfix[i]};
            Push(temp);
        }
        i = i - 1;
    }

    char *temp = Pop();

    printf("%s", temp);
}

void convertPostfixtoPrefix(char Postfix[]) {
    int i = 0;

    char *temp_a;
    char *temp_b;

    while (Postfix[i] != '\0') {
        char Result[100];
        if (Postfix[i] == '^' || Postfix[i] == '/' || Postfix[i] == '*' || Postfix[i] == '+' || Postfix[i] == '-') {
            temp_b = Pop();
            temp_a = Pop();

            switch (Postfix[i]) {
                case '^':
                    strcpy(Result, "^");
                    strcat(Result, temp_a);
                    strcat(Result, temp_b);
                    Push(Result);
                    break;
                case '/':
                    strcpy(Result, "/");
                    strcat(Result, temp_a);
                    strcat(Result, temp_b);
                    Push(Result);
                    break;
                case '*':
                    strcpy(Result, "*");
                    strcat(Result, temp_a);
                    strcat(Result, temp_b);
                    Push(Result);
                    break;
                case '+':
                    strcpy(Result, "+");
                    strcat(Result, temp_a);
                    strcat(Result, temp_b);
                    Push(Result);
                    break;
                case '-':
                    strcpy(Result, "-");
                    strcat(Result, temp_a);
                    strcat(Result, temp_b);
                    Push(Result);
                    break;
            }
        }
        else {
            char temp[2] = {Postfix[i]};
            Push(temp);
        }
        i = i + 1;
    }

    char *temp = Pop();

    printf("%s", temp);
}

void convertPrefixtoPostfix(char Postfix[]) {
    int i = strlen(Postfix) - 1;

    char *temp_a;
    char *temp_b;

    while (i >= 0) {
        char Result[100];
        if (Postfix[i] == '^' || Postfix[i] == '/' || Postfix[i] == '*' || Postfix[i] == '+' || Postfix[i] == '-') {
            temp_a = Pop();
            temp_b = Pop();

            switch (Postfix[i]) {
                case '+':
                    strcpy(Result, temp_a);
                    strcat(Result, temp_b);
                    strcat(Result, "+");
                    Push(Result);
                    break;
                case '-':
                    strcpy(Result, temp_a);
                    strcat(Result, temp_b);
                    strcat(Result, "-");
                    Push(Result);
                    break;
                case '*':
                    strcpy(Result, temp_a);
                    strcat(Result, temp_b);
                    strcat(Result, "*");
                    Push(Result);
                    break;
                case '/':
                    strcpy(Result, temp_a);
                    strcat(Result, temp_b);
                    strcat(Result, "/");
                    Push(Result);
                    break;
                case '^':
                    strcpy(Result, temp_a);
                    strcat(Result, temp_b);
                    strcat(Result, "^");
                    Push(Result);
                    break;
            }
        }
        else {
            char temp[2] = {Postfix[i]};
            Push(temp);
        }
        i = i - 1;
    }

    char *temp = Pop();

    printf("%s", temp);
}

bool isInfix(char Expression[]) {
    int count = 0;
    if ((Expression[strlen(Expression) - 1] >= 'a' && Expression[strlen(Expression) - 1] <= 'z') || (Expression[strlen(Expression) - 1] >= 'A' && Expression[strlen(Expression) - 1] <= 'Z')) {
        if (Expression[strlen(Expression) - 2] == '+' || Expression[strlen(Expression) - 2] == '-' || Expression[strlen(Expression) - 2] == '*' || Expression[strlen(Expression) - 2] == '/' || Expression[strlen(Expression) - 2] == '^')
            count++;
    }
    if ((Expression[0] >= 'a' && Expression[0] <= 'z') || (Expression[0] >= 'A' && Expression[0] <= 'Z'))
        count++;
    if (count == 2)
        return true;
    else
        return false;
}

bool isPostfix(char Expression[]) {
    int count = 0;
    if ((Expression[0] >= 'a' && Expression[0] <= 'z') || (Expression[0] >= 'A' && Expression[0] <= 'Z')) {
        if ((Expression[1] >= 'a' && Expression[1] <= 'z') || (Expression[1] >= 'A' && Expression[1] <= 'Z'))
            count++;
    }

    if (Expression[strlen(Expression) - 1] == '+' || Expression[strlen(Expression) - 1] == '-' || Expression[strlen(Expression) - 1] == '*' || Expression[strlen(Expression) - 1] == '/' || Expression[strlen(Expression) - 1] == '^')
        count++;

    if (count == 2)
        return true;
    else
        return false;
}

bool isPrefix(char Expression[]) {
    int count = 0;
    if ((Expression[strlen(Expression) - 1] >= 'a' && Expression[strlen(Expression) - 1] <= 'z') || (Expression[strlen(Expression) - 1] >= 'A' && Expression[strlen(Expression) - 1] <= 'Z')) {
        if ((Expression[strlen(Expression) - 2] >= 'a' && Expression[strlen(Expression) - 2] <= 'z') || (Expression[strlen(Expression) - 2] >= 'A' && Expression[strlen(Expression) - 2] <= 'Z'))
            count++;
    }
    if (Expression[0] == '+' || Expression[0] == '-' || Expression[0] == '*' || Expression[0] == '/' || Expression[0] == '^')
        count++;

    if (count == 2)
        return true;
    else
        return false;
}

int main() {
    int choice;
    do {
        char Expression[100];
        printf("Which Operation would you linke to perform?\n");
        printf("1. Infix to Postfix\n");
        printf("2. Infix to Prefix\n");
        printf("3. Postfix to Infix\n");
        printf("4. Prefix to Infix\n");
        printf("5. Postfix to Prefix\n");
        printf("6. Prefix to Postfix\n");
        printf("7. Exit\n");
        printf("What would you like to do? ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("\nEnter the Infix Expression here: ");
                scanf("%s", Expression);
                while (!isInfix(Expression)) {
                    printf("\nInvalid Input\n");
                    printf("\nEnter the Infix Expression again here:  ");
                    scanf("%s", Expression);
                }
                printf("\nIt sounds like Infix Expression\n");
                printf("\nEnter Postfix Expression here: ");
                convertInfixtoPostFix(Expression);
                printf("\n");
                break;
            case 2:
                printf("\nEnter the Infix Expression here: ");
                scanf("%s", Expression);
                while (!isInfix(Expression)) {
                    printf("\nInvalid Input.\n");
                    printf("\nEnter the Infix Expression again here: ");
                    scanf("%s", Expression);
                }
                printf("\nIt sounds like Infix Expression\n");
                printf("\nEnter Prefix Expression here: ");
                convertInfixtoPrefix(Expression);
                printf("\n");
                break;
            case 3:
                printf("\nEnter the Postfix Expression again here: ");
                scanf("%s", Expression);
                while (!isPostfix(Expression)) {
                    printf("\nInvalid Input.\n");
                    printf("\nEnter the Postfix Expression again here:: ");
                    scanf("%s", Expression);
                }
                printf("\nIt sounds like Postfix Expression\n");
                printf("\nEnter Infix Expression here: ");
                postfix_to_infix(Expression);
                printf("\n");
                break;
            case 4:
                printf("\nEnter the Prefix Expression here: ");
                scanf("%s", Expression);
                while (!isPrefix(Expression)) {
                    printf("\nInvalid Input\n");
                    printf("\nEnter the Prefix Expression again here: ");
                    scanf("%s", Expression);
                }
                printf("\nIt sounds like Prefix Expression\n");
                printf("\nEnter Infix Expression here: ");
                convertPrefixtoInfix(Expression);
                printf("\n");
                break;
            case 5:
                printf("\nEnter the Postfix Expression here: ");
                scanf("%s", Expression);
                while (!isPostfix(Expression)) {
                    printf("\nInvalid Input\n");
                    printf("\nEnter the Postfix Expression again here: ");
                    scanf("%s", Expression);
                }
                printf("\nIt sounds like Postfix Expression\n");
                printf("\nEnter Prefix Expression here: ");
                convertPostfixtoPrefix(Expression);
                printf("\n");
                break;
            case 6:
                printf("\nEnter the Prefix Expression here: ");
                scanf("%s", Expression);
                while (!isPrefix(Expression)) {
                    printf("\nInvalid Input\n");
                    printf("\nEnter the Prefix Expression again here: ");
                    scanf("%s", Expression);
                }
                printf("\nIt sounds like Prefix Expression\n");
                printf("\nEnter Postfix Expression here: ");
                convertPrefixtoPostfix(Expression);
                printf("\n");
                break;
            case 7:
                printf("\nGood Bye, TATA\n");
                break;
        }
    } while (choice != 7);
}