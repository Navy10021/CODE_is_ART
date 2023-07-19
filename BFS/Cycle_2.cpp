/*
그 학생에서 출발해 다시 한번 다음학색으로 이동하되, 이번에는 지금 방문하는 학생들이 전부 사이클에 포함되는 학생이라는 표시를 남기면

임의의 학생(X)에서 시작해 다음 학생으로 계속 이동할 때

1. 사이클에 포함된 학생 or 사이클에 포함되지 않은 학생을 재방문시 X는 사이클에 포함되지 않은 학생. 지금까지 방문한 학생을 사이클에 포함되지 않은 학생으로 분류한다.
2. X가 아닌 다른 방문한 학생이 Y를 재방문한 경우 X는 사이클에 포함되지 않고 Y는 사이클에 포함되어 있다. 즉, Y에서 출발해 이동/다시 Y에 도착할 때 까지 만나는 학생들을 사이클에 포함된 학생, X에서 출발해 Y에 도달할때까지 만나는 학생들은 싸이클 미포함.
3. X를 재방문한 경우 X는 사이클에 포함된 학생. X에서 출발해 이동하며 다시 X에 도달할 때까지 만난 학생들을 사이클에 포함된 학생으로 표시.
*/
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
