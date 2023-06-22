#include <bits/stdc++.h>
using namespace std;


int arr[100005];
int state[100005];
int N;

const int not_visited = 0;
const int in_cycle = -1;

void run(int x){
    int cur = x;
    while (true){
        state[cur] = x; // 임의의 시작 학생값(1)을 넣음. 
        cur = arr[cur];
    // 1.이번 방문(cur)에서 지나간 학생(x)에 도달했을 경우 : 사이클 표시
    if (state[cur] == x){
        while(state[cur] != in_cycle){
            state[cur] = in_cycle;
            cur = arr[cur];
        }
        return;
    }
    // 2.이전 방문 지나간 학생에 도달했을 경우
    else if(state[cur] != 0) return;
  }
}

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        cin >> N;
        fill(state+1, state+(N+1), 0);
        for (int i=1; i <= N; i++)
            cin >> arr[i];
        // 최초 방문인 경우 run!
        for (int i=1; i<=N; i++){
            if(state[i] == not_visited) run(i);
        }
        // 사이클에 미포함된 인원수 카운트
        int res = 0;
        for (int i=1; i<=N; i++){
            if (state[i] != in_cycle) res++;
        }
        cout << res << '\n';
    }
}



