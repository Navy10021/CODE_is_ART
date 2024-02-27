#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Special Palindrome : all the characters in the substring are same or only the middle character is different for odd length.
// eg. "aba", "aabaa", "aaa"(O) / "abcba"(X)

// Palindrome Check in Substring(sample)
int isPalindrome(char str[], int start, int end){
    while(start < end){
        if (str[start] != str[end]){
            return 0;
        }
        start++;
        end--;
    }
    return 1;
}

// Special Check in Substring
int isSpecial(char str[], int start, int end){
    // 알파벳 개수가 2개 보다 많을 수 없고, 2개이면, 홀수길이어야함.
    int hash[26] = {0};
    for (int i = start; i < end; i++){
        if (hash[str[i] - 'a'] == 0)
            hash[str[i] - 'a'] = 1;
    }
    int count = 0;
    for (int i = 0; i < 26; i++){
        if (hash[i])
            count++;
    }
    if (count > 2)
        return 0;

    int sub_length = end - start + 1;
    if (sub_length % 2 == 0 && count == 2)
        return 0;

    return isPalindrome(str, start, end);
}

void substringSpecialPalindrome(char str[]){
    int numOfSpecial = 0;
    int start = 0;
    int len = strlen(str);

    for (int i = 0; i < len; i++){
        for (int j = i; j < len; j++){
            if (isSpecial(str, i, j) && (j - i + 1) != 1){
                numOfSpecial++;
                int substr_len = j - i + 1;
                char * substr = (char*)malloc((substr_len + 1)*sizeof(char));
                strncpy(substr, str + i, substr_len);
                substr[substr_len] = '\0'; 
                printf("%s\n", substr);
                free(substr);
            }
        }
    }
}

int main(void){
    char input[50];
    scanf("%s", input);
    substringSpecialPalindrome(input);

    return 0;
}

