#include<stdio.h>

void Insertion_Sort(int arr[], int size){
    for (int i = 1; i < size; i++){
        int temp = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > temp){
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = temp;
    }
}
int main(){
    int arr[9] = {3, 1, 4, 1, 5, 9, 2, 6, 5};
    int size = sizeof(arr) / sizeof(int);
    Insertion_Sort(arr, size);
    for (int i = 0; i < size; i++){
        printf("%d ", arr[i]);
    }
    return 0;
}