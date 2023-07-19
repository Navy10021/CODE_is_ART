/*
말은 격자판에서 체스의 나이트와 같은 이동방식을 가진다. 
x표시한 곳으로 말이 갈 수 있다는 뜻이다. 참고로 말은 장애물을 뛰어넘을 수 있다.
원숭이는 능력이 부족해서 총 K번만 위와 같이 움직일 수 있고, 그 외에는 그냥 인접한 칸으로만 움직일 수 있다. 
*/

#include <bits/stdc++.h>
using namespace std;


const int MX = 202;
int board[MX][MX];
int vis[32][MX][MX];

int org_dx[4]={0,0,1,-1};
int org_dy[4]={1,-1,0,0};
int dx[8]={2, 1, -1, -2, -2, -1, 1, 2};
int dy[8]={1, 2, 2, 1, -1, -2, -2, -1};
int K, Y, X; 
queue<tuple<int, int, int>> Q;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> K >> Y >> X;
    for (int i=0; i<X; i++)
        for (int j=0; j<Y; j++)
            cin >> board[i][j];
    Q.push({0,0,0});    // {나이트 이동가능 횟수, X, Y}
    vis[0][0][0] = 1;
    // BFS
    while (!Q.empty()){
        int cur_k, cur_x, cur_y;
        tie(cur_k, cur_x, cur_y) = Q.front();
        Q.pop();
        // 1.나이트 방식 이동(가능시)
        if (cur_k < K){
            for(int i=0; i<8; i++){
                int nx = cur_x + dx[i];
                int ny = cur_y + dy[i];
                if (nx<0 || nx>=X || ny<0 || ny>=Y) continue; // 바운더리 밖
                if (board[nx][ny]) continue; // 이동값 == 1 : 장애물
                if (vis[cur_k + 1][nx][ny]) continue; // 방문한 곳
                vis[cur_k + 1][nx][ny] = vis[cur_k][cur_x][cur_y] + 1;
                Q.push({cur_k + 1, nx, ny});
            }
        }
        // 2.상하좌우 이동(항시)
        for (int i=0; i<4; i++){
            int nx = cur_x + org_dx[i];
            int ny = cur_y + org_dy[i];
            if (nx<0 || nx>=X || ny<0 || ny>=Y) continue;
            if (board[nx][ny]) continue; // 이동값 == 1 : 장애물
            if (vis[cur_k][nx][ny]) continue;
            vis[cur_k][nx][ny] = vis[cur_k][cur_x][cur_y] + 1;
            Q.push({cur_k, nx, ny});
        }
    }
    
    int res=99999;
    for (int i; i < K + 1; i++)
        if (vis[i][X - 1][Y - 1])
            res = min(res, vis[i][X - 1][Y - 1]);
    if (res != 99999) cout << res - 1;
    else cout << -1;
}
