#include<stdio.h>
#include<string.h>
#include<stdlib.h>

// 연속된 같은 문자를 카운트해서 압축하는 함수
// 443. String Compression : If group's length is 1, append the characters to s. Otherwise, append character to s + lengths
/*
**`sprintf`** 함수는 지정된 버퍼에 문자열을 저장하면서 동시에 저장된 문자열의 길이를 반환합니다. 이 길이에는 널 종료 문자('\0')가 포함되지 않습니다.

예를 들어, **`sprintf`** 함수를 사용하여 정수와 문자열을 버퍼에 저장하는 경우, 예를 들어 **`sprintf(buffer, "%d %s", 123, "abc");`**, 함수는 "123 abc" 라는 문자열을 **`buffer`**에 저장하고, 이 문자열의 길이인 7을 반환합니다. 이는 "123 abc"의 문자 개수와 같으며, 널 종료 문자는 이 길이에 포함되지 않습니다.
*/
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
