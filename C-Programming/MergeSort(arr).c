#include <stdio.h>
#include <string.h>

void merge(char arr[][100], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    // Temp arrays
    char L[n1][100], R[n2][100];

    // Copy data to temp arrays
    for (int i = 0; i < n1; i++) {
        strcpy(L[i], arr[left + i]);
    }
    for (int j = 0; j < n2; j++) {
        strcpy(R[j], arr[mid + 1 + j]);
    }

    // Merge Temp arrays back into arr[left ... right]
    int i = 0;
    int j = 0;
    int k = left;

    while (i < n1 && j < n2) {
        if (strcmp(L[i], R[j]) <= 0) {  // Change the condition to >= for descending order
            strcpy(arr[k], L[i]);
            i++;
        } else {
            strcpy(arr[k], R[j]);
            j++;
        }
        k++;
    }

    // Copy the remaining elements of L[] and R[]
    while (i < n1) {
        strcpy(arr[k], L[i]);
        i++;
        k++;
    }
    while (j < n2) {
        strcpy(arr[k], R[j]);
        j++;
        k++;
    }
}

void mergeSort(char arr[][100], int left, int right) {
    if (left < right) {
        // Same as (left + right) / 2, but avoid overflow for large left
        int mid = left + (right - left) / 2;

        // Sort first and second Halves
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        // Merge the sorted halves
        merge(arr, left, mid, right);
    }
}

int main() {
    char arr[][100] = {"apple", "orange", "banana", "grape", "kiwi", "pear"};
    int arr_size = sizeof(arr) / sizeof(arr[0]);

    printf("Given array is \n");
    for (int i = 0; i < arr_size; i++)
        printf("%s ", arr[i]);
    printf("\n");

    // Perform merge sort
    mergeSort(arr, 0, arr_size - 1);

    printf("Sorted array in Ascending order is \n");
    for (int i = 0; i < arr_size; i++)
        printf("%s ", arr[i]);
    printf("\n");

    return 0;
}