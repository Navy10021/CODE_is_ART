#include <stdio.h>
#include <string.h>

int main(void){
    char* strings[] = {"abcde", "apple", "abc", "ac", "ab", "ad", "cd"};
    int n = sizeof(strings) / sizeof(strings[0]);
    
    // Initialize
    char * longest = strings[0];
    int long_len = strlen(strings[0]);
    
    for (int i = 1; i < n; i++){
        int curr_len = strlen(strings[i]);
        // case 1. update longest length & longest
        if (curr_len > long_len){
            longest = strings[i];
            long_len = curr_len;
        }
        // case 2. update Lexicographically longest 
        else if (curr_len == long_len && strcmp(strings[i], longest) > 0){
            longest = strings[i];
        }
    }
    
    printf("The Longest string : %s\n", longest);
    
    return 0;
}