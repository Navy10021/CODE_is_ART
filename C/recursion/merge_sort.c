#include <stdio.h>

int N, K, cnt;
int A[50000];
int trr[50000];
int ans;

void mergeSort(int s, int e){
    // 0. Base case
    if (s >= e) return;
    // 1. Divide & Conqure
    int mid = (s+e) / 2;
    mergeSort(s, mid);
    mergeSort(mid+1, e);

    if (cnt >= K) return;

    // 2. Merge
    int i = s;
    int j = mid+1;
    int k = s;

    while (i <= mid && j <= e)
    {
        if(A[i] <= A[j]) trr[k++] = A[i++];
        else trr[k++] = A[j++];
    }
    while (i <= mid) trr[k++] = A[i++];
    while (j <= e) trr[k++] = A[j++];

    for (i = s; i <= e; i++){
        A[i] = trr[i];
        if (++cnt == K){
            ans = A[i];
            break;
        }
    }
}

int main(){
    ans = 0;
    scanf("%d %d", &N, &K);
    for (int i=1; i<=N; i++){
        scanf("%d", A+i);
    }

    mergeSort(1, N);
    if (cnt <K) printf("-1\n");
    else printf("%d\n", ans);
}
