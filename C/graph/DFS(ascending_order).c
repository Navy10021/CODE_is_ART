#include <stdio.h>
#include <stdbool.h>

#define MAX_VERTICES 100

// 그래프를 나타내는 구조체
struct Graph {
    int vertices;
    bool visited[MAX_VERTICES];
    int adjMatrix[MAX_VERTICES][MAX_VERTICES];
    int order[MAX_VERTICES];
    int cnt;
};

// 그래프 초기화 함수
void initGraph(struct Graph *g, int vertices) {
    g->cnt = 0;
    g->vertices = vertices;
    for (int i = 0; i <= vertices; i++) {
        g->visited[i] = false;
        g->order[i] = 0;
        for (int j = 0; j <= vertices; j++) {
            g->adjMatrix[i][j] = 0;
        }
    }
}

// 그래프에 간선 추가 함수
void addEdge(struct Graph *g, int start, int end) {
    g->adjMatrix[start][end] = 1;
    g->adjMatrix[end][start] = 1;
}

// 깊이 우선 탐색 함수 : 각 노드의 방문순서를 체크.
void DFS(struct Graph *g, int curr) {
    // 이미 방문했다면 pass
    if (g->visited[curr])
        return;
    // 방문 안했다면, 방문 표시 후 방문순서를 체크
    g->visited[curr] = true;
    g->cnt++;
    g->order[curr] = g->cnt;

    for (int i = 0; i < g->vertices; i++) {
        if (g->adjMatrix[curr][i] == 1 && !g->visited[i]) {
            DFS(g, i);
        }
    }
}

int main() {
    struct Graph g;
    int vertices, edges, startNode;
    printf("Enter the number of vertices: ");
    scanf("%d", &vertices);
    initGraph(&g, vertices);

    printf("Enter the number of edges: ");
    scanf("%d", &edges);

    printf("Enter the starting node for DFS: ");
    scanf("%d", &startNode);

    printf("Enter the edges (format: start end):\n");
    for (int i = 0; i < edges; i++) {
        int start, end;
        scanf("%d %d", &start, &end);
        addEdge(&g, start, end);
    }

    DFS(&g, startNode);
    // 인접리스트 sorting

    for (int i=1; i<=vertices; i++){
        printf("%d ", g.order[i]);
    }

    return 0;
}
