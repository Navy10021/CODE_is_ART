#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <cmath>
using namespace std;
/*
1. 산술평균 : N개의 수의 합을 N으로 나눈 값.
2. 중앙값 : N개의 수들을 증가하는 순서로 나열했을 경우 그 중앙에 위치하는 값
3. 최빈값 : N개의 수들 중 가장 많이 나타나는 값
4. 범위 : N개의 수들 중 최댓값과 최솟값의 차이
*/

int main(){
    int N;
    cin >> N;

    vector<int> numbers(N); // vector size == N
    map<int, int> freq;     // <int, frequency>
    int sum = 0;
    for (int i=0; i<N; i++){
        cin >> numbers[i];
        sum += numbers[i];
        freq[numbers[i]]++; // value++
    }

    // 1. 산술평균 
    double mean = static_cast<double>(sum) / N;
    int rounded_mean = round(mean);

    // 2. 중앙값(numbers.size = 홀수)
    sort(numbers.begin(), numbers.end());
    int median = numbers[N/2];

    // 3. 최빈값
    int curr = numbers[0];
    int max_freq = 1;

    for (const auto& pair : freq){
        if(pair.second > max_freq){
            max_freq = pair.second;
            curr = pair.first;      // 최빈값 수로 업데이트
        }
    }

    // 최빈값이 여러개인 경우 두번째로 작은 값.
    int cnt = 0;
    for (const auto& pair : freq){
        if(pair.second == max_freq)
            cnt++;
    }
    if (cnt > 1){
        int second = numbers[0];
        int second_max_freq = 0;
        for (const auto& pair : freq){
            if (pair.second == max_freq && pair.first != curr){
                second = pair.first;
                curr = second;
                break;
            }
        }
    }

    // 4. 범위 구하기(이미 정렬되어 있으므로)
    int range = numbers[N-1] - numbers[0];

    // 결 과
    // 소수점 두 자리까지 출력
    //cout << fixed;
    //cout.precision(2); 

    cout << rounded_mean << "\n";
    cout << median << "\n";
    cout << curr << "\n";
    cout << range << "\n";

}
