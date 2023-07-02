#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

const int MX = 55;
int board[MX][MX];
int N, M;       // NxN, 치킨집 선택수 
vector<pair<int, int>> chicken; // 치킨 좌표 
vector<pair<int, int>> house;  // 집 좌표 

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M;
    
    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){
            cin >> board[i][j];
            // 집과 치킨집 좌표 넣기 
            if (board[i][j] == 1) house.push_back({i,j});
            if (board[i][j] == 2) chicken.push_back({i,j});
        }
    }
    // 1. 폐업시키지 않을 치킨집 M개 고르기 : 치킨집 A개 중에 M개 고르기 (조합)
    vector<int> brute(chicken.size(), 1);
    for (int i = 0; i < chicken.size(); ++i) brute.push_back(i < M ? 0 : 1);    // M칸 이전 0 M칸 이후 1 
    int res = 0x7f7f7f7f;
    do {
        // 2. 전체체치킨거리 구하기
        int dist = 0;   // 도시의 전체 치킨 거리 저장 변수 
        for (auto h : house){
            int tmp = 0x7f7f7f7f;   // 집~치킨집 거리 저장 변수
            for (int i = 0; i < chicken.size(); i++){
                if (brute[i] == 0) continue;
                // brute[i] == 1 인경우 거리값 구하기 & 갱신신
                tmp = min(tmp, abs(chicken[i].X - h.X) + abs(chicken[i].Y - h.Y)); 
            }
            dist += tmp;
        }
        res = min(res, dist);
    }while (next_permutation(brute.begin(), brute.end()));
    cout << res;
}
