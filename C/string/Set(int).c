#include <stdio.h>
#include <stdbool.h>

#define MAX_SIZE 10

// Set()에 동일한 원소가 포함되어 있는지 여부 확인.
bool contains(const int set[], int size, int value) {
    for (int i = 0; i < size; i++) {
        if (set[i] == value) {
            return true;
        }
    }
    return false;
}

// Set()에 원소를 추가하는 함수
bool addToSet(int set[], int *size, int value) {
    if (*size < MAX_SIZE && !contains(set, *size, value)) {
        set[*size] = value;
        (*size)++;
        return true; // Added successfully
    }
    return false; // Element not added (either set is full or element already exists)
}

int main() {
    int integerSet[MAX_SIZE];
    int setSize = 0;

    // Example usage of addToSet function
    addToSet(integerSet, &setSize, 1);
    addToSet(integerSet, &setSize, 2);
    addToSet(integerSet, &setSize, 1);
    addToSet(integerSet, &setSize, 2);
    
    // Printing the elements in the set
    printf("Elements in the set:\n");
    for (int i = 0; i < setSize; i++) {
        printf("%d\n", integerSet[i]);
    }

    return 0;
}
