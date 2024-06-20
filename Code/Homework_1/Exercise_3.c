#include<stdio.h>
#include<stdlib.h>

/**
 * Function: inputArray2D
 * ----------------------
 * Reads the dimensions and elements of a 2D array from the user.
 *
 * @param rows: Pointer to the number of rows in the array.
 * @param columns: Pointer to the number of columns in the array.
 * @param array: Pointer to the 2D array.
 *
 * @return: void
 */
void inputArray2D(int *rows, int *columns, int **array){
    printf("Enter number of rows: ");
    scanf("%d", rows);
    printf("Enter number of columns: ");
    scanf("%d", columns);
    for (int i = 0; i < *rows; i++){
        for (int j = 0; j < *columns; j++){
            printf("Input value for cell (%d, %d): ", i, j);
            scanf("%d", &array[i][j]);
        }
    }
}


/**
 * Function: printArray2D
 * ----------------------
 * Prints the elements of a 2D array to the console.
 *
 * @param arr: Pointer to the 2D array.
 * @param rows: Pointer to the number of rows in the array.
 * @param columns: Pointer to the number of columns in the array.
 *
 * @return: void
 */
void printArray2D(int **arr, int *rows, int *columns) {
    printf("The array: \n");
    for (int i = 0; i < *rows; i++) {
        for (int j = 0; j < *columns; j++) {
            printf("%d ", *(*(arr + i) + j)); // Access element using correct pointer arithmetic
        }
        printf("\n");  // Newline for each row
    }
}


/**
 * Function: sumArray2D
 * --------------------
 * Computes the sum of all elements in a 2D array.
 *
 * @param rows: Pointer to the number of rows in the array.
 * @param columns: Pointer to the number of columns in the array.
 * @param arr: Pointer to the 2D array.
 *
 * @return: The sum of all elements in the array.
 */
int sumArray2D(int *rows, int *columns, int **arr){
    int sum = 0;
    for (int i = 0; i < *rows; i++) {
        for (int j = 0; j < *columns; j++) {
            sum += arr[i][j];
        }
    }
    return sum;

}

/**
 * Function: transposeArray2D
 * ---------------------------
 * Prints the transpose of a 2D array to the console.
 *
 * @param rows: Pointer to the number of rows in the original array.
 * @param columns: Pointer to the number of columns in the original array.
 * @param arr: Pointer to the 2D array.
 *
 * @return: void
 */

void transposeArray2D(int *rows, int *columns, int **arr){

    printf("The transpose of the array: \n");
    for (int i = 0; i < *columns; i++) {
        for (int j = 0; j < *rows; j++) {
            printf("%d ", arr[j][i]);
        }
        printf("\n");
    }
}

int main(){
    int m, n;
    int **arr = (int**)malloc(m * n * sizeof(int));
    inputArray2D(&m, &n, arr);
    printArray2D(arr, &m, &n);
    printf("Sum of the array: %d\n", sumArray2D(&m, &n, arr));
    transposeArray2D(&m, &n, arr);
    free(arr);
    return 0;
}