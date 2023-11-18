#include <stdio.h>
#include <stdlib.h>

#define HEAP_LEN 100

typedef int Data;
typedef int (*PriorityComp)(Data, Data);

typedef struct _heap {
    PriorityComp comp;
    int numOfData;
    Data heapArr[HEAP_LEN];
} Heap;

void HeapInit(Heap *ph, PriorityComp pc);
int IsEmpty(Heap *ph);
void Insert(Heap *ph, Data data);
Data Delete(Heap *ph);

void HeapInit(Heap *ph, PriorityComp pc) {
    ph->numOfData = 0;
    ph->comp = pc;
}

int IsEmpty(Heap *ph) {
    return ph->numOfData == 0;
}

int GetParentIdx(int idx) {
    return idx / 2;
}

int GetLeftChildIdx(int idx) {
    return idx * 2;
}

int GetRightChildIdx(int idx) {
    return GetLeftChildIdx(idx) + 1;
}

int GetHighChildIdx(Heap *ph, int idx) {
    if (GetLeftChildIdx(idx) > ph->numOfData)
        return 0;

    if (GetLeftChildIdx(idx) == ph->numOfData)
        return GetLeftChildIdx(idx);

    if (ph->comp(ph->heapArr[GetLeftChildIdx(idx)], ph->heapArr[GetRightChildIdx(idx)]) < 0)
        return GetRightChildIdx(idx);
    else
        return GetLeftChildIdx(idx);
}

void Insert(Heap *ph, Data data) {
    int idx = ph->numOfData + 1;

    while (idx != 1) {
        if (ph->comp(data, ph->heapArr[GetParentIdx(idx)]) > 0) {
            ph->heapArr[idx] = ph->heapArr[GetParentIdx(idx)];
            idx = GetParentIdx(idx);
        } else {
            break;
        }
    }

    ph->heapArr[idx] = data;
    ph->numOfData += 1;
}

Data Delete(Heap *ph) {
    Data rdata = ph->heapArr[1];
    Data lastElem = ph->heapArr[ph->numOfData];

    int parentIdx = 1;
    int childIdx;

    while (childIdx = GetHighChildIdx(ph, parentIdx)) {
        if (ph->comp(lastElem, ph->heapArr[childIdx]) >= 0)
            break;

        ph->heapArr[parentIdx] = ph->heapArr[childIdx];
        parentIdx = childIdx;
    }

    ph->heapArr[parentIdx] = lastElem;
    ph->numOfData -= 1;
    return rdata;
}

// Sample Priority Comparison Function (max priority queue)
int CompareData(Data d1, Data d2) {
    //return d2 - d1;
    return d1 - d2;
}

// PriorityQueue
typedef Heap PQueue;

void PQInit(PQueue * ppq, PriorityComp pc){
    HeapInit(ppq, pc);
}

int PQIsEmpty(PQueue * ppq){
    return IsEmpty(ppq);
}

void Enqueue(PQueue * ppq, Data data){
    Insert(ppq, data);
}

Data Dequeue(PQueue * ppq){
    return Delete(ppq);
}

int main(void) {
    PQueue pq;
    PQInit(&pq, CompareData);

    Enqueue(&pq, 30);
    Enqueue(&pq, 20);
    Enqueue(&pq, 40);
    Enqueue(&pq, 10);

    while (! PQIsEmpty(&pq)) {
        printf("%d ", Dequeue(&pq));
    }

    return 0;
}
