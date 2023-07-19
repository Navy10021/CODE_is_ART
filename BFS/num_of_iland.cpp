#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

int board[51][51]; // 1~50
bool vis[51][51];
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
int m, n, k; // row, col, number of 배추
queue <pair<int, int>> Q;

// BFS function
void bfs(int x, int y){
    // 초기값(x,y)
    vis[x][y] = true;
    Q.push({x,y});
    while(!Q.empty()){
        auto cur = Q.front(); Q.pop();
        for(int dir=0; dir<4; dir++){
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            // 예외
            if (nx < 0 || nx >= m || ny < 0 || ny >=n) continue;
            if (vis[nx][ny] || board[nx][ny] != 1) continue;
            vis[nx][ny] = true;
            Q.push({nx, ny});
        }
    }
}

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;    // 입력 개수
    cin >> t;
    while(t--){
        cin >> m >> n >> k;
        int x, y;
        for (int i=0; i<k; i++){
            cin >> x >> y;
            board[y][x]=1;
        }
        int res = 0; // 연결된 섬(1)의 개수
        for (int i=0; i<n; i++){
            for (int j=0; j<m; j++){
                if(board[i][j] == 1 && !vis[i][j]){  // BFS 시작점 
                    bfs(i,j);
                    res++;
                }
            }
        }
        cout << res << '\n';
        // board , vis 초기화
        for(int i; i<n; i++){
            fill(board[i], board[i]+m, 0);
            fill(vis[i], vis[i]+m, false);
        }
    }
    return 0;
}
