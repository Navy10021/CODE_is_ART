/*
Heaps : Binary Tree 형태.
Max heap : 부모노드 >= 자식노드. Root == 가장 큰값. 우선순위가 높을수록 값이 크다.
*/ 
#include <iostream>
#include <vector>

class MaxHeap{
    private:
        std::vector<int> heap;
    
    // element를 위로 올려서 Max Heap 속성을 유지하는 함수
    void heapUp(int idx){
        int parentIdx = (idx - 1) / 2;  // 이진트리
        // 자식노드 > 부모노드이면 Swap
        while (idx > 0 && heap[idx] > heap[parentIdx]){
            std::swap(heap[idx], heap[parentIdx]);
            idx = parentIdx;
            parentIdx = (idx - 1) / 2;
        }
    }

    // element를 아래로 내려서 Max Heap 속성을 유지하는 함수
    void heapDown(int idx){
        int leftChildIdx = 2 * idx + 1;
        int rightChildIdx = 2 * idx + 2;
        int largest = idx;

        if (leftChildIdx < heap.size() && heap[leftChildIdx] > heap[largest]){
            largest = leftChildIdx;
        }
        if (rightChildIdx < heap.size() && heap[rightChildIdx] > heap[largest]){
            largest = rightChildIdx;
        }
        if (largest != idx){
            std::swap(heap[idx], heap[largest]);
            heapDown(largest);
        }
    }

    public:
        // 생성자 : input값 없음.
        MaxHeap() {}
        
        // new element를 Heap에 삽입.
        void push(int value){
            heap.push_back(value);
            heapUp(heap.size()-1);  // 삽입된 index heap-up
        }
        // Get Max값 리턴 
        int top(){
            if (!heap.empty()){
                return heap[0];
            }
            else{
                throw std::runtime_error("Heap is empty!");
            }
        }
        // 최대 값 제거(Pop)
        void pop(){
            if (!heap.empty()){
                std::swap(heap[0], heap[heap.size()-1]);
                heap.pop_back();
                heapDown(0);
            }
            else{
                throw std::runtime_error("Heap is empty!");
            }
        }
        // Heap empty 여부 확인
        bool isEmpty(){
            return heap.empty();
        }
};

int main(){
    MaxHeap max_heap;

    max_heap.push(5);
    max_heap.push(10);
    max_heap.push(3);
    max_heap.push(100);
    max_heap.push(50);
    max_heap.push(30);
    max_heap.push(0);

    std::cout << "Max value : " << max_heap.top() << "\n";
    max_heap.pop();
    std::cout << "Next Max value : " << max_heap.top() << "\n";
    max_heap.pop();
    std::cout << "Next Max value : " << max_heap.top() << "\n";
    max_heap.pop();
    std::cout << "Next Max value : " << max_heap.top() << "\n";
}
