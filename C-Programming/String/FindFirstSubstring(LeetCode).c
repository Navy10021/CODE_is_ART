#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// 28. Find the Index of the First Occurrence in a String

int FindSubstr(char* haystack, char* needle){
    // Find Substring and store first index
    int length = strlen(haystack);
    int firstIdx = -1;

    for (int i = 0; i < length; i++){
        for (int j = i; j < length; j++){
            int subLength = j - i + 1;
            char * substr = (char*)malloc((subLength+1)*sizeof(char));
            strncpy(substr, haystack + i, subLength);
            substr[subLength] = '\0';
            if (strcmp(substr, needle) == 0){
                firstIdx = i;
                free(substr);
                return firstIdx;
            }
            free(substr);
        }
    }
    printf("Can't find needle.\n");
    return -1;
}

int main(void){
    char haystack[100];
    char needle[100];
    scanf("%s %s", haystack, needle);

    int res = FindSubstr(haystack, needle);
    printf("%d", res);
}