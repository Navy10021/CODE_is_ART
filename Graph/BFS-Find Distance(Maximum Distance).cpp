#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

class GNode {
public:
    char data;
    char color; // 'W' -> white, 'G' -> gray(in Queue), 'B' -> black(out Queue)
    int distance;
    GNode* parent;

    GNode(char d, char c = 'W', int dist = -1, GNode* p = nullptr) : data(d), color(c), distance(dist), parent(p) {}

    ~GNode() {
        // Deallocate memory if needed
    }
};

unordered_map<GNode*, vector<GNode*>> G;

int BFS(GNode* start) {
    start->color = 'G';
    start->distance = 0;
    queue<GNode*> Q;
    Q.push(start);

    while (!Q.empty()) {
        GNode* curr = Q.front();
        Q.pop();
        for (GNode* nxt : G[curr]) {
            if (nxt->color == 'W') {
                nxt->color = 'G';
                nxt->distance = curr->distance + 1;
                nxt->parent = curr;
                Q.push(nxt);
            }
        }
        curr->color = 'B';
    }

    int max_depth = 0;
    for (auto& pair : G) {
        max_depth = max(max_depth, pair.first->distance);
    }
    return max_depth;
}

int find_max_depth() {
    int max_depth = 0;
    for (auto& pair : G) {
        for (auto& node : G) {
            node.first->color = 'W';
            node.first->distance = -1;
            node.first->parent = nullptr;
        }
        int res = BFS(pair.first);
        max_depth = max(max_depth, res);
    }
    return max_depth;
}

int main() {
    GNode* A = new GNode('A');
    GNode* B = new GNode('B');
    GNode* C = new GNode('C');
    GNode* D = new GNode('D');
    GNode* E = new GNode('E');
    GNode* F = new GNode('F');

    G[A] = {C, B};
    G[B] = {A, D};
    G[C] = {A};
    G[D] = {B, E, F};
    G[E] = {D, F};
    G[F] = {D, E};

    int max_depth = find_max_depth();

    cout << "All BFS is Done." << endl;
    cout << "Maximum Depth: " << max_depth << endl;

    // Deallocate memory
    delete A;
    delete B;
    delete C;
    delete D;
    delete E;
    delete F;

    return 0;
}