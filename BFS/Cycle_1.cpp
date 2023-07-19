/*
학생들이(s1, s2, ..., sr)이라 할 때, r=1이고 s1이 s1을 선택하는 경우나, s1이 s2를 선택하고, s2가 s3를 선택하고,..., sr-1이 sr을 선택하고, sr이 s1을 선택하는 경우에만 한 팀이 될 수 있다.
- 첫째 줄에 테스트 케이스의 개수 T가 주어진다.
- 각 테스트 케이스의 첫 줄에는 학생의 수가 정수 n (2 ≤ n ≤ 100,000)으로 주어진다.
- 각 테스트 케이스의 둘째 줄에는 선택된 학생들의 번호가 주어진다. (모든 학생들은 1부터 n까지 번호가 부여된다.)
- 출력 : 프로젝트 팀에 속하지 못한 학생 수

TIP : 시작점과 끝점이 같아야.. (Cycle!) : 이전에 방문했던 학생을 다시 방문했다면 사이클에 포함된 학생.
*/

#include <bits/stdc++.h>
using namespace std;

int arr[100005];
int n;

bool isCycle(int idx){
    int cur = idx;
    for (int i=0; i<n; i++){ // 해당 인덱스가 이미 방문한 인덱스인 경우 -> true
        cur = arr[cur];
        if(cur == idx) return true;
    }
    return false;
}

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        cin >> n;
        for (int i=1; i<=n; i++)
            cin >> arr[i];
        int res = 0;
        for(int i = 1; i <= n; i++)
            if(!isCycle(i)) res ++;
        cout << res << '\n';
    }
    
}
