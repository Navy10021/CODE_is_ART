#include <stdio.h>
#include <string.h>

void reverseStringRecursive(char* str, int start, int end) {
    if (start >= end) {
        return; // Base case: when the start index is greater than or equal to the end index
    }

    // Swap characters at start and end positions
    char temp = str[start];
    str[start] = str[end];
    str[end] = temp;

    // Recursively call the function with updated start and end indices
    reverseStringRecursive(*str, start + 1, end - 1);
}

int main() {
    char str[100]; // Assuming a maximum string length of 100 characters

    printf("Enter a string: ");
    scanf("%s", str);

    int length = strlen(str);

    // Call the recursive function to reverse the string
    reverseStringRecursive(str, 0, length - 1);

    printf("Reversed string: %s\n", str);

    return 0;
}
