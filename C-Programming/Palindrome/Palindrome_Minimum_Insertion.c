#include <stdio.h>
#include <string.h>
#include <limits.h>  // for INT_MAX

// Minimum Insertion to Form a Palindrome.
int min(int a, int b){
    return a < b ? a : b;
}

// case 1 : Insert character at the beginning to match the last character 
// case 2 : Insert character at the end to match the first character
int findMinInsertion(char str[], int l, int r){
    // Base cases
    if (l > r){
        return INT_MAX;
    }
    if (l == r){
        return 0;   // a single character is already Palindrome
    }
    if (str[l] == str[r]){ // move towards the center
        return findMinInsertion(str, l + 1, r - 1);
    }
    // Find minimum insertions consider two conditions and +1 (insertions)
    return (min(findMinInsertion(str, l, r - 1), findMinInsertion(str, l + 1, r)) + 1);
}

int main(){
    char input[100];
    scanf("%s", input);
    printf("Minimum Insertions needed to make it palindrome : %d", findMinInsertion(input, 0, strlen(input) - 1));
    
    return 0;
}