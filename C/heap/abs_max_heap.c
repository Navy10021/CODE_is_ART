#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

// 절대값 힙 구조체 정의
typedef struct {
    int *arr;
    int capacity;
    int size;
} AbsoluteValueHeap;

// 절대값 반환 함수
int absoluteValue(int x) {
    return (x < 0) ? -x : x;
}

// Absolute Value Heap 초기화 함수
AbsoluteValueHeap* createAbsoluteValueHeap(int capacity) {
    AbsoluteValueHeap* heap = (AbsoluteValueHeap*)malloc(sizeof(AbsoluteValueHeap));
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

// Absolute Value Heapify 함수
void absoluteValueHeapify(AbsoluteValueHeap* heap, int i) {
    int largest = i;
    int left = leftChild(i);
    int right = rightChild(i);

    // 왼쪽 자식이 현재 노드보다 크면 largest를 왼쪽 자식으로 업데이트
    if (left < heap->size && absoluteValue(heap->arr[left]) > absoluteValue(heap->arr[largest]))
        largest = left;
    
    // 오른쪽 자식이 현재 노드보다 크면 largest를 오른쪽 자식으로 업데이트
    if (right < heap->size && absoluteValue(heap->arr[right]) > absoluteValue(heap->arr[largest]))
        largest = right;

    // largest가 현재 노드가 아니라면 노드를 스왑하고 재귀적으로 호출
    if (largest != i) {
        swap(&heap->arr[i], &heap->arr[largest]);
        absoluteValueHeapify(heap, largest);
    }
}

// Absolute Value Heap에 요소 삽입
void insert(AbsoluteValueHeap* heap, int key) {
    if (heap->size == heap->capacity) {
        printf("Absolute Value Heap is full. Insertion failed.\n");
        return;
    }

    // 요소를 힙의 끝에 추가
    int i = heap->size;
    heap->arr[i] = key;
    heap->size++;

    // 요소를 올바른 위치로 이동시키기 위해 Absolute Value Heapify 호출
    while (i != 0 && absoluteValue(heap->arr[parent(i)]) < absoluteValue(heap->arr[i])) {
        swap(&heap->arr[i], &heap->arr[parent(i)]);
        i = parent(i);
    }
}

// Absolute Value Heap에서 최댓값 반환
int extractMax(AbsoluteValueHeap* heap) {
    if (heap->size <= 0)
        return -1; // 힙이 비어있음

    if (heap->size == 1) {
        heap->size--;
        return heap->arr[0];
    }

    // 루트 노드의 값을 저장하고 루트 노드를 힙의 마지막 노드로 대체
    int max = heap->arr[0];
    heap->arr[0] = heap->arr[heap->size - 1];
    heap->size--;

    // Absolute Value Heap 조건을 만족하도록 Absolute Value Heapify 호출
    absoluteValueHeapify(heap, 0);

    return max;
}

// Absolute Value Heap 출력 함수 (테스트용)
void printAbsoluteValueHeap(AbsoluteValueHeap* heap) {
    printf("Absolute Value Heap: ");
    for (int i = 0; i < heap->size; i++) {
        printf("%d ", heap->arr[i]);
    }
    printf("\n");
}

int main() {
    AbsoluteValueHeap* heap = createAbsoluteValueHeap(10);

    insert(heap, 4);
    insert(heap, -10);
    insert(heap, 8);
    insert(heap, -15);
    insert(heap, 20);

    printAbsoluteValueHeap(heap);

    int max = extractMax(heap);
    printf("Extracted Max: %d\n", max);

    printAbsoluteValueHeap(heap);

    free(heap->arr);
    free(heap);

    return 0;
}
