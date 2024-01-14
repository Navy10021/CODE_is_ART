#include<stdio.h>
#include<string.h>
#include<stdlib.h>

// 443. String Compression : If group's length is 1, append the characters to s. Otherwise, append character to s + lengths

void compress(char* str){
    int count = 1;
    char * newStr = (char*)malloc(sizeof(char) * (strlen(str) + 1));
    int index = 0;

    for(int i = 0; i < strlen(str) - 1; i++){
        // 1. Check Consecutive character same or not
        if (str[i] != str[i+1]){
            // Single Character case
            if (count == 1){
                newStr[index++] = str[i];
            }
            else{
                // Muliple consecutive character case
                newStr[index++] = str[i];
                // Count값을 newStr + index 만큼 "%d" 저장하고, 인덱스에 추가
                index += sprintf(newStr + index, "%d", count); // sprintf(char *str, const char *format, ..);
                count = 1;
            }
        }
        else{
            count++;
        }
    }
    // Handle the last character
    if (count == 1){
        newStr[index++] = str[strlen(str) - 1];
    }
    else{
        newStr[index++] = str[strlen(str) - 1];
        index += sprintf(newStr + index, "%d", count);
    }

    newStr[index] = '\0';

    printf("Compressed String : %s\n", newStr);
    printf("Compressed length : %d", strlen(newStr));
    free(newStr);
}

int main(void){
    char input[] = "abbbbbbbbbbbbbccc";
    compress(input);

    return 0;
}
