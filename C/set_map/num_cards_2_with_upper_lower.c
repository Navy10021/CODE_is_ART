/*
lower_bound : 입력값 이상의 값이 처음 나오는 위치(index)
upper_bound : 입력값 초과의 값이 처음 나오는 위치(index)
count = upper_bound - lower_bound
-10 -10 2 3 3 6 7 10 10
*/
#include <stdio.h>
#include <stdlib.h>

// for qsort()
int compare(const void *a, const void *b){
    return (*(int *)a - *(int *)b);
}

// 이상.
int lowerBound(int cards[], int size, int tgt){
    int left = 0;
    int right = size;

    while(left < right){
        int mid = left + (right - left) / 2;

        if(cards[mid] < tgt){
            left = mid + 1;
        }
        else{
            right = mid;
        }
    }
    return left;
}

// 초과.
int upperBound(int cards[], int size, int tgt){
    int left = 0;
    int right = size;

    while(left < right){
        int mid = left + (right - left) / 2;

        if (cards[mid] <= tgt){
            left = mid + 1;
        }
        else {
            right = mid;
        }
    }
    return left;
}

int main(){
    int n, m;
    scanf("%d", &n);
    int *cards = (int *)malloc(n * sizeof(int));

    for (int i=0; i<n; i++){
        scanf("%d", &cards[i]);
    }
    // sorting
    qsort(cards, n, sizeof(int), compare);

    scanf("%d", &m);
    for (int i=0; i<m; i++){
        int num;
        scanf("%d", &num);

        // Find lower_bound && uppert_bound position
        int lower = lowerBound(cards, n, num);
        int upper = upperBound(cards, n, num);
        // count = upper - lower
        printf("%d ", upper-lower);
    }
    free(cards);
    return 0;
}
