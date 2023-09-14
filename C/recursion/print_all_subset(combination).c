#include <stdio.h>
/*Combination과 동일한 개념*/
void printSubsets(char set[], int n, char subset[], int subSize, int index) {
    if (index == n) {
        printf("Subset: { ");
        for (int i = 0; i < subSize; i++) {
            printf("%c ", subset[i]);
        }
        printf("}\n");
        return;
    }
    subset[subSize] = set[index];
    printSubsets(set, n, subset, subSize + 1, index + 1);
    printSubsets(set, n, subset, subSize, index + 1);
}

int main() {
    char set[] = {'A', 'B', 'C'};
    int size = sizeof(set) / sizeof(set[0]);
    char subset[size];

    printSubsets(set, size, subset, 0, 0);

    return 0;
}
