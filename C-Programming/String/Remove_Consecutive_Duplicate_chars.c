#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void removeConsecutiveDuplicates(char * str){
    int len = strlen(str);

    if (len <= 1){
        return;     // No duplicate
    }

    int idx = 0;    // Index for the non-duplicate characters

    for (int i = 0; i < len; i++){
        if (i == len - 1 || str[i] != str[i+1]){
            str[idx++] = str[i];
        }
    }
    str[idx] = '\0';
}

// Custom function to convert an integer to a string
void intToStr(int num, char * str){
    int i = 0;
    while (num != 0){
        str[i++] = '0' + num % 10;
        num /= 10;
    }
    // Reverse string
    int st = 0;
    int en = i - 1;
    while(st < en){
        char temp = str[st];
        str[st] = str[en];
        str[en] = temp;
        st++;
        en--;
    }
    str[i] = '\0';
}

void compress(char * str){
    int len = strlen(str);

    if (len <= 1){
        return;
    }
    int count = 1;
    int idx = 0;
    for (int i = 1; i <= len; i++){
        if (i < len && str[i] == str[i-1]){
            count++;
        }
        else{
            str[idx++] = str[i-1];
            if (count > 1){
                //int digits = snprintf(NULL, 0, "%d", count);
                //char countStr[digits + 1];
                //sprintf(countStr, "%d", count);
                char countStr[10];
                intToStr(count, countStr);  // int count -> char[] countStr
                int strLen = strlen(countStr);
                for (int j = 0; j < strLen; j++){
                    str[idx++] = countStr[j];
                }
                count = 1;  // Reset;
            }
        }
    }
    str[idx] = '\0';
}

int main(void){
    char inputStr[20];
    scanf("%s", inputStr);

    printf("Original string : %s\n", inputStr);
    //removeConsecutiveDuplicates(inputStr);
    compress(inputStr);
    printf("Modified string : %s\n", inputStr);

    return 0;
}
