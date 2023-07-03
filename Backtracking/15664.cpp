// N개의 자연수 중에 M개를 고르는 수열 + 중복되는 수열을 여러번 출력하면 안됨 + 비 내림차순 
#include <bits/stdc++.h>
using namespace std;

int N, M;
int arr[10];
int num[10];

void func(int k, int st){
    if (k == M){
        for(int i=0; i < M; i++)
            cout << arr[i] << ' ';
        cout << '\n';
        return;
        }
    
    int tmp = 0; // 중복 수열인지 체크하기 위한 임시변수
    for (int i = st; i < N; i++){
        if (tmp != num[i]){ // 이전 수열의 마지막 항과 새로운 수열의 마지막항이 같으면 중복 수열 
            arr[k] = num[i];
            tmp = arr[k];
            func(k + 1, i + 1);
        }
    }
}

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M;
    for (int i = 0; i < N; i++) cin >> num[i];
    sort(num, num+N);
    func(0,0);
}
