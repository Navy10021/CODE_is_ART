#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class GNode {
public:
    char data;
    char color;
    GNode(char d, char c = 'W') : data(d), color(c) {}
};

vector<vector<char>> find_all_paths(unordered_map<GNode*, vector<GNode*>>& G, GNode* start, GNode* end, vector<char>& path) {
    vector<vector<char>> paths;
    if (path.empty()) {
        path.push_back(start->data);
    }
    if (start == end) {
        paths.push_back(path);
        return paths;
    }
    if (G.find(start) == G.end()) {
        return paths;
    }

    for (GNode* nxt : G[start]) {
        if (find(path.begin(), path.end(), nxt->data) == path.end()) {
            vector<char> new_path = path;
            new_path.push_back(nxt->data);
            auto new_paths = find_all_paths(G, nxt, end, new_path);
            paths.insert(paths.end(), new_paths.begin(), new_paths.end());
        }
    }
    return paths;
}

int main() {
    GNode A('A'), B('B'), C('C'), D('D'), E('E'), F('F');

    unordered_map<GNode*, vector<GNode*>> G;
    G[&A] = {&B, &D};
    G[&B] = {&A, &D};
    G[&C] = {&A, &D};
    G[&D] = {&B, &C, &F, &E};
    G[&E] = {&D, &F};
    G[&F] = {&D, &E};

    GNode* start_vertex = &A;
    GNode* end_vertex = &F;
    vector<char> path;
    auto all_paths = find_all_paths(G, start_vertex, end_vertex, path);
    for (const auto& p : all_paths) {
        for (char node : p) {
            cout << node << " ";
        }
        cout << endl;
    }
    return 0;
}