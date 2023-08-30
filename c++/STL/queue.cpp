/*
Queue : First-In-Fist-Out(FIFO)
*/
#include <iostream> 
#include <queue> 
using namespace std;

int main(){
//int자료형을 저장하는 큐 생성 
queue<int> q;

//원소 삽입
q.push(1);
q.push(2);
q.push(3);
q.push(4);
q.push(5);

//맨 앞 원소 값 출력
printf("Front : %d\n", q.front());

//맨 앞 원소 팝 
printf("POP! \n");
q.pop(); 
printf("Front : %d\n", q.front());

//큐가 비어있다면 1 아니면 0 
printf("is empty? %d\n", q.empty()); 

//큐에 저장되어 있는 원소의 수 출력 
printf("Queue size : %d\n", q.size()); return 0;
}
