#include<stdio.h>
#include<string.h>
#include<stdlib.h>

// 316. Remove Duplicate Letters : return the smallest in lexicographical order among all possible results.
// 중복문자를 제거하되, 사전순으로 정렬된 결과 리턴. "bcabc" -> "abc" / "cbadcbc" -> "acbc"
void removeDuplicates(char * str){
    int seen[256] = {0};
    int newIdx = 0;
    for (int i = 0; i < strlen(str); i++){
        if (!seen[str[i]]){
            seen[str[i]] = 1;
            str[newIdx++] = str[i];
        }
    }
    str[newIdx] = '\0';
}

void genSubseq(char *str, int index, char *subseq, int* maxLen, char* resSubstr){
    if (str[index] == '\0'){
        char * subseqDup = strdup(subseq);
        removeDuplicates(subseqDup);
        if ((*maxLen) == strlen(subseqDup)){
            // subseq is smaller in lexicographical order than res, Update.
            if (strcmp(resSubstr, subseqDup) > 0 || resSubstr[0] == '\0'){
                strcpy(resSubstr, subseqDup);
            }
        }
        free(subseqDup);
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

void RemoveDuplicateLetters(char * str){
    // 1. 중복 제거된 길이(Max lenght)를 구한다.
    char * newStr = strdup(str);
    removeDuplicates(newStr);
    int maxLen = strlen(newStr);
    int strLen = strlen(str);
    char * maxSubstr = (char*)malloc(sizeof(char)*(strLen+1));
    char * subseq = (char*)malloc(sizeof(char)*(strLen+1));
    subseq[0] = '\0';

    // 2. Subsequnce를 생성하며, 중복제거시 Max length이면서 사전보다 빠르면 
    genSubseq(str, 0, subseq, &maxLen, maxSubstr);
    
    printf("Remove Duplicate Letters : %s\n", maxSubstr);

    free(newStr);
    free(subseq);
    free(maxSubstr);    
}


int main(void){
    char input[100];
    scanf("%s", input);
    RemoveDuplicateLetters(input);
    return 0;
}




