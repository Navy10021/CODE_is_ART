#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// LeetCode 1456. Maximum Number of Vowels in a Substring of Given length

int is_aeiou(char c){
    if (c == 'a' || c == 'e' || c == 'o' || c == 'i' ||c == 'u'){
        return 1;
    }
    return 0;
}

int maxVowels(char* str, int k){
    // Substring
    int maxVol = 0;
    char * maxVolstr = NULL;
    int len = strlen(str);
    for (int i = 0; i < len; i++){
        for (int j = i; j < len; j++){
            int subLen = j - i + 1;
            if (subLen == k){
                char * substr = (char*) malloc(sizeof(char)*(subLen+1));
                strncpy(substr, str+i, subLen);
                substr[subLen] = '\0';
                int count = 0;
                for (int k = 0; k < subLen; k++){
                    if (is_aeiou(substr[k])){
                        count++;
                    }
                }
                if (count > maxVol){
                    maxVol = count;
                    maxVolstr = strdup(substr);
                }
                free(substr);
            }
        }
    }
    printf("Max Vowels : %s (%d)", maxVolstr, maxVol);
    free(maxVolstr);
    return maxVol;
}

int main(void){
    char input[50];
    int K;
    scanf("%s %d", input, &K);
    int res = maxVowels(input, K);
}