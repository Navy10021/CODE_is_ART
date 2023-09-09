#include <stdio.h>
#include <string.h>

// Function to swap characters at two positions in a string
void swap(char* x, char* y) {
    char temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

// Function to generate all permutations of a string recursively
void generatePermutations(char* str, int start, int end) {
    if (start == end) {
        printf("%s\n", str); // Print the permutation
    } else {
        for (int i = start; i <= end; i++) {
            // Swap the current character with the character at the start position
            swap(&str[start], &str[i]);
            
            // Recursively generate permutations for the rest of the string
            generatePermutations(str, start + 1, end);
            
            // Restore the original order (backtracking)
            swap(&str[start], &str[i]);
        }
    }
}

int main() {
    char str[100]; // Assuming a maximum string length of 100 characters

    printf("Enter a string: ");
    scanf("%s", str);

    int length = strlen(str);

    printf("Permutations of '%s':\n", str);
    generatePermutations(str, 0, length - 1);

    return 0;
}
