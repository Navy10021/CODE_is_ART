#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// string : char *arr
void MergeTwoArea(char arr[], int left, int mid, int right){
    int fIdx = left;
    int rIdx = mid + 1;
    int i;

    char * sortArr = (char *)malloc(sizeof(char) * (right + 1));
    int sIdx = left;

    while(fIdx <= mid && rIdx <= right){
        if(arr[fIdx] <= arr[rIdx])     // Your order condition
            sortArr[sIdx] = arr[fIdx++];
        else
            sortArr[sIdx] = arr[rIdx++];
    
        sIdx++;
    }
    if (fIdx > mid){
        for (i = rIdx; i <= right; i++, sIdx++){
            sortArr[sIdx] = arr[i];
        }
    }
    else{
        for (i = fIdx; i <= mid; i++, sIdx++){
            sortArr[sIdx] = arr[i];
        }
    }

    for (i = left; i<= right; i++){
        arr[i] = sortArr[i];
    }

    free(sortArr);
}

void MergeSort(char arr[], int left, int right){
    int mid;

    if (left < right){
        mid = (left + right) / 2;

        MergeSort(arr, left, mid);
        MergeSort(arr, mid + 1, right);

        MergeTwoArea(arr, left, mid, right);
    }
}

int main(void){
    char arr[100];
    scanf("%s", arr);
    int arrSize = strlen(arr);
    
    MergeSort(arr, 0, arrSize-1);

    for (int i = 0; i < arrSize; i++){
        printf("%c ", arr[i]);
    }

    return 0;
}