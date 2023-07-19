/*
그림(섬)
1. 상하좌우로 연결된 그림의 크기(area)를 알아내기 → while 문 안에서 pop이 이뤄질 때마다 area ++;
2. 도화지에 있는 모든 그림을 찾아 내기 → 이중 for문으로 각 칸이 **BFS의 시작점이 될 수 있는지 체크(num++)**하면 모든 그램을 찾아 낼 수 있음.
*/

#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

int board[502][502]; // 0:색칠 false && 1:색칠 true
bool vis[502][502];     // visited
int n, m;               // row, col
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m; // rows , cols
    // Board 값 넣기
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin >> board[i][j];
            
    int mx = 0;     // 그림의 최대값
    int num = 0;    // 그림 수
    
    // 1. 이중 for문을 통해 모든 시작점(i, j)을 확인
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            // 시작점(i,j)가 색칠이 안되어 있는 상황(0) || 이미 visited 한 상황(vis == 1) 
            if(board[i][j] == 0 || vis[i][j]) continue; 
            // (i, j)는 시작점
            num++; // 그림수 +=1
            // 2. (i,j)에서 BFS 준비
            queue<pair<int,int>> Q;
            vis[i][j] = 1;          // 시작점 방문표시
            Q.push({i,j});          // 시작점 Q.push
            int area = 0;           // 그림 넓이
            // 3. BFS를 통해 그림의 크기 구하기
            while(!Q.empty()){
                area++;             // 큐의 원소를 하나씩 뺄때마다 넓이를 1 증가시킨다!
                pair<int,int> cur = Q.front(); 
                Q.pop();
                //area++;  
                for(int dir=0; dir<4; dir++){
                    int nx = cur.X + dx[dir];
                    int ny = cur.Y + dy[dir];
                    // 예외 : 범위를 넘어가는 경우 || 방문한 곳 || 색칠이 안된곳
                    if (nx<0 || ny<0 || nx>=n || ny>=m) continue;
                    if (vis[nx][ny] || board[nx][ny] != 1) continue;
                    // 방문 표시 
                    vis[nx][ny] = 1;
                    // 큐에 넣기 
                    Q.push({nx, ny});
                }
            } // (i,j) 시작하는 BFS 종료 최대값 업데이트 
            mx = max(mx, area);
        }
    }
    cout << "Number of paints : " << num << '\n' << "The biggest paint : " << mx; 
}
