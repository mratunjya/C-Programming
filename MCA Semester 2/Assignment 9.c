#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 100

struct STUDENT {
    int Student_RollNo;
    char Student_Name[50], Student_Gender[10];
};

struct STUDENT QUEUE[MAX];

int FRONT = -1, REAR = -1;

int isFull(int SIZE);

void enQueue(int SIZE);

int isEmpty();

void deQueue(int SIZE);

void displayQueue(int SIZE);

int main() {
    int choice, SIZE;

    printf("\nWhat SIZE of the Queue would you like to have: ");
    scanf("%d", &SIZE);

    do {
        printf("\n1. Enqueue: Insert a new element (Student) in the Queue\n");
        printf("\n2. Dequeue: Delete first element (Student) from the Queue\n");
        printf("\n3. Display: View list of elements (Student) in the Queue\n");
        printf("\n4. Exit");

        printf("\n\nWhich Operation would you like to perform now: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                enQueue(SIZE);
                break;
            case 2:
                deQueue(SIZE);
                break;
            case 3:
                displayQueue(SIZE);
                break;
            case 4:
                printf("\nGood Bye, See You Again\n");
                break;
        }
    } while (choice != 4);
}

int isEmpty() {
    if (FRONT != -1 && REAR != -1)
        return 0;
    else
        return 1;
}

int isFull(int SIZE) {
    if ((FRONT != 0 && REAR != SIZE - 1) || (FRONT != (REAR + 1)))
        return 0;
    else
        return 1;
}

void enQueue(int SIZE) {
    if (isFull(SIZE))
        printf("\nOops, Overflow .....\n");
    else {
        if (FRONT == -1)
            FRONT = 0;

        REAR = (REAR + 1) % SIZE;

        printf("\nStudent's Roll No: ");
        scanf("%d", &QUEUE[REAR].Student_RollNo);

        printf("Student's Student_Name: ");
        scanf("%s", QUEUE[REAR].Student_Name);

        printf("Student's Gender: ");
        scanf("%s", QUEUE[REAR].Student_Gender);

        printf("Inserting ...");
        printf("\nData is successfully stored in the Queue ...\n", REAR);
    }
}

void deQueue(int SIZE) {
    if (isEmpty())
        printf("\nOops, Underflow\n");
    else {
        printf("\nDeleting ...\n\n");
        printf("Student's Roll No\tStudent's Name\tStudent's Gender\n");
        printf("%d\t\t\t\t%s\t\t%s", QUEUE[FRONT].Student_RollNo, QUEUE[FRONT].Student_Name, QUEUE[FRONT].Student_Gender, FRONT);
        printf("\nData is successfully deleted from the Queue ...\n");

        if (FRONT == REAR)
            FRONT = REAR = -1;
        else
            FRONT = (FRONT + 1) % SIZE;
    }
}

void displayQueue(int SIZE) {
    int t = FRONT;
    if (isEmpty())
        printf("\nUnderflow\n");
    else {
        printf("Loading Student's List ....\n\n");
        printf("Student's Roll No\tStudent's Name\tStudent's Gender\n");

        while (t != REAR) {
            printf("%d\t\t\t\t%s\t\t\t%s\n", QUEUE[t].Student_RollNo, QUEUE[t].Student_Name, QUEUE[t].Student_Gender, FRONT);
            t = (t + 1) % SIZE;
        }
    };
}