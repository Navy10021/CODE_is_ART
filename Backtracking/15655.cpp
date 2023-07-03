// N개의 자연수(다른 수)와 자연수 M이 주어졌을 때 길이가 M인 수열 + 오름차순!
#include <bits/stdc++.h>
using namespace std;

int N, M;
int arr[10];
bool is_used[10];
int num[10]; // 주어진 N개의 자연수를 받는 배열

void func(int k){ // 현재 k개의 수를 선택
    if (k == M){
        for(int i = 0; i < M; i++)
            cout << num[arr[i]] << ' ';  // arr에 대응되는 num 출력
        cout << '\n';
        return;
    }
    
    // k = 0일떄 시작점 = 0
    int st = 0;
    // k != 0 일떄 시작점 = arr[k-1] + 1 
    if (k != 0) st = arr[k-1] + 1;
    
    for (int i = st; i < N; i++){  // start ~ N-1
        if (!is_used[i]){
            arr[k] = i;
            is_used[i] = 1;
            func(k+1);
            is_used[i] = 0;
        }
    }
    
}

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M;
    for (int i=0; i<N; i++) cin >> num[i];
    sort(num, num + N); // 정렬
    func(0);
}



