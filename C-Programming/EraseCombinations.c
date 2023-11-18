#include <stdio.h>
#include <string.h>

#define MAX_SIZE 10

char* removePos(char * str, int positions[], int numPos){
    int len = strlen(str);
    int i, j, k;

    for (i = 0, j = 0, k = 0; i < len; i++){
        if (k < numPos && i == positions[k]){   // 현재 인덱스가 삭제할 인덱스이면 k값 증가
            k++;
        }
        else{   // 삭제할 인덱스가 아니면 현재 Char keep!
            str[j++] = str[i];
        }
    }
    str[j] = '\0';  // string의 마지막을 NULL값으로 처리.
    return str;
}


void genCombinations(char * arr, int data[], int st, int en, int idx, int r){
    if (idx == r){
        // print all combinations
        char arrCopy[MAX_SIZE];
        strcpy(arrCopy, arr);           // string을 복사

        removePos(arrCopy, data, r);
        printf("%s \n", arrCopy);
        return;
    }
    // Recursion
    for (int i = st; i <= en && en - i + 1 >= r - idx; i++){ // arr 인덱스 Loop && arr 남은 원소 >= data 채울 원소
        data[idx] = i;      // data 배열 : 지울 인덱스를 저장
        genCombinations(arr, data, i + 1, en, idx + 1, r);
    }
}

void genAllCombinations(char * arr, int n){
    // Generate all possible combinations
    for (int r = 0; r <= n; r++){
        int data[r];
        genCombinations(arr, data, 0, n-1, 0, r);
    }
}


int main(){
    char arr[MAX_SIZE];
    printf("Enter your string : ");
    scanf("%s", arr);
    int n = strlen(arr);

    if (n > MAX_SIZE-1){
        printf("Error : Input string is too long.\n");
        return 1;
    }

    genAllCombinations(arr, n);

    return 0;
}
