#include<stdio.h>
#include<string.h>
#include<stdlib.h>

// 1768. Merge Strings Alternately
// word1 = "ab", word2 = "pqrs" -> "apbqrs"

int min(int a, int b){
    return (a < b) ? a : b;
}

// Merge Sort Style
void mergeAlternately(char * word1, char * word2){
    // 1. merge alternately
    int len1 = strlen(word1);
    int len2 = strlen(word2);
    char *newStr = (char*)malloc((len1 + len2 + 1) * sizeof(char)); // Null-terminate
    int i = 0, j = 0, k = 0;   // i : word1 && j word2 && k newStr indices

    int shortLen = min(len1, len2);

    // 1.Add each characters
    while(i < shortLen && j < shortLen){
        newStr[k++] = word1[i++];
        newStr[k++] = word2[j++];
    }

    // 2.Add rest characters
    while(i < len1){
        newStr[k++] = word1[i++];
    }

    while(j < len2){
        newStr[k++] = word2[j++];
    }

    // 3. Null-terminate the new string
    newStr[k] = '\0';

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
