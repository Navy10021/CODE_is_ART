/*
Heaps : Binary Tree 형태.
Min heap : 부모노드 =< 자식노드. Root == 가장 작은값.
Min heap == Priority Queue;
*/ 
#include <iostream>
#include <vector>

class MinHeap{
    private:
        std::vector<int> heap;
    
    // element를 위로 올려서 Min Heap 속성을 유지하는 함수
    void heapUp(int idx){
        while (idx > 0){
            int parentIdx = (idx - 1) / 2;
            if (heap[parentIdx] > heap[idx]){
                std::swap(heap[parentIdx], heap[idx]);
                idx = parentIdx;
            }
            else{
                break;
            }
        }
    }
    /*
    void heapifUp (int idx){
        int parernt = (idx - 1) / 2;
        while(idx > 0 && heap[parernt] > heap[idx]){
            std::swap(heap[parernt], heap[idx]);
            idx = parernt;
            parernt = (idx - 1) / 2;
        }
    }
    */
   
    // element를 아래로 내려서 Min Heap 속성을 유지하는 함수
    void heapDown(int idx){
        int leftChildIdx = 2 * idx + 1;
        int rightChildIdx = 2 * idx + 2;
        int smallest = idx;

        if (leftChildIdx < heap.size() && heap[leftChildIdx] < heap[smallest]){
            smallest = leftChildIdx;
        }
        if (rightChildIdx < heap.size() && heap[rightChildIdx] < heap[smallest]){
            smallest = rightChildIdx;
        }
        if (smallest != idx){
            std::swap(heap[idx], heap[smallest]);
            heapDown(smallest);
        }
    }

    public:
        // 생성자 : input값 없음.
        MinHeap() {}
        
        // new element를 Heap에 삽입.
        void push(int value){
            heap.push_back(value);
            heapUp(heap.size() - 1);  // 삽입된 index heap-up
        }
        // 최소값 리턴 
        int top(){
            if (!heap.empty()){
                return heap[0];
            }
            else{
                throw std::runtime_error("Heap is empty!");
            }
        }
        // 최소값 제거 및 최소값 리턴(Pop)
        int pop(){
            if (!heap.empty()){
                int minValue = heap[0];
                heap[0] = heap.back();
                heap.pop_back();
                heapDown(0);

                return minValue;
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
    MinHeap min_heap;

    min_heap.push(5);
    min_heap.push(10);
    min_heap.push(3);
    min_heap.push(100);
    min_heap.push(50);
    min_heap.push(30);
    min_heap.push(0);

    while(!min_heap.isEmpty()){
        std::cout<< min_heap.pop() << " ";
    }
    return 0;

}
    
