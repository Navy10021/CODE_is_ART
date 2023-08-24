#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct GNode {
    char* id;
    char color; // 'W', 'B'
    int distance;
    struct GNode* parent;
};

typedef struct GNode GNode;

#define MAX_NODES 256

GNode* newGNode(char* id, char color, int d, GNode* p) {
    GNode* node = (GNode*)malloc(sizeof(GNode));
    node->id = strdup(id);
    node->color = color;
    node->distance = d;
    node->parent = p;
    return node;
}

typedef struct {
    GNode* nodes[MAX_NODES];
    int size;
} Level;

typedef struct {
    Level levels[MAX_NODES];
    int size;
} Levels;

typedef struct {
    GNode* data[MAX_NODES];
    int front;
    int rear;
} Queue;

void initQueue(Queue* q) {
    q->front = q->rear = 0;
}

void enqueue(Queue* q, GNode* node) {
    q->data[q->rear++] = node;
}

GNode* dequeue(Queue* q) {
    return q->data[q->front++];
}

int isEmpty(Queue* q) {
    return q->front == q->rear;
}

typedef struct {
    GNode* data[MAX_NODES];
    int size;
} GNodeList;

typedef struct {
    GNodeList adj[MAX_NODES];
} Graph;

Levels level_partition(Graph* G, GNode* nodes[], GNode* s) {
    Queue q;
    initQueue(&q);
    enqueue(&q, s);
    s->color = 'B';
    Levels vv;
    vv.size = 0;
    Level level0;
    level0.nodes[0] = s;
    level0.size = 1;
    vv.levels[vv.size++] = level0;
    
    while (!isEmpty(&q)) {
        Level level;
        level.size = 0;
        int lv_size = q.rear - q.front;
        for (int i = 0; i < lv_size; i++) {
            GNode* node = dequeue(&q);
            for (int j = 0; j < G->adj[node->distance].size; j++) {
                GNode* adj = G->adj[node->distance].data[j];
                if (adj->color == 'B') continue;
                adj->color = 'B';
                level.nodes[level.size++] = adj;
                enqueue(&q, adj);
            }
        }
        vv.levels[vv.size++] = level;
    }
    return vv;
}

int main() {
    GNode *r = newGNode("r", 'W', 0, NULL),
          *s = newGNode("s", 'W', 1, NULL),
          *t = newGNode("t", 'W', 2, NULL),
          *u = newGNode("u", 'W', 3, NULL),
          *v = newGNode("v", 'W', 4, NULL),
          *w = newGNode("w", 'W', 5, NULL),
          *x = newGNode("x", 'W', 6, NULL),
          *y = newGNode("y", 'W', 7, NULL);

    Graph G;
    GNode* nodes[] = {r, s, t, u, v, w, x, y};
    G.adj[0] = (GNodeList){.data = {s, v}, .size = 2};
    G.adj[1] = (GNodeList){.data = {r, w}, .size = 2};
    G.adj[2] = (GNodeList){.data = {w, x, u}, .size = 3};
    G.adj[3] = (GNodeList){.data = {t, x, y}, .size = 3};
    G.adj[4] = (GNodeList){.data = {r}, .size = 1};
    G.adj[5] = (GNodeList){.data = {s, t, x}, .size = 3};
    G.adj[6] = (GNodeList){.data = {w, t, u, y}, .size = 4};
    G.adj[7] = (GNodeList){.data = {x, u}, .size = 2};

    Levels result = level_partition(&G, nodes, s);

    // Print the result
    for (int i = 0; i < result.size; i++) {
        for (int j = 0; j < result.levels[i].size; j++) {
            printf("%s ", result.levels[i].nodes[j]->id);
        }
        printf("\n");
    }

    // Clean up memory
    free(r);
    free(s);
    free(t);
    free(u);
    free(v);
    free(w);
    free(x);
    free(y);

    return 0;
}
