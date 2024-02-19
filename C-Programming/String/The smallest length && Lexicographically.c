#include <stdio.h>
#include <string.h>

int main(void){
    char* strings[] = {"abcd", "apple", "abc", "ac", "ab", "ad", "cd"};
    int n = sizeof(strings) / sizeof(strings[0]);
    
    // Initialize
    char * smallest = strings[0];
    int small_len = strlen(strings[0]);
    
    for (int i = 1; i < n; i++){
        int curr_len = strlen(strings[i]);
        // case 1. update smallest length & smallest
        if (curr_len < small_len){
            smallest = strings[i];
            small_len = curr_len;
        }
        // case 2. update Lexicographically smallest 
        else if (curr_len == small_len && strcmp(strings[i], smallest) < 0){
            smallest = strings[i];
        }
    }
    
    printf("The smallest string : %s\n", smallest);
    
    return 0;
}