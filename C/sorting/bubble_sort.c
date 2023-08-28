#include <stdio.h>

void bubbleSort(int arr[], int n){
    for (int i=0; i<n-1; i++){
        for (int j=0; j<n-i-1; j++){
            if(arr[j] > arr[j+1]){
                // swap
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

int main() {
    int N, num;
    int idx = 0;
    scanf("%d", &N);
    int arr[N];
    int n = sizeof(arr) / sizeof(arr[0]);
    while(N--){
        scanf("%d", &num);
        arr[idx] = num;
        idx++;
    }

    bubbleSort(arr, n);
    for(int i =0; i<n; i++){
        printf("%d ", arr[i]);
    }
}
