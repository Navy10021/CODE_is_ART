#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NODES 100

typedef struct GNode {
    char id;
    char color;
    int d;
    int f;
    struct GNode* parent;
} GNode;

GNode* createGNode(char id) {
    GNode* newNode = (GNode*) malloc(sizeof(GNode));
    newNode->id = id;
    newNode->color = 'W';
    newNode->d = -1;
    newNode->f = -1;
    newNode->parent = NULL;
    return newNode;
}

bool find = false;
char output[MAX_NODES];
int outputIndex = 0;

void dfs(GNode* G[MAX_NODES][MAX_NODES], GNode* st, GNode* en) {
    if (find) return;

    st->color = 'K';
    output[outputIndex++] = st->id;

    for (int i = 0; i < MAX_NODES; i++) {
        if (G[(int)(st->id - 'a')][i] == NULL || G[(int)(st->id - 'a')][i]->color == 'K') continue;

        G[(int)(st->id - 'a')][i]->color = 'K';
        if (G[(int)(st->id - 'a')][i] == en) {
            find = true;
            output[outputIndex++] = en->id;
            return;
        }
        dfs(G, G[(int)(st->id - 'a')][i], en);
    }
}

char* lexSmallest(GNode* G[MAX_NODES][MAX_NODES], GNode* t, GNode* v) {
    find = false;
    memset(output, 0, sizeof(output));
    outputIndex = 0;
    dfs(G, t, v);
    return output;
}

int main() {
    GNode* r = createGNode('r');
    GNode* s = createGNode('s');
    GNode* t = createGNode('t');
    GNode* u = createGNode('u');
    GNode* v = createGNode('v');
    GNode* w = createGNode('w');
    GNode* x = createGNode('x');
    GNode* y = createGNode('y');

    GNode* G[MAX_NODES][MAX_NODES] = {0};

    G[(int)(r->id - 'a')][0] = w;
    G[(int)(r->id - 'a')][1] = v;
    G[(int)(w->id - 'a')][0] = s;
    G[(int)(w->id - 'a')][1] = r;
    G[(int)(w->id - 'a')][2] = t;
    G[(int)(t->id - 'a')][0] = w;
    G[(int)(t->id - 'a')][1] = s;
    G[(int)(t->id - 'a')][2] = x;
    G[(int)(u->id - 'a')][0] = y;
    G[(int)(v->id - 'a')][0] = r;
    G[(int)(s->id - 'a')][0] = w;
    G[(int)(s->id - 'a')][1] = t;
    G[(int)(s->id - 'a')][2] = x;
    G[(int)(x->id - 'a')][0] = s;
    G[(int)(x->id - 'a')][1] = t;
    G[(int)(y->id - 'a')][0] = u;

    printf("%s\n", lexSmallest(G, t, v));
    printf("%s\n", lexSmallest(G, u, u));
    printf("%s\n", lexSmallest(G, x, y));

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
