#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;

class GNode {
public:
    string id;
    string color;
    int d, f;
    GNode* parent;

    GNode(string id, string color = "W", int d = -1, int f = -1, GNode* p = nullptr)
        : id(id), color(color), d(d), f(f), parent(p) {}
};

vector<GNode*> slicing(vector<GNode*>& arr, int X, int Y)
{
    auto start = arr.begin() + X;
    auto end = arr.begin() + Y;
    vector<GNode*> result(Y - X);
    copy(start, end, result.begin());
    return result;
}


void merge(vector<GNode*>& v, int first, int mid, int last) {
    int k = first;
    vector<GNode*> sub1 = slicing(v, first, mid + 1);
    vector<GNode*> sub2 = slicing(v, mid + 1, last + 1);
    int i = 0;
    int j = 0;
    while (i < sub1.size() && j < sub2.size()) {
        if (sub1[i]->id <= sub2[j]->id) { // Compare based on the id field
            v[k] = sub1[i];
            i = i + 1;
        }
        else {
            v[k] = sub2[j];
            j = j + 1;
        }
        k = k + 1;
    }
    if (i < sub1.size()) {
        for (; i < sub1.size(); i++) {
            v[k] = sub1[i];
            k = k + 1;
        }
    }
    if (j < sub2.size()) {
        for (; j < sub2.size(); j++) {
            v[k] = sub2[j];
            k = k + 1;
        }
    }
}


void mergeSortHelp(vector<GNode*>& v, int first, int last){
    if (first == last)
        return ;
    else{
        int mid = first + (last-first) / 2;
        mergeSortHelp(v, first, mid);
        mergeSortHelp(v, mid+1, last);
        merge(v, first, mid, last);
    }
}

void mergeSort(vector<GNode*>& v){
    mergeSortHelp(v, 0, v.size()-1);
}



bool flag = false;
vector<string> out;

void dfs(GNode* st, GNode* en, unordered_map<GNode*, vector<GNode*>> &G) {
    if (flag) return;
    st->color = "K";
    out.push_back(st->id);
    for (GNode* nxt : G[st]) {
        if (nxt->color == "K") continue;
        nxt->color = "K";
        if (nxt == en) {
            flag = true;
            out.push_back(nxt->id);
            return;
        }
        dfs(nxt, en, G);
    }
}

vector<string> LexSmallest(unordered_map<GNode*, vector<GNode*>> &G, GNode* t, GNode* v) {
    out.clear();
    flag = false;

    if (t == v) return {t->id};

    dfs(t, v, G);
    // for (auto& nd : G) {
    //     mergeSort(nd.second); -> 이것도 가능
    // }

    for (auto &nd : G) {
        sort(nd.second.begin(), nd.second.end(), [](GNode *a, GNode *b) {
            return a->id < b->id;
        });
    }
    if (flag) {
        return out;
    }
    else {
        return {};
    }
}



// rest of the code remains the same
int main() {
    GNode r("r"), s("s"), t("t"), u("u");
    GNode v("v"), w("w"), x("x"), y("y");
    unordered_map<GNode*, vector<GNode*>> G;
    G[&r] = {&w, &v}; G[&w] = {&s, &r, &t}; G[&t] = {&x, &w, &s}; G[&u] = {&y};
    G[&v] = {&r}; G[&s] = {&w, &t, &x}; G[&x] = {&s, &t}; G[&y] = {&u};

    auto result1 = LexSmallest(G, &t, &v);
    for (const auto &id : result1) {
        cout << id << " ";
    }
    cout << '\n';

    auto result2 = LexSmallest(G, &u, &u);
    for (const auto &id : result2) {
        cout << id << " ";
    }
    cout << '\n';

    auto result3 = LexSmallest(G, &x, &y);
    for (const auto &id : result3) {
        cout << id << " ";
    }
    cout << '\n';

    return 0;
}