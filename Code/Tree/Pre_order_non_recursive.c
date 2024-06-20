#include <stdio.h>
#include <stdlib.h>
struct BinaryTreeNode {
    int data;
    struct BinaryTreeNode * left;
    struct BinaryTreeNode * right;
};
typedef struct BinaryTreeNode * PtrToNode;
typedef struct BinaryTreeNode * Stack;

void PreOrder(struct BinaryTreeNode * root){
    Stack S = malloc(sizeof(struct BinaryTreeNode));
    S->right = NULL;
    S->left = NULL;
    S->data = 0;
    PtrToNode TmpCell;
    TmpCell = malloc(sizeof(struct BinaryTreeNode));
    TmpCell = root;
    while (TmpCell != NULL || S->data != 0){
        while (TmpCell != NULL){
            printf("%d -> ", TmpCell->data);
            S->data++;
            S->left = TmpCell;
            S = S->left;
            TmpCell = TmpCell->left;
        }
        if (S->data != 0){
            TmpCell = S->right;
            S = S->right;
            S->data--;
        }
    }
}

int main(){
    PtrToNode root = (PtrToNode)malloc(sizeof(struct BinaryTreeNode));
    root->data = 1;
    root->left = (PtrToNode)malloc(sizeof(struct BinaryTreeNode));
    root->left->data = 2;
    root->left->left = NULL;
    root->left->right = NULL;
    root->right = (PtrToNode)malloc(sizeof(struct BinaryTreeNode));
    root->right->data = 3;
    root->right->left = NULL;
    root->right->right = NULL;
    PreOrder(root);
    return 0;
}