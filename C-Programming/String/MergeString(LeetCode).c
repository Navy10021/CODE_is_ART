#include<stdio.h>
#include<string.h>
#include<stdlib.h>

// 1768. Merge Strings Alternately
// word1 = "ab", word2 = "pqrs" -> "apbqrs"

int min(int a, int b){
    return (a < b) ? a : b;
}

int max(int a, int b){
    return (a > b) ? a : b;
}

void mergeAlternately(char * word1, char * word2){
    // 1. merge alternately
    int len1 = strlen(word1);
    int len2 = strlen(word2);
    char *newStr = (char*)malloc((len1 + len2 + 1) * sizeof(char));
    int newIdx = 0;

    int longLen = max(len1, len2);
    int shortLen = min(len1, len2);

    for (int i = 0; i < shortLen; i++){
        newStr[newIdx++] = word1[i];
        newStr[newIdx++] = word2[i];
    }

    // 2. Add rest characters
    if (longLen > shortLen){
        for (int j = shortLen; j < longLen; j++){
            if (len1 > len2)
                newStr[newIdx++] = word1[j];
            else
                newStr[newIdx++] = word2[j];
        }
    }

    // 3. Null-terminate the new string
    newStr[newIdx] = '\0';

    // 4. Print or use the merged string as needed
    printf("Merged String: %s\n", newStr);

    // 5. Free dynamically allocated memory
    free(newStr);
}

int main(void){
    char word1[] = "ab";
    char word2[] = "pqrs";

    mergeAlternately(word1, word2);

    return 0;
}
