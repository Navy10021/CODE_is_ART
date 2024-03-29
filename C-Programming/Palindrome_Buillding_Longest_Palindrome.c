#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// string reverse function
void reverse(char * str){
    int st = 0;
    int en = strlen(str)-1;
    
    while(st < en){  //Swap
        char temp = str[st];
        str[st] = str[en];
        str[en] = temp;
        st++;
        en--;
    }
}

// if need to check palindrome, add function

// LeetCode 409 : Longest Palindrome + print builted Palindrome
void longestPalindrome(char * str){
    // hash table 
    int hash[256] = {0};
    int length = strlen(str);
    for (int i=0; i<length; i++){
        hash[str[i]]++;
    }
    
    // build palindrome 
    char * new_str = (char*)malloc((length + 1) * sizeof(char));
    int str_idx = 0;
    for (int i=0; i<256; i++){
        if (hash[i] > 0 && hash[i]%2 == 0){
            while(hash[i] > 0){
                new_str[str_idx++] = i;
                hash[i] -= 2;
            }
        }
        else if (hash[i] > 0 && hash[i]%2 != 0){
            while(hash[i] > 1){
                new_str[str_idx++] = i;
                hash[i] -= 2;
            }
        }
    }
    
    new_str[str_idx] = '\0';
    char * reversed_str = strdup(new_str);
    reverse(reversed_str);
    //printf("%s | %s\n", new_str, reversed_str);
    
    // special case : odd length palindrome.
    int is_odd = 0;
    for (int i=0; i<256; i++){
        if(hash[i] == 1){
            char * copy_str = strdup(new_str);
            copy_str[str_idx++] = i;
            copy_str[str_idx] = '\0';
            is_odd = 1;
            strcat(copy_str, reversed_str);
            printf("%s\n", copy_str);
            str_idx--;
            free(copy_str);
        }
    }
    
    if (!is_odd){
        char * copy_str = strdup(new_str);
        strcat(copy_str, reversed_str);
        printf("%s\n", copy_str);
        free(copy_str);
    }
    
    free(new_str);
    free(reversed_str);
    return;
}

int main(void){
    char input[50];
    scanf("%s", input);
    longestPalindrome(input);
    return 0;
}
