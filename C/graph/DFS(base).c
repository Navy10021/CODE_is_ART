#include <stdio.h>
#include <stdlib.h>

// 그래프의 최대 노드 수
#define MAX_NODES 100

// 그래프의 인접 리스트를 나타내는 구조체
typedef struct Node {
    int value;
    struct Node* next;
} Node;

// 그래프 구조체 정의
typedef struct {
    int numNodes;
    Node* adjacencyList[MAX_NODES];
    int visited[MAX_NODES];
} Graph;

// 그래프 초기화 함수
void initGraph(Graph* graph, int numNodes) {
    graph->numNodes = numNodes;
    for (int i = 0; i < numNodes; i++) {
        graph->adjacencyList[i] = NULL;
        graph->visited[i] = 0;
    }
}

// 그래프에 간선 추가 함수
void addEdge(Graph* graph, int src, int dest) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->value = dest;
    newNode->next = graph->adjacencyList[src];
    graph->adjacencyList[src] = newNode;
}

// 인접 리스트 정렬 함수
void sortAdjacencyList(Graph* graph) {
    for (int i = 0; i < graph->numNodes; i++) {
        // 현재 노드와 연결된 노드 값을 배열에 저장
        int numNeighbors = 0;
        int neighbors[MAX_NODES];

        Node* current = graph->adjacencyList[i];
        while (current != NULL) {
            neighbors[numNeighbors] = current->value;
            numNeighbors++;
            current = current->next;
        }

        // 배열을 오름차순으로 정렬
        for (int j = 0; j < numNeighbors - 1; j++) {
            for (int k = 0; k < numNeighbors - j - 1; k++) {
                if (neighbors[k] > neighbors[k + 1]) {
                    int temp = neighbors[k];
                    neighbors[k] = neighbors[k + 1];
                    neighbors[k + 1] = temp;
                }
            }
        }

        // 정렬된 값을 다시 연결 리스트에 삽입
        Node* sortedList = NULL;
        for (int j = numNeighbors - 1; j >= 0; j--) {
            Node* newNode = (Node*)malloc(sizeof(Node));
            newNode->value = neighbors[j];
            newNode->next = sortedList;
            sortedList = newNode;
        }

        graph->adjacencyList[i] = sortedList;
    }
}

// DFS 함수 (재귀)
void dfs(Graph* graph, int node) {
    graph->visited[node] = 1; // 노드를 방문한 것으로 표시
    printf("%d ", node); // 노드 출력

    // 현재 노드와 연결된 모든 미방문 노드를 재귀적으로 방문
    Node* current = graph->adjacencyList[node];
    while (current != NULL) {
        if (!graph->visited[current->value]) {
            dfs(graph, current->value);
        }
        current = current->next;
    }
}

// DFS 시작 함수
void startDFS(Graph* graph, int startNode) {
    // 인접 리스트 정렬
    sortAdjacencyList(graph);

    // 시작 노드부터 DFS 시작
    dfs(graph, startNode);

    // 시작 노드와 연결되지 않은 다른 연결 요소를 탐색
    for (int i = 0; i < graph->numNodes; i++) {
        if (!graph->visited[i]) {
            dfs(graph, i);
        }
    }
}

int main() {
    int numNodes = 7; // 노드 수
    Graph graph;
    initGraph(&graph, numNodes);

    // 그래프에 간선 추가
    addEdge(&graph, 0, 1);
    addEdge(&graph, 0, 2);
    addEdge(&graph, 1, 3);
    addEdge(&graph, 2, 5);
    addEdge(&graph, 2, 4);
    addEdge(&graph, 3, 4);
    addEdge(&graph, 3, 6);

    int startNode = 0; // DFS를 시작할 노드 선택
    printf("DFS Search: ");
    startDFS(&graph, startNode);
    printf("\n");

    return 0;
}
