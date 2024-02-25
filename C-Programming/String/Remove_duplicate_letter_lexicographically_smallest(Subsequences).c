#include<stdio.h>
#include<string.h>
#include<stdlib.h>

// 316. Remove Duplicate Letters : return the smallest in lexicographical order among all possible results.
// 중복문자를 제거하되, 사전순으로 정렬된 결과 리턴. "bcabc" -> "abc" / "cbacdcbc" -> "acdb"
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

int is_anagram(char* str1, char* str2){
    int hash[256] = {0};
    for (int i = 0; i < strlen(str1); i++){
        hash[str1[i]]++;
    }

    for (int i = 0; i < strlen(str2); i++){
        hash[str2[i]]--;
    }

    for (int i = 0; i < 256; i++){
        if (hash[i] != 0){
            return 0;
        }
    }
    return 1;
}

void partition(char* str, int l, int r, char* path, int path_idx, char* removed_str, char ** res_str){
    if (l == r){
        path[path_idx] = '\0';
        // 중복 제거된 문자열과 아나그램 && 빠른 사전순이면 저장
        if (is_anagram(removed_str, path)){
            if (strcmp(path, *res_str) < 0 || strcmp(*res_str, "") == 0){
                free(*res_str);
                *res_str = strdup(path);
            }
        }
        return;
    }
    // Include
    path[path_idx] = str[l];
    partition(str, l + 1, r, path, path_idx + 1, removed_str, res_str);
    // Exclude
    partition(str, l + 1, r, path, path_idx, removed_str, res_str);
}

void RemoveDuplicateLetters(char * str){
    // 1. 중복 제거된 길이(Max lenght)를 구한다.
    char * newStr = strdup(str);
    removeDuplicates(newStr);
    int resLen = strlen(newStr);
    int strLen = strlen(str);
    char * res = strdup("");
    char * path = (char*)malloc(sizeof(char)*(strLen+1));

    // 2. Subsequnce를 생성
    partition(str, 0, strLen, path, 0, newStr, &res);
    
    printf("Remove Duplicate Letters : %s\n", res);

    free(newStr);
    free(path);
    free(res);    
}


int main(void){
    //char input[50] = "bcabc";
    char input[50] = "cbacdcbc";
    RemoveDuplicateLetters(input);

    return 0;
}




