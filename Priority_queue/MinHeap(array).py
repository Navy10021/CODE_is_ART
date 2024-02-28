class MinHeap: # 부모노드가 자식노드 보다 작거나 같은 값을 가지고, 루트가 가장 작은 값 위치
    def __init__(self):
        self.heap = []

    def insert(self, val):
        self.heap.append(val)
        self._heapify_up(len(self.heap) - 1)

    def extractMin(self):
        if not self.heap:
            return None
        min_val = self.heap[0]
        # 마지막 요소를 루트로 이동
        self.heap[0] = self.heap[-1]
        self.heap.pop()
        self._heapify_down(0)
        return min_val

    def _heapify_up(self, index):
        while (parent_index := (index - 1) // 2) >= 0:
            if self.heap[parent_index] > self.heap[index]:
                self.heap[parent_index], self.heap[index] = self.heap[index], self.heap[parent_index]
                index = parent_index
            else:
                break

    def _heapify_down(self, index):
        heap_size = len(self.heap)
        while (left_child_index := 2 * index + 1) < heap_size:
            right_child_index = left_child_index + 1
            smallest_index = index

            if self.heap[left_child_index] < self.heap[smallest_index]:
                smallest_index = left_child_index
            if right_child_index < heap_size and self.heap[right_child_index] < self.heap[smallest_index]:
                smallest_index = right_child_index

            if smallest_index != index:
                self.heap[index], self.heap[smallest_index] = self.heap[smallest_index], self.heap[index]
                index = smallest_index
            else:
                break

    def peek(self):
        return self.heap[0] if self.heap else None

# 사용 예:
heap = MinHeap()
heap.insert(5)
heap.insert(3)
heap.insert(8)
heap.insert(4)
print(heap.extractMin())  # 3을 출력하고, 힙에서 제거
