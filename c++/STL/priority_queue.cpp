/*
- Priority-Queue : 모든 원소 중에서 가장 큰 값이 Top을 유지하도록 설계.
- 내부적으로 Heap 자료구조 사용
- push(), top(), pop(), empty(), size() 
*/

#include <iostream>
#include <queue>
#include <functional>    // greater, less
using namespace std;
int main() {
    priority_queue<int> pq;  // ==  priority_queue<int, vector<int>, less<int>> pq;
    priority_queue<int, vector<int>, greater<int>> pq;  // 작은 원소가 Top을 유지

    pq.push(4);
    pq.push(7);
    pq.push(3);
    pq.push(1);
    pq.push(10);
 
    cout << "PQ size : " << pq.size() << "\n";
    while (!pq.empty()) {
        cout << pq.top() << '\n';
        pq.pop();
    }
    return 0;
}
