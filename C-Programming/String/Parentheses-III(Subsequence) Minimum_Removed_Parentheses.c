#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Minimum Remove To Make Valid Parentheses
// Find the Longest Subseqence in Parentheses
int isValid(char *s) {
    int len = strlen(s);
    char stack[len];
    int top = -1;

    for (int i = 0; i < len; i++) {
        if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
            stack[++top] = s[i];
        } 
        
        else if (isalpha(s[i]) || isalnum(s[i])){
            continue;
        }
        
        else {
            if (top == -1) {
                return 0;  // No matching open bracket
            }

            if ((s[i] == ')' && stack[top] != '(') ||
                (s[i] == ']' && stack[top] != '[') ||
                (s[i] == '}' && stack[top] != '{')) {
                return 0;  // Mismatched closing bracket
            }
            top--;
        }
    }
    return (top == -1);  // Check if all open brackets are closed
}

// Function to check if a subsequence is already seen
int seen(char **arr, int arr_idx, char *target) {
    for (int i = 0; i < arr_idx; i++) {
        if (strcmp(arr[i], target) == 0) {
            return 1;
        }
    }
    return 0;
}

// Backtrack to generate subsequences
void backtrack(char *str, int index, char *subseq, int subseq_idx, char **subseqs, int *subseqs_idx) {
    //if (str[index] == '\0' && strlen(subseq) > 0) {
    if (str[index] == '\0' && strlen(subseq) > 0 && isValid(subseq)) {
        //if (!seen(subseqs, *subseqs_idx, subseq)) {
            subseqs[*subseqs_idx] = strdup(subseq);
            (*subseqs_idx)++;
            return;
        }
    for (int i = index; i <= strlen(str); i++){
        // 1. Include current character
        subseq[subseq_idx] = str[i];
        // 2. Exclude the current character: str[index++]
        backtrack(str, i + 1, subseq, subseq_idx + 1, subseqs, subseqs_idx);
        // 3. pop the last character
        subseq[subseq_idx] = '\0';
    }
}

// Generate and print subsequences
void generateSubseqs(char *str) {
    int len = strlen(str);
    
    // Allocate memory for the subsequence and subsequences array
    char *subseq = (char *)malloc(sizeof(char) * (len + 1));
    int subsequences_size = 1 << len;
    char **subsequences = (char **)malloc(sizeof(char*) * subsequences_size);
    int subsequences_idx = 0;

    // Call the backtrack function to generate subsequences
    backtrack(str, 0, subseq, 0, subsequences, &subsequences_idx);

    // Find minimum removed results
    int maxlen = 0;
    //char* maxValid = NULL;
    for (int i = 0; i < subsequences_idx; i++) {
        if(strlen(subsequences[i]) > maxlen){
            maxlen = strlen(subsequences[i]);
            //maxValid = strdup(subsequences[i]);
        }
    }
    
    //printf("Minimum Removed Pharentheses : %s\n", maxValid);
    printf("Minimum Removed Pharentheses :");
    for (int i = 0; i < subsequences_idx; i++) {
        if(strlen(subsequences[i]) == maxlen){
            printf("%s, ", subsequences[i]);
        }
    }

    // Free memory
    for (int i = 0; i < subsequences_idx; i++) {
        free(subsequences[i]); // Free memory for each subsequence
    }
    free(subseq);
    free(subsequences);
    //free(maxValid);
}

// s = "lee(t(c)o)de)" -> "lee(t(c)o)de"  // Input: s = "a)b(c)d" -> "ab(c)d"  // "))((" -> ""
int main(void) {
    char input[100];
    // Uncomment the following line to take user input
    printf("Enter a string: ");
    scanf("%s", input);
    printf("--------------------\n");
    generateSubseqs(input);

    return 0;
}
