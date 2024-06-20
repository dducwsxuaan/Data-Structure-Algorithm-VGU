#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
    char data;
    struct Node* next;
};
typedef struct Node* Stack;
typedef struct Node* PtrToNode;

void Push(Stack S, char c){
    PtrToNode TmpCell;
    TmpCell = malloc(sizeof(struct Node));
    if (TmpCell == NULL){
        printf("Out of space!!!");
    }
    else {
        TmpCell->data = c;
        TmpCell->next = S->next;
        S->next = TmpCell;
    }
}

int IsEmpty(Stack S){
    return S->next == NULL;
}

char Pop(Stack S){
    PtrToNode FirstCell = malloc(sizeof(struct Node));
    char c;
    if (IsEmpty(S)){
        printf("Empty stack!!!");
    }
    else{
        FirstCell = S->next;
        c = FirstCell->data;
        S->next = S->next->next;
    }
    return c;
}
void symbol(char *str){
    Stack S = malloc(sizeof(struct Node));
    S->next = NULL;
    int check = 0;
    for (int i = 0; i < strlen(str); i++){
        if (str[i] == '[' || str[i] == '{' || str[i] == '('){
            Push(S, str[i]);
        }
        else if (str[i] == ']' || str[i] == '}' || str[i] == ')'){
            if (IsEmpty(S)){
                printf("Not balancing\n");
                return;
            }
            else {
                char c;
                c = Pop(S);
                if ((c == '[' && str[i] == ']') || (c == '{' && str[i] == '}') || (c == '(' && str[i] == ')')){
                    check = 1;
                }
                else {
                    printf("Not balancing\n");
                    return;
                }
            }
        }
    }
    if (IsEmpty(S) && check == 1){
        printf("Symbol balancing\n");
    }
    else{
        printf("Not balancing\n");
    }
}



int main(){
    char str1[] = "[a+b{1*2]9*1}+(2-1)";
    char str2[] = "[a+b{1*2}9*1]+(2-1)";
    char str3[] = "[ { [ ( )] } ]";
    char str4[] = "[{]}()";
    symbol(str1);
    symbol(str2);
    symbol(str3);
    symbol(str4);
    return 0;
}

