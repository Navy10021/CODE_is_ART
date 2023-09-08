#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <algorithm>

using namespace std;

struct GNode {
    string id;
    char color;
    int distance;
    GNode* parent;

    GNode(string _id, char c = 'W', int d = -1, GNode* p = nullptr)
        : id(_id), color(c), distance(d), parent(p) {}
};

// Function to perform BFS traversal in ascending order
void BFSAscending(map<GNode*, vector<GNode*>>& graph, GNode* start) {
    queue<GNode*> q;
    
    // Initialize all nodes
    for (auto& entry : graph) {
        GNode* node = entry.first;
        node->color = 'W';
        node->distance = -1;
        node->parent = nullptr;
    }

    start->color = 'G';
    start->distance = 0;
    q.push(start);

    while (!q.empty()) {
        GNode* curr = q.front();
        q.pop();
        cout << curr->id << "(" << curr->distance << ") ";

        // Sort the adjacent nodes in ascending order based on their IDs
        vector<GNode*>& adjNodes = graph[curr];
        sort(adjNodes.begin(), adjNodes.end(), [](GNode* a, GNode* b) {
            return a->id < b->id;
            //return a->id > b->id;     // descending order
        });

        for (GNode* nxt : adjNodes) {
            if (nxt->color == 'W') {
                nxt->color = 'G';
                nxt->distance = curr->distance + 1;
                nxt->parent = curr;
                q.push(nxt);
            }
        }
        curr->color = 'B';
    }
}

int main() {
    GNode r("r"), s("s"), t("t"), u("u"), v("v"), w("w"), x("x"), y("y");

    map<GNode*, vector<GNode*>> graph;
    graph[&r] = { &w, &v };
    graph[&w] = { &s, &r, &t };
    graph[&t] = { &s, &x, &w };
    graph[&u] = { &y };
    graph[&v] = { &r };
    graph[&s] = { &w, &t, &x };
    graph[&x] = { &s, &t };
    graph[&y] = { &u };

    BFSAscending(graph, &s);

    return 0;
}

