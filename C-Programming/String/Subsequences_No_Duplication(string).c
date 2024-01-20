#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
    if (str[index] == '\0' && strlen(subseq) > 0) {
        if (!seen(subseqs, *subseqs_idx, subseq)) {
            subseqs[*subseqs_idx] = strdup(subseq);
            (*subseqs_idx)++;
            return;
        }
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

    // Print the generated subsequences
    for (int i = 0; i < subsequences_idx; i++) {
        printf("%s\n", subsequences[i]);
        free(subsequences[i]); // Free memory for each subsequence
    }

    // Free memory
    free(subseq);
    free(subsequences);
}

int main(void) {
    char input[100];
    // Uncomment the following line to take user input
    printf("Enter a string: ");
    scanf("%s", input);
    printf("--------------------\n");
    generateSubseqs(input);

    return 0;
}
