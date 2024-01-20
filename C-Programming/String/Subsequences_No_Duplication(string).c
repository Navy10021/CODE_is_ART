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

void generateSubseqs(char *str){
    int len = strlen(str);
    char * subseq = (char*)malloc(sizeof(char) * (len + 1));
    int subsequences_size = 1 << len;
    char ** subsequences = (char**)malloc(sizeof(char*) * subsequences_size);
    int subsequences_idx = 0;
    backtrack(str, 0, subseq, subsequences, &subsequences_idx);

    // Using subsequnces

    // free memory
    free(subseq);
    for(int i = 0; i < subsequences_idx; i++){
        printf("%s\n", subsequences[i]);
    }
    free(subsequences);
}

int main(void){
    char str1[100] = "ABB";
    generateSubseqs(str1);
    
    // generate subseqs arr -> compare
}
