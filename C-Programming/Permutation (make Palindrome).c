#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// Permutation을 이용하여 사전순 가장 작은 팰린드롬과 사전순 가장 큰 팰린드롬을 리턴하는 함수.
// 팰린드롬 함수
int isPalindrome(char * str){
    int st = 0;
    int en = strlen(str) - 1;

    while(st < en){
        if (str[st] != str[en])
            return 0;
        st++;
        en--;
    }
    return 1;
}
// 문자열 비교함수 : 사전순 정렬
int compareStr(const void * a, const void * b){
    return strcmp(*(const char **)a, *(const char **)b);
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

void genPerm(char * str, int start, int lenght, char ** result, int * count){
    if (start == lenght - 1 && isPalindrome(str)){
        // Allocate memory for the result(string) and copy the permutation
        result[*count] = malloc((lenght + 1) * sizeof(char));   // length + '\0'
        strcpy(result[*count], str);
        (*count)++;
        return;
    }
    
    for (int i = start; i < lenght; i++){
        if (shoudSwap(str, start, i)){
            swap(&str[start], &str[i]);
            genPerm(str, start + 1, lenght, result, count);
            swap(&str[start], &str[i]);     // Backtrack
        }
    }
}

int main(){
    char input[10];
    scanf("%s", input);
    int len = strlen(input);
    
    // Calculate the number of permutations (n!)
    int numPerms = 1;
    for (int i = 1; i <= len; i++){
        numPerms *= i;
    }

    // Allocate memory for the array to store permutations
    char **permutations = malloc(numPerms * sizeof(char *));
    if (permutations == NULL) {
        fprintf(stderr, "Memory allocation error\n");
        return 1;
    }
    int count = 0;
    
    genPerm(input, 0, len, permutations, &count);

    // Sorting(array size == count)
    qsort(permutations, count, sizeof(permutations[0]), compareStr);

    
    // Use the stored permutations. 정렬을 통해 사전순 가장 작은 것을 리턴
    if (count > 0) {
        printf("Lexicograpically smallest : %s\n", permutations[0]);
        printf("Lexicograpically largest : %s\n", permutations[count-1]);
    } else {
        printf("Sorry ! No palindromic permutations\n");
    }

    // Free allocated memory
    for (int i = 0; i < count; i++){
        free(permutations[i]);
    }
    free(permutations);

    return 0;
}
