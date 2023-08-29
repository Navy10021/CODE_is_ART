#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 길이순 -> 알파벳순 
typedef struct{
    int len;
    char str[55];
} Word;

/*
strcmp(str1, str2) ASCII 기준 크기(즉 알파벳 크기)
str1 < str2 -> return -1;
str1 > str2 -> return 1;
str1 == str2 -> return 0;
*/  
int compare(const void* first, const void* second){
    Word *A = (Word*)first;
    Word *B = (Word*)second;

    if (A->len < B->len)
        return -1;
    else if (A->len > B->len)
        return 1;
    else if (A->len == B->len){
        if (strcmp(A->str, B->str) < 0)
            return -1;
        else   
            return 1;
    }
    return 0;
}

int main(){
    int N;
    scanf("%d", &N);
    Word* arr = (Word *)calloc(N+1, sizeof(Word));
    // Word arr[N];

    for (int i=0; i<N; i++){
        scanf("%s", arr[i].str);
        arr[i].len = strlen(arr[i].str);

        // 중복제거 
        for (int j=0; j<i; j++){
            if(strcmp(arr[i].str, arr[j].str)==0){
                i-=1;
                N-=1;
                break;
            }
        }
    }
    // 정렬 
    qsort(arr, N, sizeof(arr[0]), compare);
    
    printf("===== Sorted =====\n");
    for(int i=0; i<N; i++){
        printf("%s  ", arr[i].str);
    }
}
