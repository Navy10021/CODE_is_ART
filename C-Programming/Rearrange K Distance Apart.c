#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int compareStr(const void * a, const void * b){
    return strcmp(*(const char **)a, *(const char **)b);
}
// Same characters are at least distance k from each other.
int isKDistance(char* str, int k){
    for (int i = 0; i < strlen(str); i++){
        for (int j = i + 1; j < i + k; j++){
            if (str[i] == str[j]){
                return 0;
            }
        }
    }
    return 1;
}

void swap(char * a, char * b){
    char temp = *a;
    *a = *b;
    *b = temp;
}

int shoudSwap(char * str, int start, int end){
    for (int i = start; i < end; i++){
        if (str[i] == str[end]){
            return 0;   // Character are the same. No swap.
        }
    }
    return 1;    // Character are different. Swap.
}

void genPerm(char * str, int k, int start, int lenght, char ** result, int * count){
    if (start == lenght - 1 && isKDistance(str, k)){
        //printf("%s\n", str);
        // Allocate memory for the result(string) and copy the permutation
        result[*count] = malloc((lenght + 1) * sizeof(char));   // length + '\0'
        strcpy(result[*count], str);
        (*count)++;
        return;
    }
    
    for (int i = start; i < lenght; i++){
        if (shoudSwap(str, start, i)){
            swap(&str[start], &str[i]);
            genPerm(str, k, start + 1, lenght, result, count);
            swap(&str[start], &str[i]);     // Backtrack
        }
    }
}

int main(){
    char input[10];
    int k;
    scanf("%s %d", input, &k);

    int len = strlen(input);
    
    // Calculate the number of permutations (n!)
    int numPerms = 1;
    for (int i = 1; i <= len; i++){
        numPerms *= i;
    }

    // Allocate memory for the array to store permutations
    char **permutations = malloc(numPerms * sizeof(char *));
    int count = 0;
    
    genPerm(input, k, 0, len, permutations, &count);

    // Sorting
    qsort(permutations, count, sizeof(permutations[0]), compareStr);

    // Use the stored permutations
    for (int i = 0; i < count; i++){
        printf("%s\n", permutations[i]);
    }

    // Free allocated memory
    for (int i = 0; i < count; i++){
        free(permutations[i]);
    }
    free(permutations);

    return 0;
}
