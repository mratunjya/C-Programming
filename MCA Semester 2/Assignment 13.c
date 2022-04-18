#include <stdio.h>
#include <stdlib.h>

struct NODE
{
    int data;
    struct NODE *left;
    struct NODE *right;
};

struct NODE *root = NULL;

void Insert(int newData)
{
    // Insert newData as a node in Binary Search Tree
    struct NODE *newNode = (struct NODE *)malloc(sizeof(struct NODE));
    newNode->data = newData;
    newNode->left = NULL;
    newNode->right = NULL;

    if (root == NULL)
    {
        root = newNode;
    }
    else
    {
        struct NODE *current = root;
        struct NODE *parent;
        while (1)
        {
            parent = current;
            if (newData < current->data)
            {
                current = current->left;
                if (current == NULL)
                {
                    parent->left = newNode;
                    return;
                }
            }
            else
            {
                current = current->right;
                if (current == NULL)
                {
                    parent->right = newNode;
                    return;
                }
            }
        }
    }
}

void Delete(int deleteNode)
{
    // Delete the deleteNode from the Binary Search Tree
    struct NODE *current = root;
    struct NODE *parent = root;
    int isLeft = 1;
    while (current->data != deleteNode)
    {
        parent = current;
        if (deleteNode < current->data)
        {
            isLeft = 1;
            current = current->left;
        }
        else
        {
            isLeft = 0;
            current = current->right;
        }
        if (current == NULL)
        {
            return;
        }
    }
    if (current->left == NULL && current->right == NULL)
    {
        if (current == root)
        {
            root = NULL;
        }
        else if (isLeft)
        {
            parent->left = NULL;
        }
        else
        {
            parent->right = NULL;
        }
    }
    else if (current->right == NULL)
    {
        if (current == root)
        {
            root = current->left;
        }
        else if (isLeft)
        {
            parent->left = current->left;
        }
        else
        {
            parent->right = current->left;
        }
    }
    else if (current->left == NULL)
    {
        if (current == root)
        {
            root = current->right;
        }
        else if (isLeft)
        {
            parent->left = current->right;
        }
        else
        {
            parent->right = current->right;
        }
    }
    else
    {
        struct NODE *successor = current->right;
        struct NODE *successorParent = current;
        while (successor->left != NULL)
        {
            successorParent = successor;
            successor = successor->left;
        }
        successorParent->left = successor->right;
        successor->left = current->left;
        successor->right = current->right;
        if (current == root)
        {
            root = successor;
        }
        else if (isLeft)
        {
            parent->left = successor;
        }
        else
        {
            parent->right = successor;
        }
    }
}

int GetMin()
{
    // Get the minimum value in the Binary Search Tree
    struct NODE *current = root;
    while (current->left != NULL)
    {
        current = current->left;
    }
    return current->data;
}

int GetMax()
{
    // Get the maximum value in the Binary Search Tree
    struct NODE *current = root;
    while (current->right != NULL)
    {
        current = current->right;
    }
    return current->data;
}

int Search(int searchData)
{
    // Search for searchData in the tree
    struct NODE *current = root;
    while (current->data != searchData)
    {
        if (searchData < current->data)
        {
            current = current->left;
        }
        else
        {
            current = current->right;
        }
        if (current == NULL)
        {
            return 0;
        }
    }
    return 1;
}

void Print()
{
    struct NODE *current = root;
    if (current == NULL)
    {
        printf("Tree is empty\n");
    }
    else
    {
        // Maximum data in the tree
        int max = GetMax();
        // Minimum data in the tree
        int min = GetMin();
        printf("\nInorder: ");
        // Print the Binary Search Tree in an inorder fashion
        for (int i = min; i <= max; i++)
        {
            if (Search(i))
            {
                printf("%d ", i);
            }
        }
        printf("\n");
        printf("Max Node: %d\n", max); // Print the maximum data
        printf("Min Node: %d\n", min); // Print the minimum data
        printf("\n\n");
    }
}

int main()
{
    int choice, totalNums, dltData, searchData, xdata;
    while (1)
    {
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. GetMin\n");
        printf("4. GetMax\n");
        printf("5. Search\n");
        printf("6. Print\n");
        printf("7. X Node\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter the number of nodes: ");
            scanf("%d", &totalNums);
            for (int i = 0; i < totalNums; i++)
            {
                Insert(rand() % 100);
            }
            printf("\n%d Random element between 1 and 100 is inserted\n", totalNums);
            break;
        case 2:
            printf("Enter the data: ");
            scanf("%d", &dltData);
            Delete(dltData);
            printf("%d is deleted\n", dltData);
            break;
        case 3:
            printf("Min Node: %d\n\n", GetMin());
            break;
        case 4:
            printf("Max Node: %d\n\n", GetMax());
            break;
        case 5:
            printf("Enter the data: ");
            scanf("%d", &searchData);
            if (Search(searchData))
            {
                printf("%d is present in the tree\n\n", searchData);
            }
            else
            {
                printf("%d is not present in the tree\n\n", searchData);
            }
            break;
        case 6:
            Print();
            break;
        case 7:
            printf("Enter data for X Node: ");
            scanf("%d", &xdata);
            if (Search(searchData))
            {
                Delete(xdata);
                printf("%d is deleted\n", xdata);
            }
            else
            {
                Insert(xdata);
                printf("%d is inserted\n", xdata);
            }
            Print();
            break;
        case 8:
            printf("\nGood Bye, See You Again\n");
            exit(0);
        default:
            printf("Hey Man, you have entered an invalid choice, you can retry\n");
        }
    }
    return 0;
}