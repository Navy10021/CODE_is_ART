#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool isPalindrome(const char* str){
    int left = 0;
    int right = strlen(str) - 1;

    while (left < right){
        if (str[left] != str[right])
            return false;
        left++;
        right--;
    }
    return true;
}


int main(){
    char str[100] = "abcdefedcb";
    char max_palin[100] = "";      // 초기화
    int len = strlen(str);
    int max_length = 0;
    // print all substring
    /*
    for (int st = 0; st < len; st++){      // 시작점
        for (int en = st; en < len; en++){ // 끝 점
            char subStr[100];
            for (int k = st; k <= en; k++){
                subStr[k - st] = str[k];
            }
            subStr[en - st + 1] = '\0';
            printf("%s\n", subStr);
        }
    }
    */
   // print all substring
   for (int st = 0; st < len; st++){
    for (int length = 1; length <= len - st; length++){
        char subStr[length + 1];  // for terminate '\0'
        strncpy(subStr, str + st, length);
        subStr[length] = '\0';  
        
        if(isPalindrome(subStr) && max_length < strlen(subStr)){
            max_length = strlen(subStr);
            strcpy(max_palin, subStr);  // Copy the palindrome into max_palin
            }
        }
   }
   printf("Max palindrome in string : %s", max_palin);

}
