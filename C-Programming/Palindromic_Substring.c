#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// 647. palindromic Substring
// s = abc -> 3(a, b, c)
// s = aaa -> 6(a, a, a, aa, aa, aaa)

int isPalindrome(char * str){
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

int countSubstr(char * str){
    int n = strlen(str);
    int palindromic = 0;
    
    for (int i = 0; i < n; i++){
        for (int j = i + 1; j <= n; j++){
            int sublen = j - i;    // length for strncpy
            char * substr = (char*)malloc((sublen + 1) * sizeof(char));
            strncpy(substr, str + i, sublen);
            substr[sublen] = '\0'; // Need to null terminate
            
            if (isPalindrome(substr)){
                printf("%s, ", substr);
                palindromic++;
            }
            free(substr);
        }
    }
    return palindromic;
}

int main(void){
    char input[50];
    scanf("%s", input);
    
    int res = countSubstr(input);
    printf("\nPalindromic Substring : %d", res);
}
