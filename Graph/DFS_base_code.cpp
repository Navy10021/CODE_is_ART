#include <iostream>
#include <vector>
#include <map>

class GNode {
public:
    std::string id;
    std::string color;
    int dist;
    int fin;
    GNode* parent;

    GNode(std::string _id, std::string c = "W", int d = -1, int f = -1, GNode* p = nullptr)
        : id(_id), color(c), dist(d), fin(f), parent(p) {}

    std::string toString() {
        if (parent != nullptr) {
            return "(" + id + ", " + color + ", (" + std::to_string(dist) + ", " + std::to_string(fin) + "), " + parent->id + ")";
        } else {
            return "(" + id + ", " + color + ", (" + std::to_string(dist) + ", " + std::to_string(fin) + "), None)";
        }
    }
};

void printG(std::map<GNode*, std::vector<GNode*>>& g) {
    std::cout << "====================================================" << std::endl;
    for (const auto& entry : g) {
        std::cout << entry.first->id << ": ";
        for (const GNode* u : entry.second) {
            std::cout << u->id << " ";
        }
        std::cout << std::endl;
    }
}

int time = 0;

void DFS(std::map<GNode*, std::vector<GNode*>>& G, GNode* st) {
    // 시작점 방문표시
    time += 1;
    st->dist = time;
    st->color = "G";
    printG(G);
    for (GNode* nxt : G[st]) {
        if (nxt->color == "W") {
            nxt->parent = st;
            DFS(G, nxt);
        }
    }
    st->color = "B";
    time += 1;
    st->fin = time;
    printG(G);
}

int main() {
    GNode u("u"), v("v"), w("w");
    GNode x("x"), y("y"), z("z");

    std::map<GNode*, std::vector<GNode*>> G;
    G[&u] = {&v, &x};
    G[&v] = {&y};
    G[&w] = {&y, &z};
    G[&x] = {&v};
    G[&y] = {&x};
    G[&z] = {&z};

    for (auto& vertex : G) {
        if (vertex.first->color == "W") {
            DFS(G, vertex.first);
        }
    }

    return 0;
}
