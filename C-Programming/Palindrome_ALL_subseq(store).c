#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int isPalindrome(char * str){
    int st = 0;
    int en = strlen(str) - 1;

    while(st < en){
        if (str[st] != str[en]){
            return 0;
        }
        st++;
        en--;
    }
    return 1;
}

void Subsequences(char *str, int index, char *subseq, int subseqIndex, char **arr, int *arrCount) {
    // Print the current subsequence
    subseq[subseqIndex] = '\0'; // Null-terminate the subsequence
    if (isPalindrome(subseq)){
        //printf("%s\n",subseq);
        strcpy(arr[*arrCount], subseq);
        (*arrCount)++;
    }
    for (int i = index; i < strlen(str); i++) {
        // 1. Include the current character in the subsequence
        subseq[subseqIndex] = str[i];

        // 2.Recur for the next character
        Subsequences(str, i + 1, subseq, subseqIndex + 1, arr, arrCount);

        // 3.Exclude the current character in the subsequence
        subseq[subseqIndex] = '\0';
    }
}

int main() {
    char str[50];
    char subseq[50];        // Assuming a maximum length for the subsequence
    char **arr;             // The Maximum number of stored elements are 300;   
    int arrCount = 0;

    // Allocate memory for Array
    arr = (char **)malloc(300 * sizeof(char *));
    for (int i = 0; i < 300; i++){
        arr[i] = (char *)malloc(50 * sizeof(char));
    }


    scanf("%s", str);
    printf("All Palindromic subsequnces of \"%s\" are:\n", str);
    Subsequences(str, 0, subseq, 0, arr, &arrCount);

    for (int i = 0; i < arrCount; i++){
        printf("%s\n", arr[i]);
    }

    // Free the allocated memory
    for (int i = 0; i < 300; i++) {
        free(arr[i]);
    }
    free(arr);
    
    return 0;
}
