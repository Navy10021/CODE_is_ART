#include <stdio.h>

void indertSort(int arr[], int n){
    for (int i=1; i<n; i++){
        int key = arr[i];
        int j = i-1;

        while (j >= 0 && arr[j] > key){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
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

    indertSort(arr, n);
    for(int i =0; i<n; i++){
        printf("%d ", arr[i]);
    }
}
