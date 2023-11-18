#include <stdio.h>
#include <string.h>

char* removePositions(char* str, int positions[], int numPositions) {
    int len = strlen(str);
    int i, j, k;

    for (i = 0, j = 0, k = 0; i < len; i++) {
        // If the current position is not to be removed, keep the character
        if (k < numPositions && i == positions[k]) {
            k++;
        } else {
            str[j++] = str[i];
        }
    }

    str[j] = '\0';
    return str;
}

int main() {
    char arr[10];
    int numPositions;
    printf("Enter your string and number of erase: ");
    scanf("%s %d", arr, &numPositions);

    int positions[numPositions];
    printf("Enter the positions to remove (0-based indexing): ");
    for (int i = 0; i < numPositions; i++) {
        scanf("%d ", &positions[i]);
    }

    removePositions(arr, positions, numPositions);

    printf("Modified string: %s\n", arr);

    return 0;
}
