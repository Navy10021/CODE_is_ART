#include <stdio.h>

int findMin(int arr[], int lenght){
    int hash[lenght + 1];
    // 초기화
    for (int i = 0; i < lenght; i++){
        hash[i] = 0;
    }
    // 해당 정수가 있으면 true로 변경
    for (int i = 0; i < lenght; i++){
        if (arr[i] > 0 && arr[i] <= lenght){
            hash[arr[i]] = 1;
        }
    }

    // 첫번째 원소 찾기
    for (int i = 1; i <= lenght; i++){
        if (hash[i] == 0)
            return i;
    }
    return lenght + 1;
}

int main(){
    int input[] = {3, 4, -1, 1};
    int length = sizeof(input) / sizeof(input[0]);

    int res = findMin(input, length);
    printf("The minimum positive int : %d", res);
}
