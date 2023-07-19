/*
그림에서 색이 있는 부분이 육지이고, 색이 없는 부분이 바다이다. 이 바다에 가장 짧은 다리를 놓아 두 대륙을 연결하고자 한다. 
가장 짧은 다리란, 다리가 격자에서 차지하는 칸의 수가 가장 작은 다리를 말한다. 
첫 줄에는 지도의 크기 N(100이하의 자연수)가 주어진다.
그 다음 N줄에는 N개의 숫자가 빈칸을 사이에 두고 주어지며, 0은 바다, 1은 육지를 나타낸다. 항상 두 개 이상의 섬이 있는 데이터만 입력으로 주어진다.
*/

#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

const int MX = 102;
// 섬 구분
int board[MX][MX];
int vis[MX][MX];
int n;
int cnt = 0;    // 각 섬의 번호를 의미
// 섬들 사이 거리
int dist[MX][MX];
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};

queue<pair<int, int>> Q;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;  // n x n
    for(int i=0; i < n; i++)
        for(int j=0; j < n; j++) cin >> board[i][j];
    
    // 섬 구분 표시
    for(int i=0; i < n; i++){
        for(int j=0; j<n; j++){
            if(board[i][j] == 0 || vis[i][j]) continue;
            //BFS
            cnt ++;
            vis[i][j] = 1;
            Q.push({i,j});
            while(!Q.empty()){
                auto cur = Q.front(); Q.pop();
                for (int dir=0; dir < 4; dir++){
                    int nx = cur.X + dx[dir]; 
                    int ny = cur.Y + dy[dir];
                    if (nx<0 || nx>=n || ny<0 || ny>=n) continue;
                    if (vis[nx][ny] || board[nx][ny]==0) continue;
                    board[nx][ny] = cnt;
                    vis[nx][ny] = 1;
                    Q.push({nx, ny});
                }
            }
        }
    }
    // 2. 각 섬으로 부터 최소 거리 구하기
    for(int i = 0; i < n; i++) fill(dist[i], dist[i]+n, -1); // dist -1로 초기화 

    int res = 999999;
    // 모든 섬의 육지 (i,j) 각각에 대해 BFS를 진행 -> board[i][j]와 board[nx][ny] 값이 다른 최초의 (nx,ny)를 찾으면 다리길이
    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            if(board[i][j] != 0){  // 육지인 경우 push
                Q.push({i,j});
                dist[i][j] = 0;    // 최초 거리 = 0
                bool escape = false;
                while (!Q.empty() && !escape){
                    auto cur = Q.front(); Q.pop();
                    for (int dir=0; dir<n; dir++){
                        int nx = cur.X + dx[dir];
                        int ny = cur.Y + dy[dir];
                        if (nx<0 || nx >= n || ny<0 || ny>=n) continue;
                        if (dist[nx][ny] >= 0 || board[i][j] == board[nx][ny]) continue;
                        if (board[nx][ny] != 0 && board[i][j] != board[nx][ny]){
                            res = min(res, dist[cur.X][cur.Y]);
                            while (!Q.empty()) Q.pop();
                            escape = true;
                            break;
                        }
                        dist[nx][ny] = dist[cur.X][cur.Y] + 1;
                        Q.push({nx, ny});
                    }
                }
                for (int i=0; i<n; i++)
                    fill(dist[i], dist[i]+n, -1);
            }
        }
    }
    cout << res;
    
}
