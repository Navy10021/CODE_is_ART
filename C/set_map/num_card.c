/*
N개의 카드를 가지고 있고, M개가 주어졌을 때 카드를 가지고 있는지 여부
*/
#include <stdio.h>
#include <stdlib.h>

// 0. Binary search function 
int binarySearch(int cards[], int size, int tgt){
    int left = 0;
    int right = size - 1;

    while(left <= right){
        int mid = left + (right - left) / 2;

        if (cards[mid] == tgt){
            return 1;   // target found
        }
        else if(cards[mid] < tgt){
            left = mid + 1;
        }
        else{
            right = mid - 1;
        }
    }
    return 0;   // target not found
}

int main(){
    int n, m;
    scanf("%d", &n);
    //int *cards = (int *)malloc(n * sizeof(int));
    int *cards = (int *)calloc(n, sizeof(int));

    for (int i = 0; i<n; i++){
        scanf("%d", &cards[i]);
    }
    // 1. N개의 카드 sorting(insertion sort)
    for (int i=1; i<n; i++){
        int key = cards[i];
        int j = i - 1;
        while (j >= 0 && cards[j] > key){
            cards[j+1] = cards[j];
            j--;
        }
        cards[j+1] = key;
    }
    // 2. M개의 카드 for문 -> Binary search
    scanf("%d", &m);

    for(int i=0; i<m; i++){
        int num;
        scanf("%d", &num);

        // 3. Binary search
        if (binarySearch(cards, n, num)){
            printf("1 ");
        }
        else{
            printf("0 ");
        }
    }
    //free(cards);
    return 0;
}
