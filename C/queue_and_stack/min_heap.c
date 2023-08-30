#include<stdio.h>
#include<stdlib.h>

struct MinHeap{
    int* array;
    int capacity;
    int size;
};

// 1. 새로운 MinHeap을 생성하는 함수 
struct MinHeap* createMinHeap(int capacity){
    struct MinHeap* heap = (struct MinHeap*)malloc(sizeof(struct MinHeap));
    heap->capacity = capacity;
    heap->size = 0;
    heap->array = (int*)malloc(capacity * sizeof(int));
    return heap;
}

// 2. Swap 함수
void swap(int* a, int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

// 3. Insert && MinHeap 성질 유지(가장 작은 값을 최상단에 둔다.)
void heapifyUp(struct MinHeap* heap, int index){
    int parent = (index - 1)/2;
    while (index > 0 && heap->array[index] < heap->array[parent]){
        swap(&heap->array[index], &heap->array[parent]);
        index = parent;
        parent = (index - 1) / 2;
    }
}

// 4. Insert element
void insert(struct MinHeap* heap, int value) {
    if (heap->size >= heap->capacity) {
        printf("Heap is full.\n");
        return;
    }
    heap->array[heap->size] = value;
    heap->size++;
    heapifyUp(heap, heap->size - 1);
}

// 5. Erase && MinHeap 성질 유지 
void heapifyDown(struct MinHeap* heap, int index) {
    int smallest = index;
    int leftChild = 2 * index + 1;
    int rightChild = 2 * index + 2;

    if (leftChild < heap->size && heap->array[leftChild] < heap->array[smallest])
        smallest = leftChild;

    if (rightChild < heap->size && heap->array[rightChild] < heap->array[smallest])
        smallest = rightChild;

    if (smallest != index) {
        swap(&heap->array[index], &heap->array[smallest]);
        heapifyDown(heap, smallest);
    }
}

// 6. 힙에서 최솟값을 추출하는 함수 && POP()
int extractMin(struct MinHeap* heap) {
    if (heap->size <= 0) {
        printf("Heap is empty.\n");
        return -1;
    }
    if (heap->size == 1) {
        heap->size--;
        return heap->array[0];
    }

    int root = heap->array[0];
    heap->array[0] = heap->array[heap->size - 1];
    heap->size--;
    heapifyDown(heap, 0);
    return root;
}

// 7. 메모리 해제
void destroyHeap(struct MinHeap* heap) {
    free(heap->array);
    free(heap);
}

int main() {
    struct MinHeap* heap = createMinHeap(10);
    insert(heap, 5);
    insert(heap, 3);
    insert(heap, 8);
    insert(heap, 1);
    insert(heap, 10);

    printf("Min element : %d\n", extractMin(heap));
    printf("Min element : %d\n", extractMin(heap));
    printf("Min element : %d\n", extractMin(heap));

    destroyHeap(heap);

    return 0;
}
