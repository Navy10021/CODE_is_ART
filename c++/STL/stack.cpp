/*
Stack : Last-In-First-Out(LIFO)
*/
#include <iostream> 
#include <stack> 
using namespace std;

int main(){ 
//int자료형을 저장하는 스택 생성 
stack<int> st; 

//원소 삽입
st.push(1);
st.push(2);
st.push(3);
st.push(4);
st.push(5);

//맨 위 원소 팝
printf("POP! \n");
st.pop();

//맨 위 원소 값 출력
printf("Top element : %d\n", st.top()); 

//스택이 비어있다면 1 아니면 0 
printf("is empty? %d\n", st.empty()); 

//스택에 저장되어 있는 원소의 수 출력
printf("Stack size : %d\n", st.size()); return 0; 
}
