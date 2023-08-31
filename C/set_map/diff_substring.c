#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void generateSubstrings(const char* str, int len, char** uniqueSubstrings, int* uniqueCount) {
    for (int subLen = 1; subLen <= len; subLen++) {
        for (int start = 0; start <= len - subLen; start++) {
            char* substr = (char*)malloc((subLen + 1) * sizeof(char));
            strncpy(substr, str + start, subLen);   // subLen 길이만큼만
            substr[subLen] = '\0';
            
            int isUnique = 1;
            for (int i = 0; i < *uniqueCount; i++) {
                if (strcmp(substr, uniqueSubstrings[i]) == 0) {
                    isUnique = 0;
                    break;
                }
            }

            if (isUnique) {
                uniqueSubstrings[*uniqueCount] = substr;
                (*uniqueCount)++;
            } else {
                free(substr);
            }
        }
    }
}

int main() {
    char input[100];
    scanf("%s", input);

    int len = strlen(input);

    char** uniqueSubstrings = (char**)malloc(len * len * sizeof(char*));
    int uniqueCount = 0;

    generateSubstrings(input, len, uniqueSubstrings, &uniqueCount);

    for (int i = 0; i < uniqueCount; i++) {
        printf("%s\n", uniqueSubstrings[i]);
        free(uniqueSubstrings[i]);
    }
    
    printf("%d\n", uniqueCount);

    free(uniqueSubstrings);

    return 0;
}
