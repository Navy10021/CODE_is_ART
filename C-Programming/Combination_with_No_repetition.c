#include <stdio.h>
#include <stdbool.h>

void generateCombinations(char set[], int n, int k, char current[], int index, bool used[]) {
    if (index == k) {
        for (int i = 0; i < k; i++) {
            printf("%c", current[i]);
        }
        printf("\n");
        return;
    }

    for (int i = 0; i < n; i++) {
        if (!used[i]) {
            used[i] = true;
            current[index] = set[i];
            generateCombinations(set, n, k, current, index + 1, used);
            used[i] = false;
        }
    }
}

int main() {
    char set[] = {'A', 'B', 'C'};
    int n = sizeof(set) / sizeof(set[0]);
    int k = 2; // Length of combinations

    char current[k];
    bool used[n];
    for (int i = 0; i < n; i++) {
        used[i] = false;
    }

    generateCombinations(set, n, k, current, 0, used);

    return 0;
}