#include <stdio.h>  // Standard input/output definitions
#include <stdlib.h> // Standard library

struct node
{
    char data; // Data
    struct node *left; // Pointer to left node
    struct node *right; // Pointer to right node
};

struct node *create() // create a node
{
    int data; // data
    struct node *new_node; // new node
    new_node = (struct node *)malloc(sizeof(struct node)); // allocate memory

    printf("\nEnter the value or -1 to return to the parent: ");
    scanf("%d", &data); // get the data

    if (data == -1) // if the data is -1
        return NULL; // return if the data is -1

    new_node->data = data; // set the data

    printf("Taking value for the left child of %d node: ", data); // take the value for the left child

    new_node->left = create(); // create the left child

    printf("Taking value for the right child of %d node: ", data); // take the value for the right child

    new_node->right = create(); // create the right child

    return new_node; // Return new_node
}

// Inorder traversal of the tree
void inOrder(struct node *root)
{
    if (root == NULL) // If the root is NULL
        return; // Return

    inOrder(root->left); // Inorder traversal of the left child
    printf("%c ", root->data); // Print the data
    inOrder(root->right); // Inorder traversal of the right child
}

// Preorder traversal of the tree
void preOrder(struct node *root)
{
    if (root == NULL) // If the root is NULL
        return; // Return

    printf("%c ", root->data); // Print the data
    preOrder(root->left); // Preorder traversal of the left child
    preOrder(root->right); // Preorder traversal of the right child
}

// Postorder traversal of the tree
void postOrder(struct node *root)
{
    if (root == NULL) // If the root is NULL
        return; // Return

    postOrder(root->left); // Postorder traversal of the left child
    postOrder(root->right); // Postorder traversal of the right child
    printf("%c ", root->data); // Print the data
}

int main()
{
    struct node *root = NULL; // root

    if (root == NULL)
    {
        struct node *temp = (struct node *)malloc(sizeof(struct node)); // allocate memory
        temp->data = 'F'; // set the data
        root = temp;
    }

    struct node *temp1 = (struct node *)malloc(sizeof(struct node)); // allocate memory
    temp1->data = 'B'; // set the data
    root->left = temp1; // set the left child

    struct node *temp2 = (struct node *)malloc(sizeof(struct node)); // allocate memory
    temp2->data = 'G'; // set the data
    root->right = temp2; // set the right

    struct node *temp3 = (struct node *)malloc(sizeof(struct node)); // allocate memory
    temp3->data = 'A'; // set the data
    root->left->left = temp3; // set the left child

    struct node *temp4 = (struct node *)malloc(sizeof(struct node)); // allocate memory
    temp4->data = 'D'; // set the data
    root->left->right = temp4; // set the right child

    struct node *temp5 = (struct node *)malloc(sizeof(struct node)); // allocate memory
    temp5->data = 'C'; // set the data
    root->left->right->left = temp5; // set the left child

    struct node *temp6 = (struct node *)malloc(sizeof(struct node)); // allocate memory
    temp6->data = 'E';
    root->left->right->right = temp6;

    struct node *temp7 = (struct node *)malloc(sizeof(struct node)); // allocate memory
    temp7->data = 'I'; // set the data
    root->right->right = temp7; // set the right child

    struct node *temp8 = (struct node *)malloc(sizeof(struct node)); // allocate memory
    temp8->data = 'H'; // set the data
    root->right->right->left = temp8; // set the left child

    int choice; // choice

    do
    {
        printf("\n\n1. Show InOrder\n2. Show PreOrder\n3. Show PreOrder\n4. Exit\n\n"); // show the choices
        printf("Enter your choice: "); // enter the choice
        scanf("%d", &choice); // get the choice

        switch (choice) // switch the choice
        {
        case 1:
            printf("\nInOrder: "); // print the InOrder
            inOrder(root); // Inorder traversal of the tree
            break;
        case 2:
            printf("\nPreOrder: "); // print the PreOrder
            preOrder(root); // Preorder traversal of the tree
            break;
        case 3:
            printf("\nPostOrder: "); // print the PostOrder
            postOrder(root); // Postorder traversal of the tree
            break;
        case 4:
            printf("\nExiting...\n"); // Exit
            break;
        default:
            printf("\nInvalid choice\n"); // Invalid choice
            break;
        }
    } while (choice != 4);

    return 0; // Return
}
