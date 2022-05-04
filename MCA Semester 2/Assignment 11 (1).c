#include <stdio.h>  // Standard input/output definitions
#include <stdlib.h> // Standard library
#include <string.h> // Standard string manipulation

// Implementation of the Priority Queue using Linked List
typedef struct node
{
    char patientName[20];
    char emergencyToken[20];
    char patientGender[6];
    int priority;
    struct node *next;
} node;

// Create a new node in the Priority Queue
node *newNode(char patientName[20], char emergencyToken[20], char patientGender[6], int priority)
{
    node *newNode = (node *)malloc(sizeof(node));    // Allocate memory for the new node
    strcpy(newNode->patientName, patientName);       // Copy the patient name
    strcpy(newNode->emergencyToken, emergencyToken); // Copy the emergency token
    strcpy(newNode->patientGender, patientGender);   // Copy the patient
    newNode->priority = priority;                    // Copy the priority
    newNode->next = NULL;                            // Set the next node to NULL
    return newNode;                                  // Return the new node
}

// Enqueue the node in the Priority Queue
void enqueue(node **head, node *newNode)
{
    if (*head == NULL) // If the head is NULL
    {
        *head = newNode; // If the head is NULL, set the head to the new node
        return;          // Return
    }
    node *current = *head;                                                 // Set the current node to the head
    while (current->next != NULL && current->priority < newNode->priority) // Loop until the current node is NULL or the current node's priority is less than the new node's priority
    {
        current = current->next; // Move to the next node
    }
    newNode->next = current->next; // Set the next node to the current node
    current->next = newNode;       // Set the current node to the new node
}

// Dequeue the node from the Priority Queue
node *dequeue(node **head)
{
    if (*head == NULL) // If the head is NULL
    {
        return NULL; // Return NULL
    }
    node *current = *head; // Set the current node to the head
    *head = current->next; // Set the head to the next node
    return current;        // Return the current node
}

// Print Front of the Priority Queue
void printFront(node *head)
{
    if (head == NULL) // If the head is NULL
    {
        printf("Queue is empty\n"); // Print that the queue is empty
        return;                     // Return
    }
    printf("Patient's Name: %s\n", head->patientName);               // Print the patient's name
    printf("Patient's Emergency Token: %s\n", head->emergencyToken); // Print the patient's emergency token
    printf("Patient's Gender%s\n", head->patientGender);             // Print the patient's gender
    printf("Patient's Priority: %d\n", head->priority);              // Print the patient's priority
}

// Display the Priority Queue
void display(node *head)
{
    if (head == NULL) // If the head is NULL
    {
        printf("Queue is empty\n"); // Print that the queue is empty
        return;                     // Return
    }
    node *current = head;                      // Set the current node to the head
    printf("Name\tToken\tGender\tPriority\n"); // Print the headers
    while (current != NULL)                    // Loop until the current node is NULL
    {
        printf("%s\t%s\t%s\t%d\n", current->patientName, current->emergencyToken, current->patientGender, current->priority); // Print the current node
        current = current->next;                                                                                              // Move to the next node
    }
}

// Print the Patient's Details for a given Priority
void traversePatient(node *head, int priority)
{
    if (head == NULL) // If the head is NULL
    {
        printf("Queue is empty\n"); // Print that the queue is empty
        return;                     // Return
    }
    node *current = head;   // Set the current node to the head
    while (current != NULL) // Loop until the current node is NULL
    {
        if (current->priority == priority) // If the current node's priority is equal to the given priority
        {
            printf("Patient's Name: %s\n", current->patientName);               // Print the patient's name
            printf("Patient's Emergency Token: %s\n", current->emergencyToken); // Print the patient's emergency token
            printf("Patient's Gender: %s\n", current->patientGender);           // Print the patient's gender
        }
        current = current->next; // Move to the next node
    }
}

int main()
{
    node *head = NULL; // Initialize the head as NULL
    node *deletedNode; // Initialize the deleted node variable

    int choice, priority;                                       // Initialize the choice and priority variables
    char patientName[20], emergencyToken[20], patientGender[6]; // Initialize the patient's name, emergency token, and patient's

    do // Loop until the user chooses to exit
    {
        printf("\nPriority Queue\n"); // Print the menu
        printf("1. Enqueue\n");       // Print the option to enqueue
        printf("2. Dequeue\n");       // Print the option to dequeue
        printf("3. Print Front\n");   // Print the option to print the front
        printf("4. Display\n");       // Print the option to display
        printf("5. Traverse\n");      // Print the option to traverse
        printf("6. Exit\n");          // Print the option to exit
        printf("Enter your choice: ");
        scanf("%d", &choice); // Get the user's choice

        switch (choice) // Switch on the user's choice
        {
        case 1: // If the user chooses to enqueue
            printf("Enter patient name: ");
            scanf("%s", patientName); // Get the patient's name
            printf("Enter emergency token: ");
            scanf("%s", emergencyToken); // Get the patient's emergency token
            printf("Enter patient's gender: ");
            scanf("%s", patientGender); // Get the patient's gender
            printf("Enter the priority: ");
            scanf("%d", &priority); // Get the priority
            enqueue(&head, newNode(patientName, emergencyToken, patientGender, priority));
            break;
        case 2:
            deletedNode = dequeue(&head);
            if (deletedNode != NULL)                                       // If the deleted node is not NULL
                printf("Deleted node is: %s\n", deletedNode->patientName); // Print the Deleted node
            else
            {
                printf("Queue is empty\n"); // Print that the queue is empty
            }
            break;
        case 3:
            printFront(head); // Print the front
            break;
        case 4:
            display(head); // Display the queue
            break;
        case 5:
            printf("Enter the priority: ");
            scanf("%d", &priority);          // Get the priority
            traversePatient(head, priority); // Traverse the patient with the given priority
            break;
        case 6:
            printf("Good Bye, See you soon!\n"); // Print that the user is exiting
            break;
        default:
            printf("Oops, Please try again\n"); // Print that the user entered an invalid choice
            break;
        }
    } while (choice != 6); // Loop until the user chooses to exit

    return 0; // Return 0
}