#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int isPalindrome(char * str){
    int r = 0;
    int l = strlen(str) - 1;

    while(r < l){
        if (str[r] != str[l])
            return 0;
        else{
            r++;
            l--;
        }
    }
    return 1;
}


void erasePositions(char *str, int *positions, int size){
    int len = strlen(str);
    int eraseCount = 0;

    for (int i = 0; i < len; i++){
        if (eraseCount < size && i == positions[(size - 1) - eraseCount]){ // 역순정렬인 경우로 수정
            eraseCount++;   // Skip
        }
        else{
            str[i - eraseCount] = str[i];
        }
    }
    str[len - eraseCount] = '\0';
}

void genCombination(char *str, int *buffer, int start, int depth, int size) {
    int len = strlen(str);

    if (depth == 0) {            // 해당 조합의 길이(depth)와 일치하면 return
        char copyStr[size + 1];  // Copy
        strcpy(copyStr, str);
        printf("The number of erase : %d || positions ", size);
        for (int j = 0; j < size; j++){
            printf("%d ", buffer[j]);
        }
        printf(" || ");
        erasePositions(copyStr, buffer, size);  // 각 위치별 삭제
        printf("%s\n", copyStr);
        
        if (isPalindrome(copyStr)){
            printf("The longest palindrome is : %s\n", copyStr);
            exit(1);    // 함수 종료!
        }
        return;        
    }
    for (int i = start; i < len; i++) {
        buffer[depth - 1] = i; // 해당 문자열의 인덱스를 array(buffer)에 저장
        genCombination(str, buffer, i + 1, depth - 1, size);
    }
}

int main(void) {
    char inputStr[] = "nannaa";
    int length = strlen(inputStr);

    for (int depth = 0; depth <= length; depth++) { // 1 ~ length까지 모든 길이의 조합 생성
        int combinationArr[depth];                  // 조합의 인덱스를 저장할 Array 생성.
        genCombination(inputStr, combinationArr, 0, depth, depth);
    }
    return 0;
}