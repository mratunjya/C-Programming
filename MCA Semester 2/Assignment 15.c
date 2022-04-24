#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define HORIZONTALTAB 5

struct Node {
    int data;
    int priority;
    struct Node *left;
    struct Node *right;
};

struct Queue {
    int priority;
    int data;
    struct Queue *next;
};

struct Node *root1 = NULL;
struct Node *root2 = NULL;

struct Queue *front = NULL;
struct Queue *rear = NULL;

void insertBST1(int data, int priority);

void insertBST2(int data, int priority);

void inOrder(struct Node *root);

void join(struct Node *root);

void print2DTree(struct Node *root, int tab_space);

int isEmpty();

void printQueue();

int main() {
    int n = 999;
    int choice, data[n], priority_arr[n];

    struct Node *temp = NULL;

    do {
        printf("\n\n1. Insert Random data into BST\n");
        printf("2. Join Both BSTs and Display Priority Queue\n");
        printf("3. Exit\n\n");
        printf("What do you want to do? ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("\nNumber of Nodes to be inserted in BST 1: ");
                scanf("%d", &n);
                printf("\nValues & Priority being inserted in BST 1:\n\n");

                for (int i = 0; i < n; i++) {
                    data[i] = rand() % 100 + 1;
                    priority_arr[i] = rand() % 10 + 1;
                    printf("%d\t", data[i]);
                    printf("%d\n", priority_arr[i]);
                }

                for (int i = 0; i < n; i++)
                    insertBST1(data[i], priority_arr[i]);

                printf("\n\nData Inserted Successfully...");

                printf("\n\nInorder of the BST 1 is(Data, Priority): ");
                inOrder(root1);

                printf("\n\nPrinting 2D Structure of BST 1: \n\n");
                print2DTree(root1, 5);

                printf("\nNumber of Nodes to be inserted in BST 2: ");
                scanf("%d", &n);

                printf("\nValues & Priority being inserted in BST 2:\n\n");
                printf("\nValue\tPriority\n");

                for (int i = 0; i < n; i++) {
                    data[i] = rand() % 100 + 1;
                    priority_arr[i] = rand() % 10 + 1;
                    printf("%d\t", data[i]);
                    printf("%d\n", priority_arr[i]);
                }

                for (int i = 0; i < n; i++)
                    insertBST2(data[i], priority_arr[i]);

                printf("\n\nData Inserted Successfully...");

                printf("\n\nInorder of the BST 2 is(Data, Priority): ");
                inOrder(root2);

                printf("\n\nPrinting 2D Structure of BST 2: \n\n");
                print2DTree(root2, 5);
                break;
            case 2:
                join(root1);
                join(root2);
                printQueue();
                front = NULL;
                rear = NULL;
                root1 = NULL;
                root2 = NULL;
                break;
            case 3:
                printf("\nBye, See you soon!\n");
                break;
        }
    } while (choice != 3);
}

void insertBST1(int data, int priority) {
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    temp->data = data;
    temp->priority = priority;
    temp->left = NULL;
    temp->right = NULL;

    if (root1 == NULL)
        root1 = temp;
    else {
        struct Node *curr = root1;
        struct Node *prev = NULL;
        while (curr != NULL) {
            prev = curr;
            if (temp->data < curr->data)
                curr = curr->left;
            else
                curr = curr->right;
        }
        if (temp->data == prev->data)
            printf("\nOops, It's already there...");
        else if (temp->data < prev->data)
            prev->left = temp;
        else
            prev->right = temp;
    }
}

void insertBST2(int data, int priority) {
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    temp->data = data;
    temp->priority = priority;
    temp->left = NULL;
    temp->right = NULL;

    if (root2 == NULL)
        root2 = temp;
    else
    {
        struct Node *curr = root2;
        struct Node *prev = NULL;
        while (curr != NULL)
        {
            prev = curr;
            if (temp->data < curr->data)
                curr = curr->left;
            else
                curr = curr->right;
        }
        if (temp->data == prev->data)
            printf("\nOops, It's already there...");
        else if (temp->data < prev->data)
            prev->left = temp;
        else
            prev->right = temp;
    }
}

void inOrder(struct Node *root) {
    if (root == NULL)
        return;

    inOrder(root->left);
    printf("(%d, %d) ", root->data, root->priority);
    inOrder(root->right);
}

void join(struct Node *root) {
    if (root == NULL)
        return;

    join(root->left);
    struct Queue *node = (struct Queue *)malloc(sizeof(struct Queue));
    struct Queue *last = front;

    node->data = root->data;
    node->priority = root->priority;
    node->next = NULL;

    if (front == NULL && rear == NULL) {
        node->next = NULL;
        front = node;
        rear = node;
    }
    else {
        while (last->next != NULL) {
            if (last->next->priority < node->priority)
                last = last->next;
            else if (last->next->priority == node->priority) {
                if (last->next->data <= node->data)
                    last = last->next;
                else
                    break;
            }
            else
                break;
        }
        if (last->priority < node->priority) {
            node->next = last->next;
            last->next = node;
            rear = node;
        }
        else if (last->priority == node->priority) {
            if (last->data < node->data)
            {
                node->next = last->next;
                last->next = node;
                rear = node;
            }
            else
                node->next = last;
        }
        else {
            node->next = front;
            front = node;
        }
    }
    while (rear->next != NULL)
        rear = rear->next;

    join(root->right);
}

void print2DTree(struct Node *root, int tab_space) {
    if (root == NULL)
        return;

    tab_space += HORIZONTALTAB;
    print2DTree(root->right, tab_space);
    printf("\n");

    for (int i = HORIZONTALTAB; i < tab_space; i++)
        printf(" ");

    printf("(%d, %d)\n", root->data, root->priority);
    print2DTree(root->left, tab_space);
}

int isEmpty() {
    if (front == NULL && rear == NULL)
        return 1;
    else
        return 0;
}

void printQueue() {
    struct Queue *temp = front;

    if (isEmpty()) {
        printf("\nOops, No data in queue.\n");
        return;
    }
    else {
        printf("\nValue\tPriority\n");
        while (temp != NULL) {
            printf("%d\t%d\n", temp->data, temp->priority);
            temp = temp->next;
        }
    }
}