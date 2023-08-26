#include <stdio.h>

void reverseArr(int arr[], int idx1, int idx2){
    while (idx1 < idx2){
        int temp = arr[idx1];
        arr[idx1] = arr[idx2];
        arr[idx2] = temp;
        idx1++;
        idx2--;
    }
}

int main(){
    int N, M;   // N array
    int index_a, index_b;
    scanf("%d %d", &N, &M);
    
    int arr[100];
    for (int i = 1; i <= N; i++){
        arr[i] = i;
    }

    while(M--){
        scanf("%d %d", &index_a, &index_b);
        if (index_a < 0 || index_a >= N || index_b < 0 || index_b >= N){
            printf("Invalid \n");
        }
        else{
            reverseArr(arr, index_a, index_b);
        }
    }

    for (int i = 1; i <= N; i++){
        printf("%d ", arr[i]);
    }
    return 0;
}
