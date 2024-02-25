#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 주어진 문자열의 Substring 중에 target의 모든 characters를 포함하는 최소 길이의 Substring
// 76. Minimum Window Substring
// given two string s and t -> return minimum window substring of s 
// such that every character in t(including duplicates) is included.

int isContain(char * str, char * target){
    // Calculate the length difference between str and target
    int diff = strlen(str) - strlen(target);
    if (diff < 0){
        return 0;  // target is longer, cannot be contained
    }
    // Make hash table 
    int hash[52] = {0};
    for (int i = 0; i < strlen(str); i++){
        hash[str[i]-'A']++;
    }
    // Subtrct the character frequencies of target from hash
    for (int j = 0; j < strlen(target); j++){
        if(hash[target[j] - 'A'] == 0){
            return 0;
        }
        hash[target[j]-'A']--;
    }
    // count hash's characters
    int remainChars = 0;
    for (int i = 0; i < 52; i++){
        remainChars += hash[i];
    }
    return (remainChars == diff);
}

void minWindow(char * s, char * t){
    int length = strlen(s);
    int minLen = length;
    char* minStr = strdup(s);
    for (int i = 0; i < length; i++){
        for (int j = i; j < length; j++){
            int subLen = j - i + 1;
            char * substr = malloc(sizeof(char)*(subLen+1));
            strncpy(substr, s + i, subLen);
            substr[subLen] = '\0';
            if (isContain(substr, t) && subLen < minLen){
                minLen = subLen;
                minStr = strdup(substr);
            }

            free(substr);
        }
    }
    if(minStr != NULL){
        printf("MinWindow string : %s\n", minStr);
    }
    else{
        printf("None\n");
    }
    free(minStr);
}


int main() {
    // Example usage:
    char str[] = "ADOBECODEBANC";
    char target[] = "ABC";

    minWindow(str, target);

    return 0;
}
