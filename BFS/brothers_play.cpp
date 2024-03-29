/*
수빈이는 동생과 숨바꼭질을 하고 있다. 수빈이는 현재 점 N(0 ≤ N ≤ 100,000)에 있고, 동생은 점 K(0 ≤ K ≤ 100,000)에 있다. 
수빈이는 걷거나 순간이동을 할 수 있다. 만약, 수빈이의 위치가 **X일 때 걷는다면 1초 후에 X-1 또는 X+1로 이동하게 된다.
순간이동을 하는 경우에는 1초 후에 2*X의 위치로 이동하게 된다.
수빈이와 동생의 위치가 주어졌을 때, 수빈이가 동생을 찾을 수 있는 가장 빠른 시간이 몇 초 후인지 구하는 프로그램을 작성하시오.
*/

#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
int dist[100002];

int n, k;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k;      // n : 수빈 위치 && k : brother 위치
    fill(dist, dist+100001, -1);
    // 최초위치
    dist[n] = 0;
    queue<int> Q;
    Q.push(n);
    
    while(dist[k] == -1){
        int cur = Q.front(); Q.pop();
        for (int nx : {cur-1, cur+1, cur*2}){
            if(nx < 0 || nx > 100000) continue; // 바운더리 밖
            if(dist[k] != -1) continue;         // 이미 방문
            dist[nx] = dist[cur] + 1;
            Q.push(nx);
        }
    }
    cout << dist[k];
}
