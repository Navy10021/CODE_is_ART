#include <iostream>
#include <vector>
#include <queue>
#include <map>

class GNode {
public:
    std::string id;
    std::string color;
    int distance;
    GNode* parent;

    GNode(std::string _id, std::string c = "White", int d = -1, GNode* p = nullptr)
        : id(_id), color(c), distance(d), parent(p) {}

    std::string toString() {
        if (parent != nullptr) {
            return "(" + id + ", " + color + ", " + std::to_string(distance) + ", " + parent->id + ")";
        } else {
            return "(" + id + ", " + color + ", " + std::to_string(distance) + ", None)";
        }
    }
};

void printGraph(std::map<GNode*, std::vector<GNode*>>& g) {
    std::cout << "==============================================" << std::endl;
    for (const auto& entry : g) {
        std::cout << entry.first->id << ": ";
        for (const GNode* u : entry.second) {
            std::cout << u->id << " ";
        }
        std::cout << std::endl;
    }
}

void printQ(std::queue<GNode*>& q) {
    std::cout << "Q = ";
    while (!q.empty()) {
        std::cout << q.front()->id << " ";
        q.pop();
    }
    std::cout << std::endl;
}

void BFS(std::map<GNode*, std::vector<GNode*>>& G, GNode* st) {
    for (auto& entry : G) {
        entry.first->color = "White";
        entry.first->distance = -1;
        entry.first->parent = nullptr;
    }

    st->color = "Gray";
    st->distance = 0;
    std::queue<GNode*> Q;
    Q.push(st);

    printGraph(G);
    printQ(Q);

    while (!Q.empty()) {
        GNode* curr = Q.front();
        Q.pop();

        for (GNode* nxt : G[curr]) {
            if (nxt->color == "White") {
                nxt->color = "Gray";
                nxt->distance = curr->distance + 1;
                nxt->parent = curr;
                Q.push(nxt);
            }
        }
        curr->color = "Black";

        printGraph(G);
        printQ(Q);
    }
}

int main() {
    GNode r("r");
    GNode s("s");
    GNode t("t");
    GNode u("u");
    GNode v("v");
    GNode w("w");
    GNode x("x");
    GNode y("y");

    std::map<GNode*, std::vector<GNode*>> G;
    G[&r] = {&s, &v};
    G[&s] = {&w, &r};
    G[&t] = {&w, &x, &u};
    G[&u] = {&t, &x, &y};
    G[&v] = {&r};
    G[&w] = {&s, &t, &x};
    G[&x] = {&w, &t, &u, &y};
    G[&y] = {&x, &u};

    BFS(G, &s);

    return 0;
}
