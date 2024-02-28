#include <iostream>
#include <vector>

class MinHeap {
private:
    std::vector<int> heap;

    // 상향 힙 조정 : 부모가 자식보다 작거나 같도록 조정
    void heapifyUp(int index) {
        while (index > 0) {
            int parentIndex = (index - 1) / 2;
            if (heap[parentIndex] > heap[index]) {
                std::swap(heap[parentIndex], heap[index]);
                index = parentIndex;
            } else {
                break;
            }
        }
    }
    // 더 작은 자식과 교환
    void heapifyDown(int index) {
        int size = heap.size();
        while (true) {
            int leftChildIndex = 2 * index + 1;
            int rightChildIndex = 2 * index + 2;
            int smallestIndex = index;

            if (leftChildIndex < size && heap[leftChildIndex] < heap[smallestIndex]) {
                smallestIndex = leftChildIndex;
            }

            if (rightChildIndex < size && heap[rightChildIndex] < heap[smallestIndex]) {
                smallestIndex = rightChildIndex;
            }

            if (smallestIndex != index) {
                std::swap(heap[index], heap[smallestIndex]);
                index = smallestIndex;
            } else {
                break;
            }
        }
    }

public:
    MinHeap() {}
    // 새로운 값을 힙에 삽입
    void insert(int val) {
        heap.push_back(val);
        heapifyUp(heap.size() - 1);
    }
    // 최소값을 제거하고, 반환
    int extractMin() {
        if (heap.empty()) {
            throw std::out_of_range("Heap is empty");
        }
        int minVal = heap[0];
        heap[0] = heap.back();
        heap.pop_back();
        heapifyDown(0);
        return minVal;
    }
    // 최소값 반환, 제거X
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
    MinHeap heap;
    heap.insert(5);
    heap.insert(3);
    heap.insert(8);
    heap.insert(4);

    while (!heap.isEmpty()) {
        std::cout << heap.extractMin() << " ";
    }

    return 0;
}
