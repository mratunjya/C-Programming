#include <stdio.h>  // Standard input/output definitions
#include <stdlib.h> // Standard library
#include <string.h> // Standard string manipulation
#include <limits.h> // Limits
#define MAX 100     // Maximum number of patients

// Implementation of the Priority Queue using an Array
int front = -1; // Front of the queue

char patientName[MAX][20];    // Array of patient names
char emergencyToken[MAX][20]; // Array of emergency tokens
char patientGender[MAX][6];   // Array of patient
int priority[MAX];            // Array of priorities

// Enqueue the Patient in the Priority Queue
void enqueue(char name[20], char token[20], char gender[6], int prty)
{
    if (front == MAX - 1) // If the front is at the maximum number of patients
    {
        printf("Queue is full\n"); // Print that the queue is full
        return;                    // Return
    }

    front++;                              // Increment the front
    strcpy(patientName[front], name);     // Copy the patient name
    strcpy(emergencyToken[front], token); // Copy the emergency token
    strcpy(patientGender[front], gender); // Copy the patient
    priority[front] = prty;               // Copy the priority
}

int isEmpty()
{
    if (front == -1) // If the front is at the minimum number of patients
        return 0;    // Return 0

    return 1; // Return 1
}

// Dequeue the Patient from the Priority Queue and Print the Patient Details
void dequeue()
{
    if (isEmpty()) // If the queue is empty
    {
        printf("Queue is empty\n"); // Print that the queue is empty
        return;                     // Return
    }

    printf("Dequeued Patient: \n");                         // Print that the patient is dequeued
    printf("Patient's Name: %s\n", patientName[front]);     // Print the patient name
    printf("Emergency Token: %s\n", emergencyToken[front]); // Print the emergency token
    printf("Patient's Gender: %s\n", patientGender[front]); // Print the gender
    printf("Priority: %d\n", priority[front]);              // Print the priority
    front--;                                                // Decrement the front
}

// Print Front of the Priority Queue
void printFront()
{
    if (isEmpty()) // If the queue is empty
    {
        printf("Queue is empty\n"); // Print that the queue is empty
        return;                     // Return
    }

    printf("Front of Priority Queue -\n");                  // Print the headers
    printf("Patient's Name: %s\n", patientName[front]);     // Print the patient name
    printf("Emergency Token: %s\n", emergencyToken[front]); // Print the emergency token
    printf("Patient's Gender: %s\n", patientGender[front]); // Print the gender
    printf("Priority: %d\n", priority[front]);              // Print the priority
}

// Display all patient Details
void display()
{
    if (isEmpty()) // If the queue is empty
    {
        printf("Queue is empty\n"); // Print that the queue is empty
        return;                     // Return
    }

    printf("All Patients: \n");
    printf("Name\tToken\tGender\tPriority"); // Print the headers
    for (int i = 0; i <= front; i++)
        printf("\n%s\t%s\t%s\t%d", patientName[i], emergencyToken[i], patientGender[i], priority[i]); // Print the patient details
}

// Print the patient Details in ascending order of priority
void printAscending()
{
    if (isEmpty()) // If the queue is empty
    {
        printf("Queue is empty\n"); // Print that the queue is empty
        return;                     // Return
    }

    printf("Priority Queue in Ascending Order -\n"); // Print the headers
    printf("Name\nToken\nGender\tPriority");         // Print the headers
    for (int i = 0; i <= front; i++)
    {
        if (priority[i] == priority[i + 1])                                                               // If the priority is equal to the next priority
            printf("\n%s\t%s\t%s\t%d", patientName[i], emergencyToken[i], patientGender[i], priority[i]); // Print the patient details
        else
        {
            printf("\n%s\t%s\t%s\t%d", patientName[i], emergencyToken[i], patientGender[i], priority[i]);                 // Print the patient details
            printf("\n%s\t%s\t%s\t%d", patientName[i + 1], emergencyToken[i + 1], patientGender[i + 1], priority[i + 1]); // Print the patient details
        }
    }
}

// Print the Patient's Details for a given Priority
void traverse(int prty)
{
    if (isEmpty()) // If the queue is empty
    {
        printf("Queue is empty\n"); // Print that the queue is empty
        return;                     // Return
    }

    int count = 0;                                 // Count the number of patients with the given priority
    printf("Patients with Priority %d -\n", prty); // Print the headers
    printf("Name\tToken\tGender\tPriority");       // Print the headers
    for (int i = 0; i <= front; i++)               // Loop through the patients
    {
        if (priority[i] == prty) // If the priority is equal to the given priority
        {
            count++;
            printf("\n%s\t%s\t%s\t%d", patientName[i], emergencyToken[i], patientGender[i], priority[i]); // Print the patient details
        }
    }
    if (count == 0)                                        // If there are no patients with the given priority
        printf("\nNo patients with the given priority\n"); // Print that there are no patients with the given priority
}

int main()
{
    int choice;     // Choice
    int prty;       // Priority
    char name[20];  // Patient Name
    char token[20]; // Emergency Token
    char gender[6]; // Patient Gender

    do
    {
        printf("\nPriority Queue\n");                                            // Print the menu
        printf("1. Enqueue\n");                                                  // Print the option to enqueue
        printf("2. Dequeue\n");                                                  // Print the option to dequeue
        printf("3. Print Front\n");                                              // Print the option to print the front
        printf("4. Display\n");                                                  // Print the option to display
        printf("5. Print All Patient Details in Ascending order of Priority\n"); // Print the option to print the ascending order
        printf("6. Traverse (Search)\n");                                        // Print the option to traverse
        printf("7. Exit\n");                                                     // Print the option to exit
        printf("Enter your choice: ");
        scanf("%d", &choice); // Get the user's choice

        switch (choice)
        {
        case 1: // If the user wants to enqueue
            printf("Enter the patient's name: ");
            scanf("%s", name); // Get the patient's name
            printf("Enter the patient's emergency token: ");
            scanf("%s", token); // Get the patient's emergency token
            printf("Enter the patient's Gender: ");
            scanf("%s", gender); // Get the patient's gender
            printf("Enter the priority: ");
            scanf("%d", &prty);                 // Get the priority
            enqueue(name, token, gender, prty); // Enqueue Patient data
            break;
        case 2:        // If the user wants dequeue
            dequeue(); // Dequeue the patient
            break;
        case 3:           // If the user wants to print Front
            printFront(); // Print the front
            break;
        case 4:        // If the user wants to print the patient details
            display(); // Print the patient details
            break;
        case 5:               // If the user wants to print the patient details in ascending order of priority
            printAscending(); // Print the patient details in ascending order of priority
            break;
        case 6:                             // If the user wants to traverse
            printf("Enter the priority: "); // Get the priority
            scanf("%d", &prty);             // Get the priority
            traverse(prty);                 // Print the patient details for the given priority
            break;
        case 7:
            printf("Good Bye, See you soon!\n"); // Print that the user is exiting
            break;
        default:
            printf("Oops, Please try again\n"); // Print that the user entered an invalid choice
            break;
        }
    } while (choice != 7); // Loop until the user exits

    return 0; // Return
}