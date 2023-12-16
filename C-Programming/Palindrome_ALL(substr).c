#include <stdio.h>
#include <string.h>
#include <stdlib.h>

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

void subString(char * str){
    int n = strlen(str);

    for (int i = 0; i < n; i++){
        for (int j = i + 1; j < n + 1; j++){
            char *substr = (char *)malloc((j - i + 1) * sizeof(char));
            int idx = 0; 
            for (int k = i; k < j; k++){
                substr[idx++] = str[k];
            }
            substr[idx] = '\0';         // Null-terminate!
            printf("%s\n", substr);
            
            // Check if the substring is palindrome
            if (isPalindrome(substr)){
                printf("%s\n", substr);
            }
            free(substr);        // Free the memory 
        }
    }
}

int main(void){
    char input[100];
    scanf("%s", input);
    subString(input);
}
