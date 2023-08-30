#include <stdio.h>
#include <stdlib.h>

struct MaxHeap {
    int* array;
    int capacity;
    int size;
};

// Function to create a new max heap
struct MaxHeap* createMaxHeap(int capacity) {
    struct MaxHeap* heap = (struct MaxHeap*)malloc(sizeof(struct MaxHeap));
    heap->capacity = capacity;
    heap->size = 0;
    heap->array = (int*)malloc(capacity * sizeof(int));
    return heap;
}

// Function to swap two elements in the heap
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function to maintain the max-heap property after insertion
void heapifyUp(struct MaxHeap* heap, int index) {
    int parent = (index - 1) / 2;
    while (index > 0 && heap->array[index] > heap->array[parent]) {
        swap(&heap->array[index], &heap->array[parent]);
        index = parent;
        parent = (index - 1) / 2;
    }
}

// Function to insert an element into the heap
void insert(struct MaxHeap* heap, int value) {
    if (heap->size >= heap->capacity) {
        printf("Heap is full.\n");
        return;
    }
    heap->array[heap->size] = value;
    heap->size++;
    heapifyUp(heap, heap->size - 1);
}

// Function to maintain the max-heap property after deletion
void heapifyDown(struct MaxHeap* heap, int index) {
    int largest = index;
    int leftChild = 2 * index + 1;
    int rightChild = 2 * index + 2;

    if (leftChild < heap->size && heap->array[leftChild] > heap->array[largest])
        largest = leftChild;

    if (rightChild < heap->size && heap->array[rightChild] > heap->array[largest])
        largest = rightChild;

    if (largest != index) {
        swap(&heap->array[index], &heap->array[largest]);
        heapifyDown(heap, largest);
    }
}

// Function to extract the maximum element from the heap
int extractMax(struct MaxHeap* heap) {
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

// Function to free the memory occupied by the heap
void destroyMaxHeap(struct MaxHeap* heap) {
    free(heap->array);
    free(heap);
}

int main() {
    struct MaxHeap* heap = createMaxHeap(10);
    insert(heap, 5);
    insert(heap, 3);
    insert(heap, 8);
    insert(heap, 1);
    insert(heap, 10);

    printf("Extracted Max: %d\n", extractMax(heap));
    printf("Extracted Max: %d\n", extractMax(heap));

    destroyMaxHeap(heap);

    return 0;
}
