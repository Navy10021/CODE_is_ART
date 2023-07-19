/*
체스판 위에 한 나이트가 놓여져 있다. 나이트가 한 번에 이동할 수 있는 칸은 아래 그림에 나와있다. 
나이트가 이동하려고 하는 칸이 주어진다. 나이트는 몇 번 움직이면 이 칸으로 이동할 수 있을까?

Tip : 나이트 이동 좌표 [dx = {2, 1, -1, -2, -2, -1, 1, 2}, dy = {1, 2, 2, 1, -1, -2, -2, -1}] 
TIP : BFS visited → 이동횟수 저장
*/

#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

int dist[305][305]; // 300 + 4 + 1 
int dx[8] = {2, 1, -1, -2, -2, -1, 1, 2};
int dy[8] = {1, 2, 2, 1, -1, -2, -2, -1};
int t, L, x, y, xx, yy; // test cases, L x L, (x, y) -> (xx, yy)
queue<pair<int, int>> Q;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> t;
    while (t--){
        cin >> L;
        for (int i=0; i<L; i++) fill(dist[i], dist[i]+L, -1); // dist에 이동값 저장 
        cin >> x >> y;
        dist[x][y] = 0; // 시작점 = 0
        Q.push({x,y});
        cin >> xx >> yy;
        while(!Q.empty()){
            auto cur = Q.front(); Q.pop();
            for (int dir = 0; dir < 8; dir++){
                int nx = cur.X + dx[dir];
                int ny = cur.Y + dy[dir];
                if (nx < 0 || nx >= L || ny < 0 || ny >= L) continue;
                if (dist[nx][ny] >= 0) continue;        // 이미 방문한 경우
                dist[nx][ny] = dist[cur.X][cur.Y] + 1;
                Q.push({nx, ny});
            }
        }
        cout << dist[xx][yy] << '\n';
    }
}
