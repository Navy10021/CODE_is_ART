/*
불에 대한 BFS와 지훈이에 대한 BFS를 모두 돌려서 해결!
불에 대한 BFS(dist1) → 각 칸에 불이 전파되는 시간 계산
지훈이에 대한 BFS(dist2) → vis[nx][ny] == true or dist[nx][ny] ≥0 continue + (추가) 불이 붙은 시간을 확인해서 필요에 따라 continue
*/

#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

string board[1002];
int dist1[1002][1002]; // 불의 전파시간
int dist2[1002][1002]; // 사람의 이동시간
int n, m; // row, col
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    // visited 공간을 -1로 채우기
    cin >> n >> m;
    for(int i=0; i<n; i++){
        fill(dist1[i], dist1[i]+m, -1);
        fill(dist2[i], dist2[i]+m, -1);
    }
    // rows
    for(int i=0; i<n; i++) cin >> board[i];
    
    queue<pair<int,int>> Q1;
    queue<pair<int,int>> Q2;
    // 시작점 {i,j}에 대해
    for(int i=0; i<n; i++){         // rows
        for(int j=0; j<m; j++){     // cols
            // 1.불이난 공간 시작점 
            if (board[i][j] == 'F'){
                Q1.push({i,j});
                dist1[i][j] = 0;
            }
            // 2.사람 공간 시작점 
            if (board[i][j] == 'J'){
                Q2.push({i,j});
                dist2[i][j] = 0;
            }
        }
    }
    // 1. 불(F)에 대한 BFS
    while(!Q1.empty()){
        auto cur = Q1.front(); Q1.pop();
        for(int dir=0; dir<4; dir++){
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if(nx<0 || nx>=n || ny<0 || ny>=m) continue;
            if(dist1[nx][ny]>=0 || board[nx][ny] == '#') continue;
            dist1[nx][ny] = dist1[cur.X][cur.Y] + 1;
            Q1.push({nx,ny});
        }
    }
    
    // 2. 사람(J)에 대한 BFS
    while(!Q2.empty()){
        auto cur = Q2.front(); Q2.pop();
        for(int dir=0; dir<4; dir++){
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            // 범위를 벗어남 -> 탈출 성공 해당 시간을 리턴
            if(nx<0 || nx>=n || ny<0 || ny>=m) {
                cout << dist2[cur.X][cur.Y] + 1;
                return 0;  // break
            }
            if(dist2[nx][ny] >=0 || board[nx][ny] == '#') continue;
            // 불이 번진 시간과 같거나 느린경우
            if(dist1[nx][ny] != -1 && dist1[nx][ny] <= dist2[cur.X][cur.Y] + 1) continue;
            dist2[nx][ny] = dist2[cur.X][cur.Y] + 1;
            Q2.push({nx,ny});
        }
    }
    // 마지막에 도달했다는 것은 탈출실패!
    cout << "Impossible !";
}
