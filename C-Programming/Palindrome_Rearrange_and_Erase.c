#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int isPalindrome(char str[]){
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

void swap(char * a, char * b){
    char temp = *a;
    *a = *b;
    *b = temp;
}

int shouldSwap(char * str, int st, int en){
    for (int i = st; i < en; i++){
        if (str[i] == str[en])
            return 0;
    }
    return 1;
}

// 1. Rearrange string using Permutation.
void AnagramPalindrome(char str[], int curr_idx, int length){
    if (curr_idx == length - 1){
        if (isPalindrome(str)){
            printf("%s\n", str);
            return;
        }
    }
    for (int i = curr_idx; i < length; i++){
        if (shouldSwap(str, curr_idx, i)){
            swap(&str[curr_idx], &str[i]);
            AnagramPalindrome(str, curr_idx + 1, length);
            swap(&str[curr_idx], &str[i]);
        }
    }
}

// 2. Erase string using Generate Subsequence.
void GenSubseq(char str[], int curr_idx, char subseq[]){
    int length = strlen(str);

    if (curr_idx == length){
        int sub_len = strlen(subseq);
        AnagramPalindrome(subseq, 0, sub_len);
        return;
    }

    // Exclude current char
    GenSubseq(str, curr_idx + 1, subseq);

    // Include current char
    int subseq_len = strlen(subseq);
    subseq[subseq_len] = str[curr_idx];
    subseq[subseq_len + 1] = '\0';
    GenSubseq(str, curr_idx + 1, subseq);   // Recursion

    // Backtrack: Exclude current char
    subseq[subseq_len] = '\0';
}

int main(void){
    char input[] = "aabc";
    int length = strlen(input);
    char subseq[length + 1];
    subseq[0] = '\0';

    GenSubseq(input, 0, subseq);
    return 0;
}
