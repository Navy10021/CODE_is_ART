#include <bits/stdc++.h>
using namespace std;

# define X first
# define Y second

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};        // 남 - 동 -북 - 서
int N, M;            // 서로 x 가로
int board_1[10][10]; // 최초 입력 받은 board를 저장할 변수
int board_2[10][10]; // 사각지대 개수를 저장할 변수
vector<pair<int, int>> CCTV; // cctv 좌표 

// out of boudary
bool OOB(int i, int j){
    return i < 0 || i >= N || j < 0 || j >= N;
}

// (i, j) 에서 dir 방향으로 진행 -> 벽(6)을 만날 때까지 지나친 빈칸(0)을 (9)변경
void move(int x, int y, int dir){
    dir %= 4;       // 우-상-좌-하
    while (1){
        x += dx[dir];
        y += dy[dir];
        if (OOB(x, y) || board_2[x][y] == 6) return;    // OOB or 벽(6)을 만나면 함수 탈출
        if (board_2[x][y] != 0) continue;               // 빈칸(0)이 아니면 continue
        board_2[x][y] = 9;
    }
}

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M;
    int res = 0;    // 사각지대 최소 크기
    for (int i = 0; i < N; i++){
        for (int j = 0; j < M; j++){
            cin >> board_1[i][j];
            // cctv 좌표 넣기 : 빈칸(0)이 아니고, 벽도(6) 아닌 경우
            if (board_1[i][j] != 0 && board_1[i][j] != 6) CCTV.push_back({i, j});
            // cctv가 없는 경우 비교를 위해 res 값 채우기
            if (board_1[i][j] == 0) res ++;
        }
    }
    // temp를 4진법(0 1 0 1)으로 두고, 각 자리 수를 cctv 방향으로 생각
    for (int tmp = 0; tmp < (1<<(2*CCTV.size())); tmp++){        // 전체 CCTV 개수를 돌면서, k개 cctv -> 1<<2(*CCTV.size())-1 : (4의 k승) - 1 
        for (int i = 0; i < N; i++){                             // 전체 빈칸을 돌면서,
            for (int j = 0 ; j < M; j++){
                board_2[i][j] = board_1[i][j];
            }
        }
        int brute = tmp;
        for (int i = 0; i < CCTV.size(); i++){
            int dir = brute % 4;                                // 나머지값이 i번째 cctv 방향(direction) 
            brute /= 4;
            int x = CCTV[i].X;
            int y = CCTV[i].Y;
            if (board_1[x][y] == 1){
                move(x, y, dir);    // 남 
            }
            else if (board_1[x][y] == 2){
                move(x, y, dir);    // 남 - 북
                move(x, y, dir+2);  // 
            }
            else if (board_1[x][y] == 3){
                move(x, y, dir);    // 남 - 동
                move(x, y, dir+1);  // 
            }
            else if (board_1[x][y] == 4){
                move(x, y, dir);    // 남 - 동 -북
                move(x, y, dir+1);   
                move(x, y, dir+2);  
            }
            else{
                move(x, y, dir);     // 남 - 동 - 북 - 서
                move(x, y, dir+1); 
                move(x, y, dir+2); 
                move(x, y, dir+3); 
            }
        }
        int val = 0;
        for(int i = 0; i < N; i++)
            for(int j = 0; j < M; j++)
                val += (board_2[i][j] == 0);
        res = min(res, val);        // cctv가 없는 경우와 비교하여 최소값 
    }
    cout << res;
}
