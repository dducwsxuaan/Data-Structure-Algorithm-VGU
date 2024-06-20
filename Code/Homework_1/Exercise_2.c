#include<stdio.h>
#include<stdlib.h>
/**
 * Function: input_array
 * ---------------------
 * Reads the size and elements of an array from the user.
 *
 * @param x: Pointer to the array.
 * @param n: Pointer to the size of the array.
 *
 * @return: void
 */
void input_array(int* x, int *n){
    printf("Enter the size: ");
    scanf("%d", n);
    for (int i = 0; i < *n; i++){
        printf("Enter elements of the array: ");
        scanf("%d", (x+i));
    }
}

/**
 * Function: sum_array
 * -------------------
 * Computes the sum of all elements in an array.
 *
 * @param x: Pointer to the array.
 * @param n: Pointer to the size of the array.
 *
 * @return: The sum of all elements in the array.
 */
int sum_array(int* x, int *n){
    int sum = 0;
    for (int i = 0; i < *n; i++){
        sum += *(x+i);
    }
    return sum;
}

/**
 * Function: print_array
 * ---------------------
 * Prints the elements of an array to the console.
 *
 * @param x: Pointer to the array.
 * @param n: Pointer to the size of the array.
 *
 * @return: void
 */
void print_array(int* x, int *n){
    printf("The array: ");
    // for (int i = 0; i < n; i++){
    //     printf("%d ", *(x+i));
    // }
    int i = 0;
    while (i < *n){
        printf("%d ", x[i]);
        i++;
    }
    return;
}

void Swap(int* x, int* y){
    int temp = *x;
    *x = *y;
    *y = temp;
}

/**
 * Function: sort_ascending
 * ------------------------
 * Sorts an array in ascending order using the bubble sort algorithm.
 *
 * @param x: Pointer to the array.
 * @param n: Pointer to the size of the array.
 *
 * @return: void
 */
void sort_ascending(int* x, int *n){
    for (int i = 0; i < (*n)-1; i++){
       for (int j = i+1; j < (*n); j++){
            if (*(x+i) > *(x+j)){
                Swap(x+i, x+j);
            }
       } 
    }
}

/**
 * Function: maxsubarray
 * ---------------------
 * Computes the sum of the maximum subarray in an array.
 *
 * @param Array: Pointer to the array.
 * @param n: Pointer to the size of the array.
 *
 * @return: The sum of the maximum subarray.
 */
int maxsubarray(int *Array, int *n) {
    int max_sum = 0;
    int current_sum = 0;

    for (int i = 0; i < *n; i++) {
        current_sum += Array[i];
        if (current_sum < 0)
            current_sum = 0;
        if (max_sum < current_sum)
            max_sum = current_sum;
    }

    return max_sum;
}

/**
 * Function: minsubarray
 * ---------------------
 * Computes the sum of the minimum subarray in an array.
 *
 * @param Array: Pointer to the array.
 * @param n: Pointer to the size of the array.
 *
 * @return: The sum of the minimum subarray.
 */
int minsubarray(int *Array, int *n) {
    int min_sum = 1000000;
    int current_sum = 0;

    for (int i = 0; i < *n; i++) {
        current_sum += Array[i];
        if (current_sum > 0)
            current_sum = 0;
        if (min_sum > current_sum)
            min_sum = current_sum;
    }

    return min_sum;
}

int main(){
    int* a;
    int N;
    a =  malloc(N * sizeof(int));
    input_array(a, &N);
    //printf("The sum of the array: %d",  sum_array(a, N));
    sort_ascending(a, &N);
    print_array(a, &N);
    // printf("%d\n", maxsubarray(a, N));
    // printf("%d ", minsubarray(a, N));
    free(a);
    return 0;
}