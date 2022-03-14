#include <stdio.h>
#include <stdlib.h>

int c = -1;

struct Student {
    int StudentRoll_No;
    char StudentName[50]; // Student
    float StudentMarks;
    struct Student *next;
};

struct Student *top = NULL;

void Push(int size) {
    struct Student *new_student = (struct Student *)malloc(sizeof(struct Student));

    printf("\nEnter Student's Name:");
    scanf("%d", &new_student->StudentRoll_No);
    printf("Enter Student's Roll Number:");
    scanf("%s", new_student->StudentName);
    printf("Enter Student's Marks:");
    scanf("%f", &new_student->StudentMarks);

    if (top == NULL) {
        new_student->next = NULL;
        top = new_student;
        c++;
    }
    else {
        struct Student *temp = top;
        new_student->next = top;
        top = new_student;
        c++;
    }
}

void Pop() {
    struct Student *temp = top;
    top = top->next;

    printf("\n\t The popped elements from the STACK is:\n");
    printf("Student's Name\tStudent's Roll Number\tStudent's Marks\n");
    printf("%s\t\t%d\t\t%f\n", temp->StudentName, temp->StudentRoll_No, temp->StudentMarks);
    free(temp);
    c--;
}

void display() {
    struct Student *temp = top;

    printf("\n The elements in STACK \n");
    printf("Student's Name\tStudent's Roll Number\tStudent's Marks\n");
    while (temp != NULL) {
        printf("%s\t\t%d\t\t%f\n", temp->StudentName, temp->StudentRoll_No, temp->StudentMarks);
        temp = temp->next;
    }
}

int IsFullStack(int size) {
    if (c == size - 1) {
        printf("\n\tSTACK is overflow");
        return 1;
    }
    else
        return 0;
}

int IsEmptyStack() {
    if (top == NULL) {
        printf("\n\tSTACK is underflow");
        return 1;
    }
    else
        return 0;
}

int main() {
    int choice, size, t;
    printf("Enter size of STACK: ");
    scanf("%d", &size);

    do {
        printf("\n\t Which Operation that we can perform on STACK: ");
        printf("\n\t--------------------------------");
        printf("\n\t 1. PUSH Element\n\t 2. POP Element\n\t 3. DISPLAY All Elements\n\t 4. EXIT From Program");
        printf("\n Enter Your Choice:");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                t = IsFullStack(size);
                if (t == 0)
                    Push(size);
                break;
            case 2:
                t = IsEmptyStack();
                if (t == 0)
                    Pop(size);
                break;
            case 3:
                t = IsEmptyStack();
                if (!t)
                    display();
                break;
            case 4:
                printf("\n\tThank You For Using This Program");
                break;
        }
    } while (choice != 4);
}