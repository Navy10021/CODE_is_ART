#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// Generate subsequences
// Function to check if a subsequence is already seen
int seen(char **arr, int arr_idx, char *target) {
    for (int i = 0; i < arr_idx; i++) {
        if (strcmp(arr[i], target) == 0) {
            return 1;
        }
    }
    return 0;
}

// Backtrack to generate subsequences
void backtrack(char *str, int index, char *subseq, int subseq_idx, char **subseqs, int *subseqs_idx) {
    if (str[index] == '\0' && strlen(subseq) > 0) {
        if (!seen(subseqs, *subseqs_idx, subseq)) {
            subseqs[*subseqs_idx] = strdup(subseq);
            (*subseqs_idx)++;
            return;
        }
        return;
    }
    for (int i = index; i <= strlen(str); i++){
        // 1. Include current character
        subseq[subseq_idx] = str[i];
        // 2. Exclude the current character: str[index++]
        backtrack(str, i + 1, subseq, subseq_idx + 1, subseqs, subseqs_idx);
        // 3. pop the last character
        subseq[subseq_idx] = '\0';
    }
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
