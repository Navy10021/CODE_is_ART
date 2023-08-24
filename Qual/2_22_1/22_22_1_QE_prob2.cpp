#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <string>

using namespace std;



class GNode {
public:
    string id;
    char color; // 'W', 'B'
    int distance;
    GNode* parent;

    GNode(string id, char color = 'W', int d = 0, GNode* p = nullptr)
        : id(id), color(color), distance(d), parent(p) {}
};

vector<vector<GNode*>> level_partition(unordered_map<GNode*, vector<GNode*>>& G, GNode* s) {
    queue<GNode*> q;
    q.push({s}); s->color = 'B';
    vector<vector<GNode*>> vv;
    vector <GNode*> v; v.push_back(s); vv.push_back(v);
    while (!q.empty()){
        vector<GNode*> level; int lv_size = q.size();
        for(int i = 0; i < lv_size; i++){
            GNode* node = q.front(); q.pop();
            for (auto adj : G[node]){
                if (adj->color == 'B') continue;
                adj -> color = 'B';
                level.push_back(adj);
                q.push(adj);
            }
        }
        vv.push_back(level);
    }
    return vv;
}

int main() {
    GNode *r = new GNode("r"), *s = new GNode("s"), *t = new GNode("t"), 
          *u = new GNode("u"), *v = new GNode("v"), *w = new GNode("w"), 
          *x = new GNode("x"), *y = new GNode("y");

    unordered_map<GNode*, vector<GNode*>> G;
    G[r] = {s, v};
    G[s] = {r, w};
    G[t] = {w, x, u};
    G[u] = {t, x, y};
    G[v] = {r};
    G[w] = {s, t, x};
    G[x] = {w, t, u, y};
    G[y] = {x, u};

    auto result = level_partition(G, s);

    // Print the result
    // you should print : s / r w / v t x / u y
    for (auto& level : result) {
        for (auto node : level) {
            cout << node->id << " ";
        }
        cout << endl;
    }

    // Clean up memory
    delete r, s, t, u, v, w, x, y;

    return 0;
}