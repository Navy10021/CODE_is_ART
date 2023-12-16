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

char *MinsubString(char * str){
    int n = strlen(str);
    int minLen = n;
    char *minSubstr = NULL;

    for (int i = 0; i < n; i++){
        for (int j = i + 1; j < n + 1; j++){
            char *substr = (char *)malloc((j - i + 1) * sizeof(char));
            int idx = 0; 
            for (int k = i; k < j; k++){
                substr[idx++] = str[k];
            }
            substr[idx] = '\0';         // Null-terminate!
            
            // Check if the substring is palindrome
            if (isPalindrome(substr)){
                if ((j - i + 1) < minLen){
                    minLen = (j - i + 1);
                    if(minSubstr != NULL){      // If a shorter palindrome is found, update minSubstr
                        free(minSubstr);
                    }
                    minSubstr = strdup(substr); // strdup : allocates memory and copies the string
                }
            }
            free(substr);
        }
    }
    return minSubstr;
}

int main(void){
    char input[100];
    scanf("%s", input);
    char *res = MinsubString(input);
    if (res != NULL){
        printf("%s\n", res);
    }
    else{
        printf("No palindrome substring found.\n");
    }
}
