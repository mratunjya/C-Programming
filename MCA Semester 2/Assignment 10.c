#include <stdio.h>   // Standard input/output definitions
#include <stdlib.h>  // Standard library
#include <stdbool.h> // for bool type (true/false)

// Node structure
struct node
{
    int data;           // data
    struct node *left;  // left child
    struct node *right; // right child
};

// Create a new node
struct node *createNode(int data)
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node)); // Allocate memory for new node

    newNode->data = data;  // Assign data to new node
    newNode->left = NULL;  // Assign left child to NULL
    newNode->right = NULL; // Assign right child to NULL

    return newNode; // Return new node
}

// ******************
// Function Instances
// ******************

// Print Degree of a node
void printDegree(struct node *root, int data);

// Print Node Level
void printNodeLevel(struct node *root, int data, int level);

// Print Node Depth
void printDepth(struct node *root, int data, int depth);

// Print Node Ancestors
bool getAncestor(struct node *root, int data, bool *flag);

// Print Node Neighbors
void printNeighbors(struct node *root, int data, int *neighbors);

// Main Function
int main()
{
    int choice, data;

    struct node *root = NULL;

    struct node *temp = createNode(1);
    root = temp;
    root->left = createNode(2);                 // Inserting a node where data = 2
    root->right = createNode(3);                // Inserting a node where data = 3
    root->left->left = createNode(4);           // Inserting a node where data = 4
    root->left->right = createNode(5);          // Inserting a node where data = 5
    root->left->right->right = createNode(8);   // Inserting a node where data = 8
    root->right->left = createNode(6);          // Inserting a node where data = 6
    root->right->right = createNode(7);         // Inserting a node where data = 7
    root->right->right->left = createNode(9);   // Inserting a node where data = 9
    root->right->right->right = createNode(10); // Inserting a node where data = 10

    do
    {
        printf("\n\n1. Get Degree of a node");
        printf("\n2. Get Level of a node");
        printf("\n3. Get Depth of a node");
        printf("\n4. Get Ancestors of a node");
        printf("\n5. Get Neighbors of a node");
        printf("\n6. Exit");

        printf("\n\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("\nEnter the data of which you want to get the degree: ");
            scanf("%d", &data);

            printDegree(root, data); // Function call to degree of a node
            break;

        case 2:
            printf("\nEnter the data of which you want to get the level: ");
            scanf("%d", &data);

            int level = -1;                    // Initialize level to -1
            printNodeLevel(root, data, level); // Function call to print the level of the node
            break;

        case 3:
            printf("\nEnter the data of which you want to get the depth: ");
            scanf("%d", &data);

            int depth = -1;                // Initialize depth with -1
            printDepth(root, data, depth); // Function call to print the depth
            break;

        case 4:
            printf("\nEnter the data of which you want to get the Ancestor: ");
            scanf("%d", &data);

            bool flag = false;                       // flag to check if the node is present or not
            printf("\nAncestors of %d are: ", data); // Prints the ancestors of the node

            getAncestor(root, data, &flag); // Function call to print the ancestors

            if (flag == false)
                printf("No Ancestors"); // If the node is not present
            break;

        case 5:
            printf("\nEnter the data of which you want to get the Neighbors: ");
            scanf("%d", &data);

            printf("\nNeighbors of %d are: ", data); // Prints the neighbors of the node
            int neighbors = 0;

            printNeighbors(root, data, &neighbors); // Function call to print the neighbors
            break;

        case 6:
            printf("\nExiting the program!\n Have a nice day!\n"); // Exit the program
            break;
        }
    } while (choice != 6); // Loop until user enters 6

    return 0; // Return 0
}

// ********************
// Function Definitions
// ********************

// Print Degree of a node
void printDegree(struct node *root, int data)
{
    if (root == NULL)
        return; // If the root is NULL, return

    if (root->data == data)
    {
        int degree = 0;

        if (root->left != NULL)
            degree = degree + 1; // Increment degree by 1 if left child is not NULL

        if (root->right != NULL)
            degree = degree + 1; // Increment degree by 1 if right child is not NULL
        printf("\nDegree is %d", degree);

        return; // Return if the node is found
    }

    // Recursively call for left and right subtrees
    printDegree(root->left, data);
    printDegree(root->right, data);
}

// Print Node Level
void printNodeLevel(struct node *root, int data, int level)
{
    if (root != NULL)
    {
        level = level + 1; // Increment level by 1

        if (root->data == data)
            printf("\nLevel of %d is %d", data, level);

        else
        {
            // Recursively call for left and right subtrees
            printNodeLevel(root->left, data, level);
            printNodeLevel(root->right, data, level);
            level = level - 1; // Decrement level by 1
        }
    }
}

// Print Node Depth
void printDepth(struct node *root, int data, int depth)
{
    if (root != NULL)
    {
        depth = depth + 1; // Increment depth by 1

        if (root->data == data)
            printf("\nDepth of %d is %d", data, depth);

        else
        {
            // Recursively call for left and right subtrees
            printDepth(root->left, data, depth);
            printDepth(root->right, data, depth);
            depth = depth - 1; // Decrement depth by 1
        }
    }
}

// Print Node Ancestors
bool getAncestor(struct node *root, int data, bool *flag)
{
    if (root == NULL)
        return false; // Return false if the node is not present

    if (root->data == data)
        return true; // Returns true if the node is there

    // Recursively call for left and right subtrees
    if (getAncestor(root->left, data, &(*flag)) || getAncestor(root->right, data, &(*flag)))
    {
        printf("%d ", root->data);
        *flag = true; // Set flag to true if the node is found

        return true; // Returns true if the node is found
    }

    return false; // Returns false if the node is not found
}

// Print Node Neighbors
void printNeighbors(struct node *root, int data, int *neighbors)
{
    if (root == NULL)
        return; // Return if the node is not present

    if (root->data == data)
    {
        *neighbors = 1; // Set neighbors to 1 if the node is found

        if (root->left != NULL)
            printf("%d ", root->left->data); // Print left child

        if (root->right != NULL)
            printf("%d ", root->right->data); // Print right child

        return; // Return if the node is found
    }

    // Recursively call for left and right subtrees
    printNeighbors(root->left, data, &(*neighbors));
    printNeighbors(root->right, data, &(*neighbors));

    if (*neighbors == 1)
    {
        printf("%d ", root->data); // Print the node if the node is found
        *neighbors = 0;            // Set neighbors to 0 if the node is found
    }
}