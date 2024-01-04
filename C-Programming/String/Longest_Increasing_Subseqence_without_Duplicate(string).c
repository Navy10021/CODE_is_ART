#include<stdio.h>
#include<string.h>
#include<stdlib.h>

// 316. Remove Duplicate Letters
/*
return the smallest in lexicographical order
*/

int isIncrease(char *str){
    for (int i = 1; i < strlen(str); i++){
        if (str[i-1] >= str[i])
            return 0;
    }
    return 1;
}

void removeDuplicates(char *str){
    int len = strlen(str);
    if (len <= 1){
        return;
    }

    int idx = 0;
    for (int i = 0; i < len; i++){
        int j;
        for (j = 0; j < idx; j++){
            if (str[i] == str[j])
                break;
        }
        if (j == idx)
            str[idx++] = str[i];
    }
    str[idx] = '\0';
}

void genSubseq(char *str, int index, char *subseq, int* maxLen, char* resSubstr){
    if (str[index] == '\0'){
        if (isIncrease(subseq) && (*maxLen) < strlen(subseq)){
            removeDuplicates(subseq);
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
    free(maxSubstr);
}


int main(void){
    char input[100];
    scanf("%s", input);
    lengthOfLIS(input);
    
    return 0;
}