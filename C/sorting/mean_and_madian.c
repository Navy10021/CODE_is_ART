#include <stdio.h>
#include <stdlib.h>

// 평균과 중앙값을 구하는 코드

// Function to compare values for qsort(함수)
int compare(const void *a, const void *b){
    return (*(int *)a - *(int *)b);
}

double median(int arr[], int n){
    // Sorting the array in ascending order
    qsort(arr, n, sizeof(int), compare);

    // 짝수면, 2개의 중앙값의 평균
    if (n%2==0){
        int mid_1 = arr[(n-1) / 2];
        int mid_2 = arr[n / 2];
        return (double)(mid_1+mid_2) / 2.0;
    }
    else{
        return (double)arr[n/2];
    }
}

double mean(int arr[], int n){
    double sum = 0;
    for (int i = 0; i < n; i++){
        sum += arr[i];
    }
    return sum / n;
}

int main(){
    int num;
    int arr[5];
    for (int i = 0; i<5; i++){
        scanf("%d", &num);
        arr[i] = num;
    }
    printf("MEAN : %f \n", mean(arr, 5));
    printf("MEDIEAN : %f \n", median(arr, 5));
}
