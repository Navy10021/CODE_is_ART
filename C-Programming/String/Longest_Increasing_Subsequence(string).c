#include<stdio.h>
#include<string.h>
#include<stdlib.h>

// 300. Longest Increasing Subsequence
/*
return length of the longest strictly increasing subsequnce
*/

int isIncrease(char *str){
    for (int i = 1; i < strlen(str); i++){
        if (str[i-1] >= str[i])
            return 0;
    }
    return 1;
}

void genSubseq(char *str, int index, char *subseq, int* maxLen, char* resSubstr){
    if (str[index] == '\0'){
        if (isIncrease(subseq) && (*maxLen) < strlen(subseq)){
            *maxLen = strlen(subseq);
            strcpy(resSubstr, subseq);
            return;
        }
        return;
    }
    // Exclude the current char
    genSubseq(str, index+1, subseq, maxLen, resSubstr);
    // Include
    subseq[strlen(subseq)] = str[index];
    subseq[strlen(subseq)+1] = '\0';
    genSubseq(str, index+1, subseq, maxLen, resSubstr);
    // Backtrak
    subseq[strlen(subseq)-1] = '\0';
}

void lengthOfLIS(char * str){
    int maxLen = 0;
    int strLen = strlen(str);
    char * maxSubstr = (char*)malloc(sizeof(char)*(strLen+1));
    char * subseq = (char*)malloc(sizeof(char)*(strLen+1));
    subseq[0] = '\0';
    
    genSubseq(str, 0, subseq, &maxLen, maxSubstr);
    free(subseq);
    printf("LIS : %s\n", maxSubstr);
    printf("Max length : %d\n", maxLen);
}


int main(void){
    char input[100];
    scanf("%s", input);
    lengthOfLIS(input);
    
    return 0;
}