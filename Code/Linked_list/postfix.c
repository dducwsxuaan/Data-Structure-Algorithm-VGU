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
    TmpCell = (struct Node*)malloc(sizeof(struct Node));
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
    PtrToNode FirstCell = (struct Node*)malloc(sizeof(struct Node));
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

int prec(char c){
    if (c == '^') return 3;
    else if (c == '*' || c == '/') return 2;
    else if (c == '+' || c == '-') return 1;
    return -1;
}

char associativity(char c){
    if (c == '^') return 'r';
    return 'l';
}
void infixToPostfix(char* str, char* postfix){
    Stack S = (struct Node*)malloc(sizeof(struct Node));
    S->next = NULL;
    int k = 0;
    for (int i = 0; i < strlen(str); i++){
        char c = str[i];
        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9')){
            postfix[k] = c;
            k++;
        }
        else if (c == '('){
            Push(S, c);
        }
        else if (c == ')'){
            while (!IsEmpty(S) && S->next->data != '('){
                postfix[k] = Pop(S);
                k++;
            }
            if (!IsEmpty(S) && S->next->data == '('){
                Pop(S);
            }
        }
        else {
            while (!IsEmpty(S) && (prec(c) < prec(S->next->data) || (prec(c) == prec(S->next->data) && associativity(c) == 'l'))){
                postfix[k] = Pop(S);
                k++;
            }
            Push(S, c);
        }
    }
    while (!IsEmpty(S)){
        postfix[k] = Pop(S);
        k++;
    }
    postfix[k] = '\0';
}

int calculate(char* postfix) {
    Stack S = (struct Node*)malloc(sizeof(struct Node));
    S->next = NULL;
    int i = 0;
    while (postfix[i] != '\0') {
        char c = postfix[i];
        if (c >= '0' && c <= '9') {
            Push(S, c);
        } else {
            int operand2 = Pop(S) - '0';
            int operand1 = Pop(S) - '0';
            int result;
            switch (c) {
                case '+':
                    result = operand1 + operand2;
                    break;
                case '-':
                    result = operand1 - operand2;
                    break;
                case '*':
                    result = operand1 * operand2;
                    break;
                case '/':
                    result = operand1 / operand2;
                    break;
                case '^':
                    result = 1;
                    for (int j = 0; j < operand2; j++) {
                        result *= operand1;
                    }
                    break;
            }
            Push(S, result + '0');
        }
        i++;
    }
    int finalResult = Pop(S) - '0';
    return finalResult;
}

int main(){
    char str[] = "5*(6+2)-12/4";
    char postfix[strlen(str)];
    infixToPostfix(str, postfix);
    printf("%s", postfix);
    printf("\n");
    printf("%d", calculate(postfix));
    return 0;
}