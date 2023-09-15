#include <stdio.h>
#include <stdlib.h>

/*
x를 기준으로 정렬, x가 같은경우 y를 기준으로 정렬
*/
typedef struct{
    int x;
    int y;
} coord;

int compare(const void *first, const void *second){
    coord A = *(coord *) first;
    coord B = *(coord *) second;
    if(A.x > B.x)
        return 1;
    else if (A.x == B.x){
        if (A.x > B.y)
            return 1;
        else
            return -1;
    }
    return -1;
}

int main(){
    int N;
    scanf("%d", &N);
    coord *arr = (coord *) calloc(N, sizeof(coord));
    //coord arr[N];
    for (int i=0; i<N; i++){
        scanf("%d %d", &arr[i].x, &arr[i].y);
    }
    qsort(arr, N, sizeof(coord), compare);

    printf("====Sorted====\n");
    for (int i=0; i<N; i++){
        printf("%d %d\n", arr[i].x, arr[i].y);
    }
}
