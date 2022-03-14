#include <stdio.h>
#include <stdlib.h>

int choice, n, top, i;

struct Student {
    int StudentRoll_No;
    char StudentName[50]; // Student
    float StudentMarks;
};

struct Student STACK[100];

void Push() {
    top++;
    printf(" Enter Student's Name:");
    scanf("%s", STACK[top].StudentName);
    printf(" Enter Student's Roll Number:");
    scanf("%d", &STACK[top].StudentRoll_No);
    printf(" Enter Student's Marks:");
    scanf("%f", &STACK[top].StudentMarks);
}

int Pop() {
    printf("\n\t The popped elements from the STACK is:\n");
    printf("Student's Name\tStudent's Roll Number\tStudent's Marks\n");
    printf("%s\t\t%d\t\t%f", STACK[top].StudentName, STACK[top].StudentRoll_No, STACK[top].StudentMarks);
    top--;
    return 1;
}

void display() {
    printf("\n The elements in STACK \n");
    for (i = top; i >= 0; i--)
        printf("\n%s\t\t%d\t\t%f", STACK[i].StudentName, STACK[i].StudentRoll_No, STACK[i].StudentMarks);
}

int IsEmptyStack() {
    if (top == -1) {
        printf("\n\tSTACK is underflow");
        return 1;
    }
    else
        return 0;
}

int Size() {
    return top + 1;
}

int IsFullStack() {
    if (top == n - 1) {
        printf("\n\tSTACK is overflow");
        return 1;
    }
    else
        return 0;
}

int Top() {
    return STACK[top].StudentRoll_No;
}

int main() {
    top = -1;
    printf("\n Enter size of STACK[MAX=100]:");
    scanf("%d", &n);
    do {
        printf("\n\t Which Operation that we can perform on STACK: ");
        printf("\n\t--------------------------------");
        printf("\n\t 1. PUSH Element\n\t 2. POP Element\n\t 3. DISPLAY All Elements\n\t 4. EXIT From Program");
        printf("\n Enter Your Choice:");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                int temp = IsFullStack();
                if (temp == 0)
                    Push();
                break;
            case 2:
                int temp = IsEmptyStack();
                if (temp == 0)
                    Pop();
                break;
            case 3:
                int temp = IsEmptyStack();
                if (!temp)
                    display();
                break;
            case 4:
                printf("\n\t Exiting ... ");
                break;
            default:
                printf("\n\t Kindly Enter a Valid Choice from numbers 1 to 4");
        }
    } while (choice != 4);
    return 0;
}