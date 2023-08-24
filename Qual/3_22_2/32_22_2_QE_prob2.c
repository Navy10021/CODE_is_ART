#include <stdio.h>
#include <stdlib.h>

#define MAX_NODES 4
#define MAX_PATHS 10
#define MAX_PATH_LENGTH 10

typedef struct {
    char id;
} GNode;

typedef struct {
    GNode* adj[MAX_NODES];
    int count;
} AdjList;

typedef struct {
    GNode nodes[MAX_NODES];
    AdjList adjList[MAX_NODES];
} Graph;

void backtracking(Graph* graph, GNode* start, GNode* target, char path[], int pathLen, char ans[MAX_PATHS][MAX_PATH_LENGTH], int* ansCount) {
    path[pathLen++] = start->id;
    if (start == target) {
        for (int i = 0; i < pathLen; i++) {
            ans[*ansCount][i] = path[i];
        }
        ans[*ansCount][pathLen] = '\0';
        (*ansCount)++;
        return;
    }

    AdjList* adjNodes = &graph->adjList[start->id - 'a'];
    for (int i = 0; i < adjNodes->count; i++) {
        backtracking(graph, adjNodes->adj[i], target, path, pathLen, ans, ansCount);
    }
}

int main() {
    Graph graph;
    GNode a = {'a'}, b = {'b'}, c = {'c'}, d = {'d'};
    graph.nodes[0] = a;
    graph.nodes[1] = b;
    graph.nodes[2] = c;
    graph.nodes[3] = d;

    graph.adjList[a.id - 'a'] = (AdjList){{&b, &c}, 2};
    graph.adjList[b.id - 'a'] = (AdjList){{&d}, 1};
    graph.adjList[c.id - 'a'] = (AdjList){{}, 0};
    graph.adjList[d.id - 'a'] = (AdjList){{&c}, 1};

    char path[MAX_PATH_LENGTH];
    char ans[MAX_PATHS][MAX_PATH_LENGTH];
    int ansCount = 0;

    backtracking(&graph, &a, &c, path, 0, ans, &ansCount);

    for (int i = 0; i < ansCount; i++) {
        printf("%s\n", ans[i]);
    }

    return 0;
}
