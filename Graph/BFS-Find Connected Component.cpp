#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <unordered_map>

using namespace std;

class GNode {
public:
    char data;
    char color; // W -> white, G -> gray(in Queue), B -> black(out Queue)
    int distance;
    GNode* parent;

    GNode(char d, char c = 'W', int dist = -1, GNode* p = nullptr) : data(d), color(c), distance(dist), parent(p) {}
};

vector<vector<char>> BFS_connected_components(unordered_map<GNode*, vector<GNode*>>& G) {
    vector<vector<char>> components;

    for (auto& kv : G) {
        GNode* node = kv.first;
        if (node->color == 'W') {
            vector<char> component;
            queue<GNode*> Q;
            Q.push(node);
            node->color = 'G';

            while (!Q.empty()) {
                GNode* curr = Q.front();
                Q.pop();
                // Lexicographical order
                //sort(G[curr].begin(), G[curr].end(), [](GNode* a, GNode* b) { return a->data < b->data; });
                component.push_back(curr->data);

                for (GNode* nxt : G[curr]) {
                    if (nxt->color == 'W') {
                        nxt->color = 'G';
                        nxt->parent = curr;
                        Q.push(nxt);
                    }
                }
            }

            components.push_back(component);
        }
    }

    return components;
}

int main() {
    GNode* A = new GNode('A');
    GNode* B = new GNode('B');
    GNode* C = new GNode('C');
    GNode* D = new GNode('D');
    GNode* E = new GNode('E');
    GNode* F = new GNode('F');
    GNode* H = new GNode('H');
    GNode* I = new GNode('I');
    GNode* J = new GNode('J');

    unordered_map<GNode*, vector<GNode*>> G;
    G[A] = {C, B};
    G[B] = {A, D};
    G[C] = {A, D};
    G[D] = {B, C, E, F};
    G[E] = {D, F};
    G[F] = {D, E};
    G[H] = {I, J};
    G[I] = {H};
    G[J] = {H};

    vector<vector<char>> res = BFS_connected_components(G);
    
    // Printing the result
    for (const auto& component : res) {
        cout << "[ ";
        for (char data : component) {
            cout << data << " ";
        }
        cout << "]" << endl;
    }

    // Memory cleanup
    for (auto& kv : G) {
        delete kv.first;
    }

    return 0;
}