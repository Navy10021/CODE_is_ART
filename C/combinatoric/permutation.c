#include <stdio.h>
#include <string.h>

// Function to swap characters at position i and j in a string
void swap(char* str, int i, int j) {
    char temp = str[i];
    str[i] = str[j];
    str[j] = temp;
}

// Recursive function to generate all permutations of a string
void permute(char* str, int start, int end) {
    if (start == end) {
        printf("%s\n", str); // Print the current permutation
    } else {
        for (int i = start; i <= end; i++) {
            // Swap characters at positions start and i
			swap(str, start, i);
			// Recursively generate permutations for the remaining characters
            permute(str, start + 1, end);
			// Backtrack by restoring the original order 
            swap(str, start, i);      
        }
    }
}

int main() {
    char input[100];
    printf("Enter a string: ");
    scanf("%s", input);

    int length = strlen(input);

    permute(input, 0, length - 1);

    return 0;
}
