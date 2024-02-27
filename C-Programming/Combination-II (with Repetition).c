#include <stdio.h>

// Combination with repetition
void generateCombinations(char set[], int n, int k, char current[], int index) {
    if (index == k) {
        for (int i = 0; i < k; i++) {
            printf("%c", current[i]);
        }
        printf("\n");
        return;
    }

    for (int i = 0; i < n; i++) {
        current[index] = set[i];
        generateCombinations(set, n, k, current, index + 1);
    }
}

int main() {
    char set[] = {'A', 'B', 'C'};
    int n = sizeof(set) / sizeof(set[0]);
    int k = 3; // Length of combinations

    char current[k];
    generateCombinations(set, n, k, current, 0);

    return 0;
}
