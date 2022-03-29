#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct STUDENT {
    int Student_RollNo;
    char Student_Name[50], Student_Gender;
    struct STUDENT *next;
};

struct STUDENT *FRONT = NULL;
struct STUDENT *REAR = NULL;

struct STUDENT Male_Students[100];
struct STUDENT Female_Student[100];

int FRONT_Male = -1, Rear_Male = -1, FRONT_Female = -1, REAR_Female = -1;

int isEmpty();
void enQueue();
void deQueue();
void displayQueue();
void displayFront();
void traverseMale();
void traverseFemale();
void displayMaleQueue();
void displayFemaleQueue();

int main() {
    printf("\nWhat SIZE of the Queue would you like to have: ");
    int choice;

    do {
        printf("\n1. Enqueue: Insert a new element (Student) in the Queue\n");
        printf("\n2. Dequeue: Delete first element (Student) from the Queue\n");
        printf("\n3. Display: View list of elements (Student) in the Queue\n");
        printf("\n4. Display Front Element: Display Element (Student) Present at the Starting of the Queue\n");
        printf("\n5. Display Only Male Students\n");
        printf("\n6. Display Only Female Students\n");
        printf("\n7. Exit");

        printf("\n\nWhich Operation would you like to perform now: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                enQueue();
                break;
            case 2:
                deQueue();
                break;
            case 3:
                displayQueue();
                break;
            case 4:
                displayFront();
                break;
            case 5:
                traverseMale();
                break;
            case 6:
                traverseFemale();
                break;
            case 7:
                printf("\nGood Bye, See You Again\n");
                break;
        }
    } while (choice != 7);
}

int isEmpty() {
    if (FRONT == NULL && REAR == NULL)
        return 1;
    else
        return 0;
}

void enQueue() {
    struct STUDENT *New_Node = (struct STUDENT *)malloc(sizeof(struct STUDENT));

    printf("\nStudent's Roll No: ");
    scanf("%d", &New_Node -> Student_RollNo);

    printf("Student's Student_Name: ");
    scanf("%s", New_Node -> Student_Name);

    printf("Student's Gender (M or F): ");
    New_Node -> Student_Gender = getchar();
    scanf("%c", &New_Node -> Student_Gender);

    New_Node -> next = NULL;

    if (FRONT == NULL && REAR == NULL) {
        FRONT = New_Node;
        REAR = New_Node;
    }
    else {
        struct STUDENT *temp = FRONT;

        while (temp -> next != NULL)
            temp = temp -> next;

        temp -> next = New_Node;
        REAR = New_Node;
    }
}

void deQueue() {
    if (!isEmpty()) {
        printf("Student's Name: %s\n", FRONT -> Student_Name);
        printf("Student's Roll No.: %d\n", FRONT -> Student_RollNo);
        printf("Student's Gender: %c\n", FRONT -> Student_Gender);
        if (FRONT == REAR) {
            FRONT = NULL;
            REAR = NULL;
        }
        else
            FRONT = FRONT -> next;
    }
    else
        printf("\nOops, Underflow .....\n");
}

void displayQueue() {
    struct STUDENT *temp = FRONT;
    if (isEmpty())
        printf("\nOops, Underflow .....\n");
    else
        while (temp != NULL) {
            printf("Student's Name: %s\n", FRONT -> Student_Name);
            printf("Student's Roll No.: %d\n", FRONT -> Student_RollNo);
            printf("Student's Gender: %c\n", FRONT -> Student_Gender);
            temp = temp -> next;
        }
}

void displayFront() {
    if (isEmpty())
        printf("\nOops, Underflow .....\n");
    else {
        printf("Student's Name: %s\n", FRONT -> Student_Name);
        printf("Student's Roll No.: %d\n", FRONT -> Student_RollNo);
        printf("Student's Gender: %c\n", FRONT -> Student_Gender);
    }
}

void traverseMale() {
    struct STUDENT *temp = FRONT;
    if (isEmpty()) {
        printf("\nOops, Underflow .....\n");
    }
    else {
        while (temp != NULL) {
            if (temp -> Student_Gender == 'm' || temp -> Student_Gender == 'M')
                printf("Student's Name: %s\n", temp -> Student_Name);

            temp = temp -> next;
        }
    }
}

void traverseFemale() {
    struct STUDENT *temp = FRONT;
    if (isEmpty())
        printf("\nOops, Underflow .....\n");
    else {
        while (temp != NULL) {
            if (temp -> Student_Gender == 'f' || temp -> Student_Gender == 'F')
                printf("Student's Name: %s\n", temp -> Student_Name);

            temp = temp -> next;
        }
    }
}

void displayMaleQueue() {
    struct STUDENT *temp = FRONT;

    if (isEmpty())
        printf("\nNo Male Student Found\n");
    else {
        while (temp != NULL) {
            if (temp -> Student_Gender == 'm' || temp -> Student_Gender == 'M') {
                if (FRONT_Male == -1 && Rear_Male == -1) {
                    FRONT_Male = FRONT_Male + 1;
                    Rear_Male = Rear_Male + 1;
                    strcpy(Male_Students[Rear_Male].Student_Name, temp -> Student_Name);
                    Male_Students[Rear_Male].Student_RollNo = temp -> Student_RollNo;
                    Male_Students[Rear_Male].Student_Gender = temp -> Student_Gender;
                }
                else {
                    Rear_Male = Rear_Male + 1;
                    strcpy(Male_Students[Rear_Male].Student_Name, temp -> Student_Name);
                    Male_Students[Rear_Male].Student_RollNo = temp -> Student_RollNo;
                    Male_Students[Rear_Male].Student_Gender = temp -> Student_Gender;
                }
            }

            temp = temp -> next;
        }

        int t = FRONT_Male;

        if (FRONT_Male == -1 && Rear_Male == -1)
            printf("\nNo Male Student Found\n");
        else {
            printf("Male Student Names Listed Below:");
            printf("\n-----------------------------------------------------------\n");
            while (t <= Rear_Male)
                printf("%s\n", Male_Students[t++].Student_Name);
        }
    }
}

void displayFemaleQueue() {
    struct STUDENT *temp = FRONT;
    if (isEmpty())
    printf("\nNo Female Student Found\n");
    else {
        while (temp != NULL) {
            if (temp -> Student_Gender == 'f' || temp -> Student_Gender == 'F') {
                if (FRONT_Female == -1 && REAR_Female == -1) {
                    FRONT_Female = FRONT_Female + 1;
                    REAR_Female = REAR_Female + 1;
                    strcpy(Female_Student[REAR_Female].Student_Name, temp -> Student_Name);
                    Female_Student[REAR_Female].Student_RollNo = temp -> Student_RollNo;
                    Female_Student[REAR_Female].Student_Gender = temp -> Student_Gender;
                }
                else {
                    REAR_Female = REAR_Female + 1;
                    strcpy(Female_Student[REAR_Female].Student_Name, temp -> Student_Name);
                    Female_Student[REAR_Female].Student_RollNo = temp -> Student_RollNo;
                    Female_Student[REAR_Female].Student_Gender = temp -> Student_Gender;
                }
            }

            temp = temp -> next;
        }

        int t = FRONT_Female;

        if (FRONT_Female == -1 && REAR_Female == -1)
            printf("\nNo Female Student Found\n");
        else {
            printf("Female Student Names Listed Below:");
            printf("\n-----------------------------------------------------------\n");
            while (t <= REAR_Female)
                printf("%s\n", Female_Student[t++].Student_Name);
        }
    }
}