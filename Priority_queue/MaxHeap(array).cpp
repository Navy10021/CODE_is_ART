#include <iostream>
#include <vector>
#include <stdexcept> // std::out_of_range를 사용하기 위해 추가

class MaxHeap {
private:
    std::vector<int> heap;

    // 하향 힙 조정: 부모가 자식보다 크거나 같도록 조정
    void heapifyUp(int index) {
        while (index > 0) {
            int parentIndex = (index - 1) / 2;
            if (heap[parentIndex] < heap[index]) { // 부모보다 큰 경우
                std::swap(heap[parentIndex], heap[index]);
                index = parentIndex;
            } else {
                break;
            }
        }
    }

    // 상향 힙 조정: 더 큰 자식과 교환
    void heapifyDown(int index) {
        int size = heap.size();
        while (true) {
            int leftChildIndex = 2 * index + 1;
            int rightChildIndex = 2 * index + 2;
            int largestIndex = index;

            if (leftChildIndex < size && heap[leftChildIndex] > heap[largestIndex]) {
                largestIndex = leftChildIndex;
            }

            if (rightChildIndex < size && heap[rightChildIndex] > heap[largestIndex]) {
                largestIndex = rightChildIndex;
            }

            if (largestIndex != index) {
                std::swap(heap[index], heap[largestIndex]);
                index = largestIndex;
            } else {
                break;
            }
        }
    }

public:
    MaxHeap() {}

    // 새로운 값을 힙에 삽입
    void insert(int val) {
        heap.push_back(val);
        heapifyUp(heap.size() - 1);
    }

    // 최대값을 제거하고, 반환
    int extractMax() {
        if (heap.empty()) {
            throw std::out_of_range("Heap is empty");
        }
        int maxVal = heap[0];
        heap[0] = heap.back();
        heap.pop_back();
        heapifyDown(0);
        return maxVal;
    }

    // 최대값 반환, 제거하지 않음
    int peek() const {
        if (heap.empty()) {
            throw std::out_of_range("Heap is empty");
        }
        return heap[0];
    }

    bool isEmpty() const {
        return heap.empty();
    }
};

int main() {
    MaxHeap heap;
    heap.insert(5);
    heap.insert(3);
    heap.insert(8);
    heap.insert(4);

    while (!heap.isEmpty()) {
        std::cout << heap.extractMax() << " ";
    }

    return 0;
}
