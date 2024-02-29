#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <algorithm>

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

bool BFS(GNode* start, GNode* target) {
    start->color = 'G';
    start->distance = 0;
    queue<GNode*> Q;
    Q.push(start);

    while (!Q.empty()) {
        GNode* curr = Q.front();
        Q.pop();
        // Sort neighbors lexicographically
        sort(G[curr].begin(), G[curr].end(), [](GNode* a, GNode* b) { return a->data < b->data; });
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

    if (target->distance == -1) {
        cout << "No path found between " << start->data << " and " << target->data << endl;
        return false;
    } else {
        vector<char> path;
        while (target) {
            path.insert(path.begin(), target->data);
            target = target->parent;
        }
        if (path[0] == start->data) {
            cout << "The shortest path: ";
            for (char c : path) {
                cout << c;
                if (c != path.back()) cout << " -> ";
            }
            cout << endl;
            return true;
        } else {
            return false;
        }
    }
}

int main() {
    GNode* A = new GNode('A');
    GNode* B = new GNode('B');
    GNode* C = new GNode('C');
    GNode* D = new GNode('D');
    GNode* E = new GNode('E');
    GNode* F = new GNode('F');
    GNode* H = new GNode('H');

    G[A] = {C, B};
    G[B] = {A, D};
    G[C] = {A, D};
    G[D] = {B, C, E, F};
    G[E] = {D, F};
    G[F] = {D, E};
    G[H] = {};

    GNode* start_vertex = A;
    GNode* target_vertex = H;

    if (BFS(start_vertex, target_vertex)) {
        cout << "Is valid path!" << endl;
    } else {
        cout << "Is NOT valid path." << endl;
    }

    // Deallocate memory
    delete A;
    delete B;
    delete C;
    delete D;
    delete E;
    delete F;
    delete H;

    return 0;
}