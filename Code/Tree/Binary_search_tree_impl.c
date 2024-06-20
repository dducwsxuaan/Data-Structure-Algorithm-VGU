#include <stdio.h>
#include <stdlib.h>
struct BinaryTreeNode {
    int data;
    struct BinaryTreeNode * left;
    struct BinaryTreeNode * right;
};
typedef struct BinaryTreeNode * PtrToNode;

//31, 45, 36, 14, 52, 42, 6, 21, 73, 47, 26, 37, 33, 8
PtrToNode InsertNode(PtrToNode root, int data) {
    if (root == NULL) {
        // Create a new node
        PtrToNode newNode = (PtrToNode)malloc(sizeof(struct BinaryTreeNode));
        newNode->data = data;
        newNode->left = NULL;
        newNode->right = NULL;
        return newNode;
    } 
    else {
        // Recursively insert the node in the left or right subtree
        if (data < root->data) {
            root->left = InsertNode(root->left, data);
        } else {
            root->right = InsertNode(root->right, data);
        }
        return root;
    }
}

// print the tree in-order
void displayTree(PtrToNode root) {
    if (root) {
        displayTree(root->left);
        printf("%d -> ", root->data);
        displayTree(root->right);
    }
}

void search(PtrToNode root, int data) {
    if (root == NULL) {
        printf("Not found\n");
    } else if (root->data == data) {
        printf("Found\n");
    } else if (data < root->data) {
        search(root->left, data);
    } else {
        search(root->right, data);
    }
}

struct Node* deleteNode(PtrToNode root, int k) {
    // Base case
    if (root == NULL)
        return root;

    // If the key to be deleted is smaller than the root's key, then it lies in the left subtree
    if (k < root->data) {
        root->left = deleteNode(root->left, k);
        return root;
    }
    // If the data to be deleted is greater than the root's data, then it lies in the right subtree
    else if (k > root->data) {
        root->right = deleteNode(root->right, k);
        return root;
    }

    // If data is same as root's data, then this is the node to be deleted
    // Node with only one child or no child
    if (root->left == NULL) {
        struct Node* temp = root->right;
        free(root);
        return temp;
    }
    else if (root->right == NULL) {
        struct Node* temp = root->left;
        free(root);
        return temp;
    }

    // Node with two children: Get the inorder successor (smallest in the right subtree)
    PtrToNode succParent = root;
    PtrToNode succ = root->right;
    while (succ->left != NULL) {
        succParent = succ;
        succ = succ->left;
    }

    // Copy the inorder successor's content to this node
    root->data = succ->data;

    // Delete the inorder successor
    if (succParent->left == succ)
        succParent->left = succ->right;
    else
        succParent->right = succ->right;

    free(succ);
    return root;
}

int main(){
    PtrToNode root = NULL;
    int array[14] = {31, 45, 36, 14, 52, 42, 6, 21, 73, 47, 26, 37, 33, 8};
    for (int i = 0; i < 14; i++) {
        root = InsertNode(root, array[i]);
    }
    search(root, 100);
    displayTree(root);
    printf("\n");
    deleteNode(root, 14);
    displayTree(root);
    return 0;
}

