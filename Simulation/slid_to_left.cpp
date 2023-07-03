// slide to the left.
#include <iostream>
using namespace std;

void tiltld(){
    int arr[8] = {0,2,0,2,8,8,0,16};
    int tilted[8] = {};         // 좌로 밀어 넣는 공간
    int check[8] = {};          // 합쳐졌는지 여부 확인
    
    for (int i=0; i<8; i++){
        if (arr[i] == 0) continue;
        if (tilted[0] == 0){
            tilted[0] = arr[i];
            continue;
        }
        int idx = i;
        while (tilted[idx] == 0) idx--;             // 최초 빈칸 자리수로 찾아가기
        if (!check[idx] && tilted[idx] == arr[i]){  // 합쳐지지 않았고 && 현재 tilted 위치의 값과 arr 현재 arr 위치값이 같은 경우
            check[idx] = true;
            tilted[idx] *=2;
        }
        else tilted[idx + 1] = arr[i];
    }
    
    for (int j=0; j<8; j++){
        cout << tilted[j] << ' ';
    }
}

int main()
{
    tiltld();
}
