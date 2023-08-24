#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool is_palindrome(const char* s, int start, int end) {
    while (start < end) {
        if (s[start] != s[end - 1]) {
            return false;
        }
        start++;
        end--;
    }
    return true;
}

bool is_substring(const char* s, const char* t) {
    return strstr(s, t) != NULL;
}

void max_palindromes(const char* s, char result[][256], int* resultSize) {
    int n = strlen(s);
    char pdlist[n][256];
    int pdlistSize = 0;
    char pd[256];

    for (int st = 0; st < n; st++) {
        int max_length = 0;
        for (int en = st + 1; en <= n; en++) {
            if (is_palindrome(s, st, en) && en - st > max_length) {
                max_length = en - st;
                strncpy(pd, &s[st], max_length);
                pd[max_length] = '\0';
            }
        }
        
        bool toAdd = true;
        for (int i = 0; i < pdlistSize; i++) {
            if (is_substring(pdlist[i], pd) || is_substring(pd, pdlist[i])) {
                toAdd = false;
                if (strlen(pd) > strlen(pdlist[i])) {
                    strcpy(pdlist[i], pd);
                }
                break;
            }
        }
        if (toAdd) {
            strcpy(pdlist[pdlistSize++], pd);
        }
    }

    for (int i = 0; i < pdlistSize; i++) {
        strcpy(result[i], pdlist[i]);
    }
    *resultSize = pdlistSize;
}

int main() {
    char s1[] = "kabccbadzdefgfeda";
    char s2[] = "kabccba dzabccbaza";
    char s3[] = "asdsa azazza";
    char s4[] = "kkak";
    char result[256][256];
    int resultSize;
    printf("test case 1 \n");
    max_palindromes(s1, result, &resultSize);
    for (int i = 0; i < resultSize; i++) {
        printf("%s\n", result[i]);
    }

    printf("\ntest case 2 \n");
    max_palindromes(s2, result, &resultSize);
    for (int i = 0; i < resultSize; i++) {
        printf("%s\n", result[i]);
    }
    printf("\ntest case 3 \n");

    max_palindromes(s3, result, &resultSize);
    for (int i = 0; i < resultSize; i++) {
        printf("%s\n", result[i]);
    }
    printf("\ntest case 4 \n");

    max_palindromes(s4, result, &resultSize);
    for (int i = 0; i < resultSize; i++) {
        printf("%s\n", result[i]);
    }

    return 0;
}
