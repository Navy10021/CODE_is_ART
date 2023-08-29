#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 길이순 -> 알파벳순 
typedef struct{
    int age, order;
    char name[55];
} People;


int compare(const void* first, const void* second){
    People *A = (People*)first;
    People *B = (People*)second;

    if (A->age < B->age)    // 오름차순
        return -1;
    else if (A->age > B->age)
        return 1;
    else if (A->age == B->age){
        if (A->order < B->order)
            return -1;
        else   
            return 1;
    }
    return 0;
}

int main(){
    int N;
    scanf("%d", &N);
    People* arr = (People *)calloc(N+1, sizeof(People));
    // Word arr[N];

    for (int i=0; i<N; i++){
        scanf("%d %s", &arr[i].age, arr[i].name);
        arr[i].order = i;
    }
    // 정렬 
    qsort(arr, N, sizeof(arr[0]), compare);
    
    printf("===== Sorted =====\n");
    for(int i=0; i<N; i++){
        printf("%d %s\n", arr[i].age, arr[i].name);
    }
}
