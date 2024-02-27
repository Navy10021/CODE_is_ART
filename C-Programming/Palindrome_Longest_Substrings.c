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

char *MaxsubString(char * str){
    int n = strlen(str);
    int maxLen = 0;
    char *maxSubstr = NULL;

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
                if ((j - i + 1) > maxLen){
                    maxLen = (j - i + 1);
                    if(maxSubstr != NULL){      // If a longer palindrome is found, update maxSubstr
                        free(maxSubstr);
                    }
                    maxSubstr = strdup(substr); // strdup : allocates memory and copies the string
                }
            }
            free(substr);
        }
    }
    return maxSubstr;
}

int main(void){
    char input[100];
    scanf("%s", input);
    char *res = MaxsubString(input);
    if (res != NULL){
        printf("%s\n", res);
    }
    else{
        printf("No palindrome substring found.\n");
    }
}
