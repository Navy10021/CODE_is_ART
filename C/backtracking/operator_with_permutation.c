/*
N개의 수와 N-1개의 연산자가 주어졌을때 식의 결과가 최대 && 최소
연산자 우선순위 무시하고 앞에서 부터 진행.
연산자 배치 방법 : 같은것이 포함된 순열
ex ) ++- / +-+ / -++ 
*/
#include <stdio.h>

int N, min = 10000, max = -10000;
int arr[101];
int op[101];
int index = 1;

// 연산자 배열
void insert(int val, int count){
    for (int i = 0; i < count; i++){
        op[index++] = val;
    }
}

void swap(int a, int b){
    int temp = op[a];
    op[a] = op[b];
    op[b] = temp;
}

// 주어진 식 연산
void calculate(){
    int sum = arr[1];
    for (int i=1; i<N; i++){    // N-1개의 연산자
        switch (op[i])          
        {
        case 1:
            sum += arr[i+1];
            break;
        case 2:
            sum -= arr[i+1];
            break;
        case 3:
            sum *= arr[i+1];
            break;
        case 4:
            sum /= arr[i+1];
            break;
        }
    }
    if (sum > max)
        max = sum;
    if (sum < min)
        min = sum;
}

// 중복을 허용한 Permutation
void permutation(int start){
    if (start == N-1){  // 연산자 개수가 맞으면, 계산 진행
        calculate();
    }
    for (int i=start; i<N; i++){
        if (i != start && op[i] == op[start])
            continue;
        swap(i, start);
        permutation(start+1);
        swap(i, start);
    }
}

int main(){
    scanf("%d", &N);
    for (int i=1; i<=N; i++){
        scanf("%d", &arr[i]);
    }
    int temp;
    for (int i=1; i<=4; i++){
        scanf("%d", &temp);
        if (temp != 0){
            insert(i, temp);
        }
    }
    permutation(1);

    printf("%d %d\n", max, min);

    return 0;
}
