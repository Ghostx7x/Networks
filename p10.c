#include <stdio.h>
#include <stdlib.h>

struct BST {
    int data;
    struct BST *left;
    struct BST *right;
};

typedef struct BST NODE;
NODE *node;

NODE* createtree(NODE *node, int data) {
    if (node == NULL) {
        NODE *temp;
        temp = (NODE*)malloc(sizeof(NODE));
        temp->data = data;
        temp->left = temp->right = NULL;
        return temp;
    }

    if (data < (node->data)) {
        node->left = createtree(node->left, data);
    } else if (data > node->data) {
        node -> right = createtree(node->right, data);
    }

    return node;
}

NODE* search(NODE *node, int data) {
    if (node == NULL)
        printf("\nElement not found");
    else if (data < node->data)
        node->left = search(node->left, data);
    else if (data > node->data)
        node->right = search(node->right, data);
    else
        printf("\nElement found is: %d", node->data);
    return node;
}

void inorder(NODE *node) {
    if (node != NULL) {
        inorder(node->left);
        printf("%d\t", node->data);
        inorder(node->right);
    }
}

void preorder(NODE *node) {
    if (node != NULL) {
        printf("%d\t", node->data);
        preorder(node->left);
        preorder(node->right);
    }
}

void postorder(NODE *node) {
    if (node != NULL) {
        postorder(node->left);
        postorder(node->right);
        printf("%d\t", node->data);
    }
}

int main(void) {
    int data, ch, i, n;
    NODE *root = NULL;

    while (1) {
        printf("\n1.Insertion in Binary Search Tree");
        printf("\n2.Search Element in Binary Search Tree");
        printf("\n3.Inorder\n4.Preorder\n5.Postorder\n6.Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                printf("\nEnter N value: ");
                scanf("%d", &n);
                printf("\nEnter the values to create BST like (6,9,5,2,8,15,24,14,7,8,5,2)\n");
                for (i = 0; i < n; i++) {
                    scanf("%d", &data);
                    root = createtree(root, data);
                }
                break;

            case 2:
                printf("\nEnter the element to search: ");
                scanf("%d", &data);
                root = search(root, data);
                break;

            case 3:
                printf("\nInorder Traversal: \n");
                inorder(root);
                break;

            case 4:
                printf("\nPreorder Traversal: \n");
                preorder(root);
                break;

            case 5:
                printf("\nPostorder Traversal: \n");
                postorder(root);
                break;

            case 6:
                exit(0);

            default:
                printf("\nWrong option");
                break;
        }
    }
}







/*
#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *left;
    struct node *right;
};

typedef struct node Node;

Node *insert(Node *root, int value) {
    if (root == NULL) {
        Node *newNode = (Node *)malloc(sizeof(Node));
        newNode->data = value;
        newNode->left = newNode->right = NULL;
        return newNode;
    }

    if (value < root->data) {
        root->left = insert(root->left, value);
    } else if (value > root->data) {
        root->right = insert(root->right, value);
    }

    return root;
}

void inorder(Node *root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

void preorder(Node *root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(Node *root) {
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}

Node *search(Node *root, int key) {
    if (root == NULL || root->data == key) {
        return root;
    }

    if (root->data < key) {
        return search(root->right, key);
    }

    return search(root->left, key);
}

void menu() {
    printf("\nMenu:\n");
    printf("1. Insert element into BST\n");
    printf("2. Traverse BST (Inorder, Preorder, Postorder)\n");
    printf("3. Search element in BST\n");
    printf("4. Exit\n");
}

int main(void) {
    Node *root = NULL;
    int choice, key;

    while (1) {
        menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the element to insert: ");
                scanf("%d", &key);
                root = insert(root, key);
                break;
            case 2:
                printf("\nInorder traversal: ");
                inorder(root);
                printf("\nPreorder traversal: ");
                preorder(root);
                printf("\nPostorder traversal: ");
                postorder(root);
                printf("\n");
                break;
            case 3:
                printf("Enter the element to search: ");
                scanf("%d", &key);
                if (search(root, key) != NULL) {
                    printf("Element %d found in BST.\n", key);
                } else {
                    printf("Element %d not found in BST.\n", key);
                }
                break;
            case 4:
                printf("Exiting the program...\n");
                exit(0);
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    }
}
*/