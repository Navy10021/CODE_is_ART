// N개의 자연수(다른 수)와 자연수 M이 주어졌을 때 길이가 M인 수열 + 사전순으로 증가 + 같은 수 여러번 가능 
#include <bits/stdc++.h>
using namespace std;

int N, M;
int arr[10];
int num[10];

void func(int k){
    if (k == M){
        for(int i=0; i< M; i++)
            cout << num[arr[i]] << ' ';
        cout << '\n';
        return;
    }
    
    for (int i = 0; i < N; i++){
        arr[k] = i;
        func(k+1);
    }
}

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M;
    for (int i=0; i < N; i++) cin >> num[i];
    sort(num, num + N); // 정렬
    func(0);
}
