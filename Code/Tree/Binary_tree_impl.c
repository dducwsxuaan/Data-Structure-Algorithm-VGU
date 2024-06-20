#include <stdio.h>
#include<stdlib.h>
// struct TreeNode {
//     int number;
//     PtrToNode FirstChild;
//     PtrToNode NextSibling;
// };
// typedef struct TreeNode *PtrToNode;

struct BinaryTreeNode {
    int data;
    struct BinaryTreeNode * left;
    struct BinaryTreeNode * right;
};
typedef struct BinaryTreeNode * PtrToNode;

void PreOrder(struct BinaryTreeNode * root){
    if (root){
        printf("%d -> ", root->data);
        PreOrder(root->left);
        PreOrder(root->right);
    }
}

void InOrder(struct BinaryTreeNode * root){
    if (root){
        InOrder(root->left);
        printf("%d -> ", root->data);
        InOrder(root->right);
    }
}

void PostOrder(struct BinaryTreeNode * root){
    if (root){
        PostOrder(root->left);
        PostOrder(root->right);
        printf("%d -> ", root->data);
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
    printf("\n");
    InOrder(root);
    printf("\n");
    PostOrder(root);
    return 0;
}