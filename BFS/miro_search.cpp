/* 
미로에서 1은 이동할 수 있는 칸을 나타내고, 0은 이동할 수 없는 칸을 나타낸다. 이러한 미로가 주어졌을 때, 
(1, 1)에서 출발하여 (N, M)의 위치로 이동할 때 지나야 하는 최소의 칸 수를 구하는 프로그램을 작성하시오.

Tip : 시작점 -> 종착점 까지의 거리를 계산 → dist 배열에 저장 또한! 배열을 미리 int(-1)로 초기화해 두면 visited 배열을 두지 않아도 방문 확인 가능
*/
#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

string board[102];      // 각행을 string으로 받기
int dist[102][102];     // visited
int n, m;               // row, col
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;    // n rows && m cols
    // each row = string 
    for(int i=0; i<n; i++)
        cin >> board[i]; 
    // fill(start_iter, end_iter, fill value) && dist 배열을 -1로 초기화 -> -1 == !visted
    for(int i=0; i<n; i++) fill(dist[i], dist[i]+m, -1);
    queue<pair<int, int>> Q;
    Q.push({0,0});
    dist[0][0] = 0;
    
    while (!Q.empty()){
        auto cur = Q.front(); Q.pop();
        for(int dir=0; dir<4; dir++){
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if (nx<0 || nx>=n || ny<0 || ny>=m) continue;
            if (dist[nx][ny] >=0 || board[nx][ny] != '1') continue;
            // dist(visited)에 next 인접값+1  
            dist[nx][ny] = dist[cur.X][cur.Y] + 1;
            Q.push({nx, ny});
        }
    }
    cout << dist[n-1][m-1] + 1;
}
