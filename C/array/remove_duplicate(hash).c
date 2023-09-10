#include <stdio.h>

void remove_dupicate(int* arr, int size){
    if (size <= 1) return;
    // 1. find max
    int max = -1;
    for (int i=0; i < size; i++){
        if (max < arr[i])
            max = arr[i];
    }

    // 2. hash table
    int hash[max + 1]; // Changed max to max + 1
    for (int i = 0; i <= max; i++) {
        hash[i] = 0; // Initialize all elements of the hash table to 0
    }

    // 3. insert element in hash table
    for (int i=0; i<size; i++){
        hash[arr[i]]++;
    }
    // 4. Traversal hash table(also sorted array element)
    for (int i=0; i<=max; i++){
        if (hash[i] != 0)
            printf("%d ", i);
    }
}

int main(){
    int input[] = {3,9,2,8,5,9,2,8};
    int length = sizeof(input) / sizeof(input[0]);

    remove_dupicate(input, length);
    return 0;
}
