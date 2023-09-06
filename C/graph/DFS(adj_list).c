#include <stdio.h>
#include <stdlib.h>

// 그래프의 정점을 나타내는 구조체
struct Node {
    int data;
    struct Node* next;
};

// 그래프를 나타내는 구조체
struct Graph {
    int vertices;
    struct Node** adjList;
    int* visited;
};

// 그래프 초기화 함수
struct Graph* createGraph(int vertices) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->vertices = vertices;
    graph->adjList = (struct Node**)malloc(vertices * sizeof(struct Node*));
    graph->visited = (int*)malloc(vertices * sizeof(int));

    for (int i = 0; i < vertices; i++) {
        graph->adjList[i] = NULL;
        graph->visited[i] = 0;
    }

    return graph;
}

// 그래프에 간선 추가 함수
void addEdge(struct Graph* graph, int src, int dest) {
    // 간선을 src의 인접 리스트에 추가
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = dest;
    newNode->next = graph->adjList[src];
    graph->adjList[src] = newNode;

    // 비방향 그래프라면 dest의 인접 리스트에도 추가
    newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = src;
    newNode->next = graph->adjList[dest];
    graph->adjList[dest] = newNode;
}

// DFS 함수
void DFS(struct Graph* graph, int vertex) {
    struct Node* temp = graph->adjList[vertex];
    graph->visited[vertex] = 1;
    printf("%d ->", vertex);

    while (temp != NULL) {
        int adjVertex = temp->data;
        if (!graph->visited[adjVertex]) {
            DFS(graph, adjVertex);
        }
        temp = temp->next;
    }
}

int main() {
    int vertices, edges;
    printf("Enter the number of vertices: ");
    scanf("%d", &vertices);

    struct Graph* graph = createGraph(vertices);

    printf("Enter the number of edges: ");
    scanf("%d", &edges);

    for (int i = 0; i < edges; i++) {
        int start, end;
        scanf("%d %d", &start, &end);
        addEdge(graph, start, end);
    }

    int startNode;
    printf("Enter the starting node for DFS: ");
    scanf("%d", &startNode);

    printf("Depth First Search starting from node %d:\n", startNode);
    DFS(graph, startNode);

    return 0;
}
