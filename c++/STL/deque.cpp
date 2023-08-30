/*
Deque : 동적배열, 임의의 위치에 원소접근 가능, Front와 Back에 원소 추가 O(1)
*/
#include <iostream> 
#include <deque> 
using namespace std;

int main(){
    deque<int> dq;

    // array front에 원소 추가
    dq.push_front(1);
    dq.push_front(2);
    dq.push_front(3);

    // array Back에 원소 추가
    dq.push_back(10);
    dq.push_back(11);
    dq.push_back(12);

    // front 원소 및 back 원소
    printf("%d \n", dq.front());
    printf("%d \n", dq.back());

    // 맨 앞 원소 pop
    dq.pop_front();
    printf("%d \n", dq.front());
    printf("%d \n", dq.back());

    // 맨 뒤 원소 pop
    dq.pop_back();
    printf("%d \n", dq.front());
    printf("%d \n", dq.back());

    //큐가 비어있다면 1 아니면 0 
    printf("%d\n", dq.empty()); 
    
    //큐에 저장되어 있는 원소의 수 출력 
    printf("%d\n", dq.size());

}
