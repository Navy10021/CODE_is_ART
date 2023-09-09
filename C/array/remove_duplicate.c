#include <stdio.h>


void remove_duplicate(int arr[], int *length){
    if (*length <= 1)
        return;

    int new_idx = 1;
    for (int i = 1; i < *length; i++){
        int flag = 0; // 중복여부 체크
        for (int j = 0; j < new_idx; j++){
            if (arr[i] == arr[j]){
                flag = 1;
                break;
            }
        }
        if (!flag){
            arr[new_idx] = arr[i];
            new_idx++;
        }
    }
    *length = new_idx;
}

int main(){
    int input[] = {3,9,2,8,5,9,2,8};
    int length = sizeof(input) / sizeof(input[0]);

    remove_duplicate(input, &length);   // 길이가 변경되므로 주소값으로 

    for (int i = 0; i < length; i++){
        printf("%d ", input[i]);
    }
}
