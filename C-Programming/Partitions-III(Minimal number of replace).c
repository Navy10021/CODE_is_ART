#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

// is palindrome
int is_palindrome(char * str){
    int st = 0;
    int en = strlen(str) - 1;

    while(st < en){
        if (str[st] != str[en]){
            return 0;
        }
        st++;
        en--;
    }
    return 1;
}

// Calculate Count Convert to string Palindrome.
int palindrome_replace(char* str){
    int st = 0;
    int en = strlen(str) - 1;
    int count = 0; // replace

    while (st < en){
        if (str[st] != str[en]){
            count++;
            if (str[st] < str[en]){
                str[en] = str[st];
            }
            else{
                str[st] = str[en];
            } 
        }
        st++;
        en--;
    }
    //printf("Replaced string : %s\n", str);
    //printf("The number of replaced characters : %d\n", count);
    return count;
}

void genPartitions(int* min_replace, char *str, int start, int n, int k, int curr_paritions, char arr[][n+1], int arr_idx){
    if (start >= n){
        if (curr_paritions == k){
            // 파티션의 각 요소가 팰린드롬인지 확인, 팰린드롬이 아닌경우 알파벳 변경 카운트
            int curr_replace = 0;
            for (int i = 0; i < arr_idx; i++){
                if(!is_palindrome(arr[i])){
                    char* new_element = strdup(arr[i]);
                    curr_replace += palindrome_replace(new_element);
                    printf(" %s |", new_element);
                    free(new_element);
                }
                else{
                    printf(" %s |", arr[i]);
                }
            }
            // 최소 변경값 업데이트
            printf("  Replacement : %d\n", curr_replace);
            if (curr_replace < *min_replace){
                *min_replace = curr_replace;
            }
        }
        return;
    }
    for (int end = start; end < n; end++){
        int len = end - start + 1;
        strncpy(arr[arr_idx], str + start, len);
        arr[arr_idx][len] = '\0';

        genPartitions(min_replace, str, end + 1, n, k, curr_paritions + 1, arr, arr_idx + 1);
    }
}

// Split k-th partitions
void partitions(char* str, int k){
    int len = strlen(str);
    char arr[len][len + 1];
    int min_replace = len;

    genPartitions(&min_replace, str, 0, len, k, 0, arr, 0);
    printf("Minimal number of characters : %d", min_replace);
}

int main(void){
    char input[50] = "aabbc";
    int k = 3;
    partitions(input, k);

    return 0;
}
