#include<stdio.h>
void Swap(int* x, int* y){
    int temp = *x;
    *x = *y;
    *y = temp;
}

int main(){
    int a = 10;
    int b = 9;
    Swap(&a, &b);
    printf("Now a is: %d\n", a);
    printf("Now b is: %d", b);
    return 0;
}