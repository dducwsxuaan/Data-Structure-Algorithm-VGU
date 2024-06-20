#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node{
    int coef;
    int exp;
    struct Node* next;
};

typedef struct Node* PtrToNode;
struct Node* createNode(int coef, int exp){
    struct Node* new_node = (struct Node*) malloc (sizeof(struct Node));
    new_node->coef = coef;
    new_node->exp = exp;
    new_node->next = NULL;
    return new_node;
}
void insert(PtrToNode *poly, int coef, int exp){
    PtrToNode new_node = createNode(coef, exp);
    if (*poly == NULL){
        *poly = new_node;
    }
    else{
        PtrToNode temp = *poly;
        while (temp->next != NULL){
            temp = temp->next;
        }
        temp->next = new_node;
    }
}

void print(PtrToNode poly){
    PtrToNode temp = poly;
    while (temp != NULL){
        printf("%dx^%d", temp->coef, temp->exp);
        temp = temp->next;
        if (temp != NULL){
            printf(" + ");
        }
    }
    printf("\n");
}

PtrToNode add(PtrToNode poly1, PtrToNode poly2){
    PtrToNode result = NULL;
    PtrToNode temp1 = poly1;
    PtrToNode temp2 = poly2;
    while (temp1 != NULL && temp2 != NULL){
        if (temp1->exp == temp2->exp){
            insert(&result, temp1->coef + temp2->coef, temp1->exp);
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
        else if (temp1->exp > temp2->exp){
            insert(&result, temp1->coef, temp1->exp);
            temp1 = temp1->next;
        }
        else {
            insert(&result, temp2->coef, temp2->exp);
            temp2 = temp2->next;
        }
    }

    while (temp1 != NULL){
        insert(&result, temp1->coef, temp1->exp);
        temp1 = temp1->next;
    }

    while (temp2 != NULL){
        insert(&result, temp2->coef, temp2->exp);
        temp2 = temp2->next;
    }

    return result;
}


// 
int main(){    
    PtrToNode poly1 = NULL;
    
    PtrToNode poly2 = NULL;

       
    insert(&poly1, 5, 2);
    insert(&poly1, 4, 1);
    insert(&poly1, 2, 0);

    insert(&poly2, 5, 1);
    insert(&poly2, 5, 0);

    print(poly1);
    print(poly2);

    PtrToNode result =  NULL;
    result = add(poly1, poly2);
    print(result);

    
    return 0;
}

