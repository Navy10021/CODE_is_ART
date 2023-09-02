/*
칸토어 집합은 0과 1사이의 실수로 이루어진 집합으로, 
구간 [0, 1]에서 시작해서 각 구간을 3등분하여 가운데 구간을 반복적으로 제외하는 방식으로 만든다.

1. "-"가 3^N개
2. 문자열 3등분, 가운데를 공백으로
3. 모든 선의 길이가 1일때까지 계속
즉, N번째 결과는 N-1번째 결과 2개를 이어 놓은 것과 동일
*/
#include<iostream>
#include<cmath>
using namespace std;

void canto(int n){
    int size = pow(3, n-1);

    // Base case
    if (n==0){
        cout << "-";
        return;
    }
    // canto(n) = canto(n-1) + 공백(size) + canto(n-1);
    canto(n-1);
    for (int i=0; i<size; i++){
        cout << " ";
    }
    canto(n-1);
}

int main(){
    int N;
    while(cin >> N){
        canto(N);
        cout << "\n";
    }
    return 0;
}
