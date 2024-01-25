#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// LeetCode 564 : Find the Closest Palindrome 
int is_palindrome(char *str){
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

void closest_palindrome(char *num){
    int asc_num, desc_num;
    char asc_str[20];
    char desc_str[20];
    
    for(int i = 1; i < 10000; i++){
        asc_num = atoi(num) + i;
        desc_num = atoi(num) - i;
        sprintf(asc_str, "%d", asc_num);
        sprintf(desc_str, "%d", desc_num);
        if (is_palindrome(desc_str)){
            printf("%s\n", desc_str);
            break;
        }
        else if (is_palindrome(asc_str)){
            printf("%s\n", asc_str);
            break;
        }
    }
}

int main()
{
    char input[20];
    scanf("%s", input);
    closest_palindrome(input);

    return 0;
}
