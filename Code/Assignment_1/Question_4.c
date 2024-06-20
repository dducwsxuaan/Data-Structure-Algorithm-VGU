#include <stdio.h>
#include <stdbool.h>

#define MAX_SIZE 100

int findMaxOccurrence(int arr[], int N) {
    // Create a hash table to store the count of each number
    int count[MAX_SIZE] = {0};

    // Traverse the array and update the count in the hash table
    for (int i = 0; i < N; i++) {
        count[arr[i]]++;
    }

    // Find the number with the maximum occurrence
    int maxOccurrence = 0;
    int maxNumber = 0;
    for (int i = 0; i < MAX_SIZE; i++) {
        if (count[i] > maxOccurrence) {
            maxOccurrence = count[i];
            maxNumber = i;
        }
    }

    return maxNumber;
}

int main() {
    int arr[] = {1, 2, 4, 18, 2, 10, 3, 18, 2};
    int size = sizeof(arr) / sizeof(arr[0]);

    int maxNumber = findMaxOccurrence(arr, size);

    printf("The number that appeared the maximum number of times is: %d\n", maxNumber);

    return 0;
}