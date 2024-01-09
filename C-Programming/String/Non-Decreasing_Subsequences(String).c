#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 491. Non-Decreasing Subseqences

int isNonDecreasing(char *str){
    for (int i = 1; i < strlen(str); i++){
        if (str[i-1] > str[i])
            return 0;
    }
    return 1;
}

int isIn(char ** strings, int currIdx, const char *val){
    for (int i = 0; i < currIdx; i++){
        if (strcmp(strings[i], val) == 0)
           return 1;
    }
    return 0;
}

void genSubseq(char *str, int index, char *subseq, char **res, int *resIdx){
    if (str[index] == '\0'){
        if (isNonDecreasing(subseq) && strlen(subseq) > 1 && !isIn(res, *resIdx, subseq)){
            //printf("%s\n", subseq);
            res[(*resIdx)++] = strdup(subseq);
            return;
        }
        return;
    }
    // Exclude
    genSubseq(str, index + 1, subseq, res, resIdx);
    // Include
    subseq[strlen(subseq)] = str[index];
    subseq[strlen(subseq)+1] = '\0';
    genSubseq(str, index + 1, subseq, res, resIdx);
    // BackTrack
    subseq[strlen(subseq) - 1] = '\0';
}

void findSubseq(char * string){
    int strLen = strlen(string);
    char * subseq = (char*)malloc(sizeof(char) * (strLen + 1));
    subseq[0] = '\0';
    int capacity = 1 << strlen(string);  // 2^len
    char** resArr = (char**)malloc(sizeof(char*) * capacity);
    int resIdx = 0;
    genSubseq(string, 0, subseq, resArr, &resIdx);
    free(subseq);

    // Print
    for (int i=0; i<resIdx; i++){
        printf("%s\n", resArr[i]);
        free(resArr[i]);
    }
    free(resArr);
    
}

int main(void){
    char input[100];
    scanf("%s", input);

    findSubseq(input);
    
    return 0;
}