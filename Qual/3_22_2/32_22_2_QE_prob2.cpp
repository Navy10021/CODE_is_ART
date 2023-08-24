#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

class GNode {
public:
    std::string id;
    GNode(std::string id) : id(id) {}
};

typedef std::unordered_map<GNode*, std::vector<GNode*>> Graph;

void backtracking(const Graph& G, GNode* st, GNode* tgt, std::vector<std::string>& tmp, std::vector<std::vector<std::string>>& ans) {
    if (st == tgt) {
        ans.push_back(tmp);
        return;
    }
    for (GNode* adj : G.at(st)) {
        tmp.push_back(adj->id);
        backtracking(G, adj, tgt, tmp, ans);
        tmp.pop_back();
    }
}

std::vector<std::vector<std::string>> paths(const Graph& G, GNode* s, GNode* t) {
    std::vector<std::vector<std::string>> ans;
    std::vector<std::string> tmp;
    tmp.push_back(s->id);
    backtracking(G, s, t, tmp, ans);
    return ans;
}

int main() {
    GNode a("a"), b("b"), c("c"), d("d");
    Graph G;
    G[&a] = {&b, &c};
    G[&b] = {&d};
    G[&c] = {};
    G[&d] = {&c};

    std::vector<std::vector<std::string>> result = paths(G, &a, &c);

    for (const auto& path : result) {
        for (const auto& node : path) {
            std::cout << node << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}
