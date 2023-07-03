// N개의 중복된 자연수 중에 M개를 고르는 수열 + 중복되는 수열을 여러번 출력하면 안됨
#include <bits/stdc++.h>
using namespace std;

int N, M;
int arr[10];
bool is_used[10];
int num[10];

void func(int k){
    if (k == M){
        for(int i=0; i < M; i++)
            cout << arr[i] << ' ';
        cout << '\n';
        return;
        }
    
    int tmp = 0; // 중복 수열인지 체크하기 위한 임시변수
    
    for (int i = 0 ; i < N; i++){
        if (!is_used[i] && tmp != num[i]){ // 이전 수열의 마지막 항과 새로운 수열의 마지막항이 같으면 중복 수열 
            is_used[i] = 1;
            arr[k] = num[i];
            tmp = arr[k];
            func(k + 1);
            is_used[i] = 0;
        }
    }
}

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M;
    for (int i = 0; i < N; i++) cin >> num[i];
    sort(num, num+N);
    func(0);
}

