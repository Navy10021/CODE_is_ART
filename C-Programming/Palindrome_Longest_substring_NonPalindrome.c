#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Find Longest Non-Palindrome.

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

void findLongNonPalindrome(char str[]){
    int maxLen = 0;
    int start_idx = 0;
    int length = strlen(str);

    for (int i = 0; i < length; i++){     // Substring : str[i : j+1]
        for (int j = 0; j < length; j++){
            if (!isPalindrome(str, i, j) && (j-i+1 > maxLen)){
                maxLen = j-i+1;
                start_idx = i;
            }
        }
    }
    if (maxLen > 0){
        /*
        for (int i = start_idx; i < start_idx + maxLen; i++){
            printf("%c", str[i]);
        }
        printf("\n");
        */
       char *non_palindrome = (char*)malloc((maxLen + 1) * sizeof(char));
       int index = 0;
       for (int i = start_idx; i < start_idx + maxLen; i++){
            non_palindrome[index++] = str[i];
       }
       non_palindrome[index] = '\0';
       printf("%s\n", non_palindrome);
       free(non_palindrome);
    }
    else{
        printf("No Palindromic substring found.\n");
    }

}

int main(void){
    char input[50];
    scanf("%s", input);
    findLongNonPalindrome(input);

    return 0;
}

