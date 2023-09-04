#include <iostream>
#include <vector>

using namespace std;

// 구간 합을 저장할 배열
vector<int> prefixSum;

// 배열을 기반으로 구간 합을 미리 계산하는 함수
void calculatePrefixSum(const vector<int>& arr) {
    int n = arr.size();
    prefixSum.resize(n + 1, 0);

    for (int i = 0; i < n; ++i) {
        prefixSum[i + 1] = prefixSum[i] + arr[i];
    }
}

// 특정 구간의 합을 반환하는 함수
int getRangeSum(int left, int right) {
    if (left < 0 || right >= prefixSum.size() - 1 || left > right) {
        return 0; // 유효하지 않은 인덱스
    }

    return prefixSum[right + 1] - prefixSum[left];
}

int main() {
    // 배열을 초기화합니다.
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8, 9};

    // 구간 합을 미리 계산합니다.
    calculatePrefixSum(arr);

    // 구간 [left, right]의 합을 구합니다.
    int left = 2; // 시작 인덱스
    int right = 6; // 끝 인덱스
    int rangeSum = getRangeSum(left, right);

    cout << "구간 합 [" << left << ", " << right << "] = " << rangeSum << endl;

    return 0;
}
