#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int CopyOperations = 0, TotalOperations = 0, STACKsize = 1, top = -1;

struct Student
{
    char StudentName[50];
    int StudentRoll_No;
    float StudentMarks;
};

struct Student *STACK;

void PrintingData(int TotalOperations, int CopyOperations, int top)
{
    printf("\nSteps which are processed till now, these includes Push, Pop Copy of Stack, and  Memory Allocation: %d\n", TotalOperations);
    printf("Total number of copy operations performed till now: %d\n", CopyOperations);
    printf("Total Number of Elements in STACK: %d\n", top + 1);
}

int IsFullStack()
{
    if (top == STACKsize - 1)
        return 1;
    else
        return 0;
}

int IsEmptyStack()
{
    if (top == -1)
        return 1;
    else
        return 0;
}

void Push()
{
    if (!IsFullStack())
    {
        top = top + 1;
        printf("\nEnter Student's Name: ");
        scanf("%s", STACK[top].StudentName);
        printf("Enter Student's Roll No: ");
        scanf("%d", &STACK[top].StudentRoll_No);
        printf("Enter Student's Marks: ");
        scanf("%f", &STACK[top].StudentMarks);

        TotalOperations = TotalOperations + 1;

        printf("\nPushing ....\n");
        printf("Pushed!\n");
        PrintingData(TotalOperations, CopyOperations, top);
    }
    else
    {
        printf("\nIncreasing Stack Size ..... \n");
        printf("\nDone, Stack Size Increased!\n");

        struct Student *t = (struct Student *)calloc(STACKsize, sizeof(struct Student));
        for (int i = 0; i < STACKsize; i++)
        {
            strcpy(t[i].StudentName, STACK[i].StudentName);
            t[i].StudentRoll_No = STACK[i].StudentRoll_No;
            t[i].StudentMarks = STACK[i].StudentMarks;
        }
        free(STACK);
        STACK = NULL;

        STACK = (struct Student *)calloc(STACKsize * 2, sizeof(struct Student));
        for (int i = 0; i < STACKsize; i++)
        {
            strcpy(STACK[i].StudentName, t[i].StudentName);
            STACK[i].StudentRoll_No = t[i].StudentRoll_No;
            STACK[i].StudentMarks = t[i].StudentMarks;
        }
        free(t);
        t = NULL;

        top = top + 1;
        STACKsize = STACKsize * 2;

        printf("\nEnter the StudentName: ");
        scanf("%s", STACK[top].StudentName);
        printf("Enter the roll no: ");
        scanf("%d", &STACK[top].StudentRoll_No);
        printf("Enter the Marks: ");
        scanf("%f", &STACK[top].StudentMarks);

        TotalOperations = TotalOperations + 5;
        CopyOperations = CopyOperations + 2;

        printf("\nElement pushed\n");
        PrintingData(TotalOperations, CopyOperations, top);
    }
}

void Pop()
{
    if (!IsEmptyStack())
    {
        printf("\nPopping ....\n");
        printf("Popped!\n");
        printf("\n\t The popped elements from the STACK is:\n");
        printf("Student's Name\tStudent's Roll Number\tStudent's Marks\n");
        printf("%s\t\t%d\t\t%f\n", STACK[top].StudentName, STACK[top].StudentRoll_No, STACK[top].StudentMarks);
        printf("Stack Size Decreased!\n");
        top = top - 1;
        TotalOperations = TotalOperations + 1;
        PrintingData(TotalOperations, CopyOperations, top);
    }
    else
        printf("\nStack is underflow!\n");
}

void display()
{
    int t = top;
    printf("\nStudent's Name\tStudent's Roll No\tStudent's Marks\n");
    while (t >= 0)
    {
        printf("%s\t\t%d\t\t%f\n", STACK[t].StudentName, STACK[t].StudentRoll_No, STACK[t].StudentMarks);
        t--;
    }
    if (top == -1)
    {
        printf("\nStack is underflow!\n");
        return;
    }

    PrintingData(TotalOperations, CopyOperations, top);
}

int main()
{
    STACK = (struct Student *)calloc(STACKsize, sizeof(struct Student));

    int choice;

    printf("Hello User, I'm a Program to demonstrate the Stack Data Structure\n");
    printf("It works on the basis of the concept of LIFO (Last In First Out)\n");
    printf("It would be great if you can test me!\n");

    do
    {
        printf("\n1. Push\n");
        printf("2. Pop\n");
        printf("3. Display\n");
        printf("4. Count of total copy operations\n");
        printf("5. Number of Elements present in the STACK\n");
        printf("6. Steps to complete the program\n");
        printf("7. Exit\n\n");

        printf("Kindly, enter your choice here: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            Push(&STACKsize);
            break;
        case 2:
            Pop(&STACKsize);
            break;
        case 3:
            display();
            break;
        case 4:
            printf("\nCopy Operations Performed till now: %d\n", CopyOperations);
            break;
        case 5:
            printf("\nTotal Number of Elements in STACK: %d\n", top + 1);
            break;
        case 6:
            printf("\nSteps which are processed till now, these includes Push, Pop Copy of Stack, and  Memory Allocation: %d\n", TotalOperations);
            break;
        case 7:
            printf("\n\tThank You for testing me!\n");
            break;
        default:
            printf("\n\tInvalid Choice, Retry\n");
            break;
        }
    } while (choice != 7);
}