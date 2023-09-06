#include <stdio.h>
#include <stdbool.h>

#define MAX_VERTICES 100

// 그래프를 나타내는 구조체
struct Graph {
    int vertices;
    bool visited[MAX_VERTICES];
    int adjMatrix[MAX_VERTICES][MAX_VERTICES];
};

// 그래프 초기화 함수
void initGraph(struct Graph *g, int vertices) {
    g->vertices = vertices;
    for (int i = 0; i < vertices; i++) {
        g->visited[i] = false;
        for (int j = 0; j < vertices; j++) {
            g->adjMatrix[i][j] = 0;
        }
    }
}

// 그래프에 간선 추가 함수
void addEdge(struct Graph *g, int start, int end) {
    g->adjMatrix[start][end] = 1;
    g->adjMatrix[end][start] = 1;
}

// 깊이 우선 탐색 함수
void DFS(struct Graph *g, int start) {
    printf("%d -> ", start);
    g->visited[start] = true;

    for (int i = 0; i < g->vertices; i++) {
        if (g->adjMatrix[start][i] == 1 && !g->visited[i]) {
            DFS(g, i);
        }
    }
}

int main() {
    struct Graph g;
    int vertices, edges;
    printf("Enter the number of vertices: ");
    scanf("%d", &vertices);
    initGraph(&g, vertices);

    printf("Enter the number of edges: ");
    scanf("%d", &edges);

    printf("Enter the edges (format: start end):\n");
    for (int i = 0; i < edges; i++) {
        int start, end;
        scanf("%d %d", &start, &end);
        addEdge(&g, start, end);
    }

    int startNode;
    printf("Enter the starting node for DFS: ");
    scanf("%d", &startNode);

    printf("Depth First Search starting from node %d:\n", startNode);
    DFS(&g, startNode);

    return 0;
}
