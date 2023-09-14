#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// Function to find the maximum value in an array
int findMax(int arr[], int size) {
    int max = INT_MIN;
    for (int i = 0; i < size; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

// Function to find the minimum value in an array
int findMin(int arr[], int size) {
    int min = INT_MAX;
    for (int i = 0; i < size; i++) {
        if (arr[i] < min) {
            min = arr[i];
        }
    }
    return min;
}

// Function to find the mode(s) in an array, including negative values
void findModes(int arr[], int size) {
    int max = findMax(arr, size);
    int min = findMin(arr, size);
    
    // Create a hash table
    int hashSize = max - min + 1;
    int* hash = (int*)malloc(hashSize * sizeof(int));
    
    for (int i = 0; i < hashSize; i++) {
        hash[i] = 0;
    }

    // Populate the hash table
    for (int i = 0; i < size; i++) {
        hash[arr[i] - min]++;       // 해시태이블 인덱스 : array[i] - MIN
    }

    // Find the maximum frequency : 가장 많은 빈도수를 찾고!
    int maxFreq = 0;
    for (int i = 0; i < hashSize; i++) {
        if (hash[i] > maxFreq) {
            maxFreq = hash[i];
        }
    }

    // Print the mode(s) : 최대 빈도수를 가진 숫자를 출력
    printf("The mode(s) is/are: ");
    for (int i = 0; i < hashSize; i++) {
        if (hash[i] == maxFreq) {
            printf("%d ", i + min);
        }
    }
    printf("\n");

    free(hash); // Free dynamically allocated memory
}

int main() {
    int arr[] = {1, 1, 2, 2, 2, 3, 3, 3, 4, 4, 5, -1, -1, -2, -3, -3, -3};
    int size = sizeof(arr) / sizeof(arr[0]);

    findModes(arr, size);

    return 0;
}
