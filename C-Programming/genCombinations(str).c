#include <stdio.h>
#include <string.h>

void genCombinations(char * arr, int data[], int st, int en, int idx, int r){
    if (idx == r){
        // print all combinations
        for (int i = 0; i < r; i++){
            printf("%c ", data[i]);
        }
        printf("\n");
        return;
    }
    // Recursion
    for (int i = st; i <= en && en - i + 1 >= r - idx; i++){ // arr 인덱스 Loop && arr 남은 원소 >= data 채울 원소
        data[idx] = arr[i];
        genCombinations(arr, data, i + 1, en, idx + 1, r);
    }
}

void genAllCombinations(char * arr, int n, int r){
    if (r > n){
        printf("Invalid input");
        return;
    }
    int data[r];

    // Generate Combinations
    genCombinations(arr, data, 0, n - 1, 0, r);
}


int main(){
    char arr[] = "ABCD";
    int n = strlen(arr);
    for (int r = 0; r < n; r++){
        genAllCombinations(arr, n, r);
    }
    return 0;
}
