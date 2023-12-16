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

void printSubsequences(char str[], int index, char subseq[], int subseqIndex) {
    // Print the current subsequence
    subseq[subseqIndex] = '\0'; // Null-terminate the subsequence
    if (isPalindrome(subseq)){
        printf("%s\n",subseq);
    }
    for (int i = index; i < strlen(str); i++) {
        // 1. Include the current character in the subsequence
        subseq[subseqIndex] = str[i];

        // 2.Recur for the next character
        printSubsequences(str, i + 1, subseq, subseqIndex + 1);

        // 3.Exclude the current character in the subsequence
        subseq[subseqIndex] = '\0';
    }
}

int main() {
    char str[50];
    char subseq[50]; // Assuming a maximum length for the subsequence
    scanf("%s", str);
    printf("All subsequences of \"%s\" are:\n", str);
    printSubsequences(str, 0, subseq, 0);

    return 0;
}
