#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student {
    int Roll_No;
    char Name[50]; // Student
    float Marks;
    struct Student *next;
};

void Insert(struct Student **head, int Roll_No, char Name[], float Marks) {
    struct Student *NewStudent = (struct Student *)malloc(sizeof(struct Student));
    NewStudent->Roll_No = Roll_No;
    strcpy(NewStudent->Name, Name);
    NewStudent->Marks = Marks;
    NewStudent->next = NULL;

    struct Student *temp = *head;
    if (temp == NULL) {
        // Adding the student record into the Link list
        *head = NewStudent;
    }
    else {
        while (temp != NULL) {
            if (temp->Roll_No == Roll_No) {
                printf("\nRoll No. %d is already present in Linked List", Roll_No);
                return;
            }
            temp = temp->next;
        }
        temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = NewStudent;
    }
}

void delete (struct Student **head, int Roll_No) {
    struct Student *prev = *head;
    struct Student *last = *head;
    while (last->Roll_No != Roll_No) {
        prev = last;
        last = last->next;
    } // Delete a student record
    if (prev == last) {
        last = last->next;
        *head = last;
        free(prev);
        prev = *head;
        return;
    }
    prev->next = last->next;
    free(last);
}

void display(struct Student *temp) {
    int choice, Roll_No;

    printf("\n1. Want to display particular Roll No?\n2. Want to display all?\n");
    printf("Enter Your Choice: ");
    scanf("%d", &choice);

    switch (choice) {
        // Display Student Record
        case 1:
            printf("\nEnter the roll no to display: ");
            scanf("%d", &Roll_No);
            while (temp->Roll_No != Roll_No) {
                temp = temp->next;
            }
            printf("Roll No.\tName\tMarks\n");
            printf("%d\t%s\t%f\n", temp->Roll_No, temp->Name, temp->Marks);
            break;

        case 2:
            printf("Roll No.\tName\tMarks\n");
            while (temp != NULL) {
                printf("%d\t%s\t%f\n", temp->Roll_No, temp->Name, temp->Marks);
                temp = temp->next;
            }
            break;
    }
}

void update(struct Student **head, int Roll_No) {
    int choice;
    char Name[50];
    float Marks;

    printf("\n1. Do you want to update name?\n\tOR\n");
    printf("\n2. Do you Want to update marks?\n");
    printf("\n\nEnter Your Choice: ");
    scanf("%d", &choice);
    // Update a Student Record
    struct Student *last = *head;

    switch (choice) {
        case 1:
            printf("Enter New Name: ");
            scanf("%s", Name);
            while (last->Roll_No != Roll_No) {
                last = last->next;
            }

            strcpy(last->Name, Name);
            break;

        case 2:
            printf("Enter New Marks: ");
            scanf("%f", &Marks);
            while (last->Roll_No != Roll_No) {
                last = last->next;
            }

            last->Marks = Marks;
            break;
    }
}

int main() {
    int n, Roll_No;
    char Name[50];
    float Marks;

    struct Student *head = NULL;

    while(1) {
        printf("1. Insert a student record\n");
        printf("2. Delete a student record\n");
        printf("3. Update a student record\n");
        printf("4. Display record\n");
        printf("5. Exit\n");

        printf("\n\nEnter Your Choice: ");
        scanf("%d", &n);

        switch (n) {
            case 1:
                printf("Enter Roll No: ");
                scanf("%d", &Roll_No);
                printf("Enter Name: ");
                scanf("%s", Name);
                printf("Enter Marks: ");
                scanf("%f", &Marks);
                Insert(&head, Roll_No, Name, Marks);
                break;
            case 2:
                printf("Enter Roll No which you want to Delete: ");
                scanf("%d", &Roll_No);
                delete (&head, Roll_No);
                break;
            case 3:
                printf("Enter the Roll No which you want to Update: ");
                scanf("%d", &Roll_No);
                update(&head, Roll_No);
                break;
            case 4:
                display(head);
                break;
            case 5:
                printf("\nEnding ...\n");
                break;
            default:
                printf("\nInvalid Choice\nRetry Now\n\n");
                break;
        }

        if (n == 5)
            break;
    }
}