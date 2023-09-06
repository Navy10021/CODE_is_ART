#include <stdio.h>
#include <stdlib.h>

// Heap 구조체 정의
typedef struct {
    int *arr;
    int capacity;
    int size;
} MinHeap;

// Heap 초기화 함수
MinHeap* createMinHeap(int capacity) {
    MinHeap* heap = (MinHeap*)malloc(sizeof(MinHeap));
    heap->capacity = capacity;
    heap->size = 0;
    heap->arr = (int*)malloc(capacity * sizeof(int));
    return heap;
}

// 부모 노드의 인덱스 반환
int parent(int i) {
    return (i - 1) / 2;
}

// 왼쪽 자식 노드의 인덱스 반환
int leftChild(int i) {
    return (2 * i) + 1;
}

// 오른쪽 자식 노드의 인덱스 반환
int rightChild(int i) {
    return (2 * i) + 2;
}

// 두 노드의 값을 스왑하는 함수
void swap(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

// Heapify 함수
void minHeapify(MinHeap* heap, int i) {
    int smallest = i;
    int left = leftChild(i);
    int right = rightChild(i);

    // 왼쪽 자식이 현재 노드보다 작으면 smallest를 왼쪽 자식으로 업데이트
    if (left < heap->size && heap->arr[left] < heap->arr[smallest])
        smallest = left;

    // 오른쪽 자식이 현재 노드보다 작으면 smallest를 왼쪽 자식으로 업데이트
    if (right < heap->size && heap->arr[right] < heap->arr[smallest])
        smallest = right;

    // smallest가 현재 노드가 아니라면 노드를 스왑하고 재귀적으로 호출
    if (smallest != i) {
        swap(&heap->arr[i], &heap->arr[smallest]);
        minHeapify(heap, smallest);
    }
}

// Min Heap에 요소 삽입
void insert(MinHeap* heap, int key) {
    if (heap->size == heap->capacity) {
        printf("Min Heap is full. Insertion failed.\n");
        return;
    }

    // 요소를 힙의 끝에 추가
    int i = heap->size;
    heap->arr[i] = key;
    heap->size++;

    // 요소를 올바른 위치로 이동시키기 위해 Max Heapify 호출
    while (i != 0 && heap->arr[parent(i)] > heap->arr[i]) {
        swap(&heap->arr[i], &heap->arr[parent(i)]);
        i = parent(i);
    }
}

// Min Heap에서 최소값 반환
int extractMin(MinHeap* heap) {
    if (heap->size <= 0)
        return -1; // 힙이 비어있음

    if (heap->size == 1) {
        heap->size--;
        return heap->arr[0];
    }

    // 루트 노드의 값을 저장하고 루트 노드를 힙의 마지막 노드로 대체
    int min = heap->arr[0];
    heap->arr[0] = heap->arr[heap->size - 1];
    heap->size--;

    // Min Heap 조건을 만족하도록 Min Heapify 호출
    minHeapify(heap, 0);

    return min;
}

// Min Heap 출력 함수 (테스트용)
void printMinHeap(MinHeap* heap) {
    printf("Min Heap: ");
    printf("{ ");
    for (int i = 0; i < heap->size; i++) {
        printf("%d ", heap->arr[i]);
    }
    printf("}");
    printf("\n");
}

int main() {
    int min;
    MinHeap* heap = createMinHeap(10);

    insert(heap, 4);
    insert(heap, 10);
    insert(heap, 8);
    insert(heap, 15);
    insert(heap, 20);
    insert(heap, 1);
    insert(heap, 3);
    insert(heap, 5);

    printMinHeap(heap);

    min = extractMin(heap);
    printf("Extracted Min: %d\n", min);

    printMinHeap(heap);

    min = extractMin(heap);
    printf("Extracted Min: %d\n", min);

    printMinHeap(heap);

    min = extractMin(heap);
    printf("Extracted Min: %d\n", min);

    printMinHeap(heap);

    free(heap->arr);
    free(heap);

    return 0;
}
