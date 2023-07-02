#include <bits/stdc++.h>
using namespace std;

const int MX = 21;
int board_1[MX][MX];
int board_2[MX][MX];    // 결과 값을 저장하는 배열 
int N;                  // N x N

void rotate(){  // board_2(N x N)를 시계방향으로 90도 회전하는 함수
    int tmp[MX][MX];
    for (int i=0; i < N; i++)       // row
        for (int j=0; j < N; j++)   // col 
            tmp[i][j] = board_2[i][j];
    
    for (int i=0; i < N; i++)       // col 
        for (int j=0; j < N; j++)   // row
            board_1[i][j] = tmp[N-1-j][i];  // row-1-j
}

// 한쪽으로 밀어 넣어 합치는 함수 
void tilt(int dir){
    while (dir--) rotate();     // dir 만큼 회전 -> 1 : 90도 2 : 180도 3: 270도 ..
    
    for(int i = 0; i < N; i++){
        int tilted[MX] = {};        // board_2[i]를 왼쪽으로 기울인 결과를 저장할 변수 
        int idx = 0;
        for (int j = 0; j < N; j++){
            if (board_2[i][j] == 0) continue;   
            if (tilted[idx] == 0) tilted[idx] = board_2[i][j];  // 삽입할 위치가 비어 있는 경우
            else if (tilted[idx] == board_2[i][j]) tilted[idx++] *= 2;          // 같은 값이 충돌하는 경우
            else tilted[++idx] = board_2[i][j];
        }
        for (int j=0; j < N; j++) board_2[i][j] = tilted[j];    // 덮어 씀
    }
}

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N;
  for(int i = 0; i < N; i++)
    for(int j = 0; j < N; j++)
      cin >> board_1[i][j];
      
      int res = 0;
      for (int tmp = 0; tmp < (1<<(2*5)); tmp++){   // 최대 5번 이동해서 만들 수 있는 블록
            for (int i=0; i < N; i++)
                for (int j=0; j < N; j++)
                    board_2[i][j] = board_1[i][j];
            int brute = tmp;
            for (int i = 0; i < 5; i++){    // 최대 5번 
                int dir = brute % 4;        // 방향성 -> 1(90도) || 2(180도) || 3(270도) || 0 
                brute /= 4;
                tilt(dir);
            }
            for (int i=0; i<N; i++)
                for (int j=0; j<N; j++)
                    res = max(res, board_2[i][j]);
          
      }
      cout << res;
}
