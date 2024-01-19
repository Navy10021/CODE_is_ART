#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// Generate subsequences

int seen(char ** arr, int arr_idx, char * target){
    for(int i=0; i<arr_idx; i++){
        if(strcmp(arr[i], target)==0){
            return 1;
        }
    }
    return 0;
}

// 1. backtrack
void backtrack(char *str, int index, char*subseq, char**subseqs, int*subseqs_idx){
    if (str[index] == '\0'){
        if (!seen(subseqs, *subseqs_idx, subseq)){
            subseqs[*subseqs_idx] = strdup(subseq);
            (*subseqs_idx)++;
            return;
        }
        return;
    }
    // Exclude the curr char : str[index++]
    backtrack(str, index + 1, subseq, subseqs, subseqs_idx);
    // include
    subseq[strlen(subseq)] = str[index];
    subseq[strlen(subseq)+1] = '\0';
    backtrack(str, index + 1, subseq, subseqs, subseqs_idx);
    // pop()
    subseq[strlen(subseq)-1] = '\0';
}

void LongestCommonSubseqs(char *str1, char *str2){
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    char * subseq1 = (char*)malloc(sizeof(char) * (len1 + 1));
    char * subseq2 = (char*)malloc(sizeof(char) * (len2 + 2));
    int subsequences_size1 = 1 << len1;
    int subsequences_size2 = 1 << len2;
    char ** subsequences1 = (char**)malloc(sizeof(char*) * subsequences_size1);
    char ** subsequences2 = (char**)malloc(sizeof(char*) * subsequences_size2);
    int subsequences_idx1 = 0;
    int subsequences_idx2 = 0;
    backtrack(str1, 0, subseq1, subsequences1, &subsequences_idx1);
    backtrack(str2, 0, subseq2, subsequences2, &subsequences_idx2);
    
    free(subseq1);
    free(subseq2);
    
    int common_len = 0;
    char * common_str = NULL;
    // Compare two arrays
    for(int i = 0; i < subsequences_idx1; i++){
        for (int j = 0; j < subsequences_idx2; j++){
            if (strcmp(subsequences1[i], subsequences2[j])==0 && common_len < strlen(subsequences1[i])){
                common_len = strlen(subsequences1[i]);
                common_str = strdup(subsequences1[i]);
            }
        }
    }
    printf("The Longest Common subsequences : %s \n", common_str);
    free(common_str);
    free(subsequences1);
    free(subsequences2);
}

int main(void){
    char str1[100] = "ABYYB";
    char str2[100] = "XXAXXBXXB";
    
    LongestCommonSubseqs(str1, str2);
    
    return 0;
    // generate subseqs arr -> compare
}