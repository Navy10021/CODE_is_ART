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

// check palindrome function
int isPalindrome(char * str){
    int st = 0;
    int en = strlen(str) - 1;
    while(st < en){
        if (str[st]!=str[en]){
            return 0;
        }
        st++;
        en--;
    }
    return 1;
}

// swap function
void swap(char *a, char *b){
    char temp = *a;
    *a = *b;
    *b = temp;
}

int shouldSwap(char * str, int st, int en){
    for (int i = st; i < en; i++){
        if (str[i] == str[en]){
            return 0;
        }
    }
    return 1;
}

// permutation function
void rearrange(char* str, int str_idx, int length){
    if (str_idx == length - 1 && isPalindrome(str)){
        printf("%s\n", str);
        return;
    }
    for (int i = str_idx; i < length; i++){
        if (shouldSwap(str, str_idx, i)){
            swap(&str[str_idx], &str[i]);
            rearrange(str, str_idx + 1, length);
            swap(&str[str_idx], &str[i]);
        }
    }
}

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
            //printf("%s\n", copy_str);
            rearrange(copy_str, 0, strlen(copy_str));
            str_idx--;
            free(copy_str);
        }
    }
    
    if (!is_odd){
        char * copy_str = strdup(new_str);
        strcat(copy_str, reversed_str);
        //printf("%s\n", copy_str);
        rearrange(copy_str, 0, strlen(copy_str));
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
