#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// is subtext is palindrome..
int isSubtextPalindrome(char** arr, int arrSize){
    int st = 0;
    int en = arrSize - 1;
    while(st < en){
        if (strcmp(arr[st], arr[en]) != 0){
            return 0;
        }
        st++;
        en--;
    }
    return 1;
}

// Split K-parts
void splitStringIntoKParts(const char* str, int k) {
    int len = strlen(str);
    int baseLength = len / k;
    int remainder = len % k;
    char** substrings = malloc(k * sizeof(char*));
    int currentPosition = 0;

    for (int i = 0; i < k; i++) {
        // Calculate length of this substring
        int thisSubstringLength = baseLength + (i < remainder ? 1 : 0);
        substrings[i] = malloc((thisSubstringLength + 1) * sizeof(char)); // +1 for null terminator

        // Copy the substring
        strncpy(substrings[i], str + currentPosition, thisSubstringLength);
        substrings[i][thisSubstringLength] = '\0'; // Null-terminate the substring

        // Print the substring (for demonstration)
        //printf("Substring %d: %s\n", i+1, substrings[i]);
        currentPosition += thisSubstringLength;
    }
    // Check SubText is palindrome 
    if (isSubtextPalindrome(substrings, k)){
        printf("Splitting into %d parts is Palindrome Decomposition\n", k);
        for (int i = 0; i < k; i++){
            printf("Substring %d: %s\n", i+1, substrings[i]);   
        }
    }
    
    // Cleanup
    for (int i = 0; i < k; i++) {
        free(substrings[i]);
    }
    free(substrings);
}

int main() {
    const char* str = "abcxxxabc";
    int len = strlen(str);
    // Ensure k starts from 1 to avoid division by zero
    // and doesn't exceed the length of the string
    for (int k = 1; k <= len; k++){
        splitStringIntoKParts(str, k);
    }
    return 0;
}