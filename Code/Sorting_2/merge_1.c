#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
void Merge(int A[], int TmpArray[], int Lpos, int Rpos, int RightEnd){
    int LeftEnd, NumElements, TmpPos;
    
    LeftEnd = Rpos - 1;
    TmpPos = Lpos;
    NumElements = RightEnd - Lpos + 1;
    
    
    while (Lpos <= LeftEnd && Rpos <= RightEnd){
        if (A[Lpos] <= A[Rpos]){
            TmpArray [TmpPos] = A[Lpos];
            TmpPos++;
            Lpos++;
        }
        else {
            TmpArray[TmpPos] = A[Rpos];
            TmpPos++;
            Rpos++;
        }
    }

    while (Lpos <= LeftEnd){
        TmpArray[TmpPos] = A[Lpos];
        TmpPos++;
        Lpos++;
    }

    while (Rpos <= RightEnd)
    {
        TmpArray[TmpPos] = A[Rpos];
        TmpPos++;
        Rpos++;
    }

    for (int i = 0; i < NumElements; i++, RightEnd--){
        A[RightEnd] = TmpArray[RightEnd];
    }
}
void MSort(int A[], int TmpArray[], int Left, int Right) {
    // Function implementation goes here
    int Center;

    if (Left < Right){
        Center = (Left + Right) / 2;
        MSort(A, TmpArray, Left, Center);
        MSort(A, TmpArray, Center + 1, Right);
        Merge(A, TmpArray, Left, Center + 1, Right);
    }
}

void Mergesort(int A[], int N){
    int *TmpArray;

    TmpArray = malloc (N * sizeof(int));
    if (TmpArray != NULL){
        MSort(A, TmpArray, 0, N-1);
        free (TmpArray);
    }
    else {
        printf("No space for tmp array!!!");
    }
}

void printArray(int A[], int N){
    for (int i = 0; i < N; i++){
        printf("%d ", A[i]);
    }
    printf("\n");
}
int main() {
    int array[] = {3, 1, 4, 1, 5, 9, 2, 6, 5};
    
    // int array[] = {3, 1, 4, 1, 5, 9, 2, 6};
    int size = sizeof(array) / sizeof(int);
    printf("The original array is: ");
    printArray(array, size);
    Mergesort(array, size);
    printf("The sorted array is: ");
    printArray(array, size);
    return 0;
}
