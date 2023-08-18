#include <iostream>
#include <vector>
#include <map>
#include <stack>

// Vertex Class
class Vertex{
    private:
        std::string name;

    public: 
        // _name 변수 입력
        Vertex(const std::string& _name) : name(_name){}
        // Vertex(name)을 return
        std::string getName() const{
            return name;
        }
};

class Graph{
    private:
        // adjList : map<Vertex(curr) : [Vertex(nxt)], ...>
        std::map<std::string, std::vector<std::string>> adjList;
        //std::map<std::string, Vertex> vertices;

    public:
        // 입력값을 받지 않음
        Graph() {}

        // Vertex를 adjList에 추가하는 함수 
        void addVertex(const std::string& name){
            if (adjList.find(name) == adjList.end()){
                adjList[name] = std::vector<std::string>();
                //vertices[name] = Vertex(name);
            }
        }
        // Vertex간 연결하는 함수(Directed Graph)
        void addEdge(const std::string& u, const std::string& v){
            addVertex(u);
            addVertex(v);
            adjList[u].push_back(v);    // u -> v
        }

        // Cycle 여부를 확인하는 함수
        bool hasCycle(){
            std::map<std::string, bool> vis;
            std::map<std::string, bool> recStack;

            for (const auto& vertexPair : adjList){
                if (hasCycleDFS(vertexPair.first, vis, recStack)){
                    return true;
                }
            }
            return false;
        }

        // DFS를 활용한 Cycle Detection
        bool hasCycleDFS(const std::string& curr,
                         std::map<std::string, bool>& vis,
                         std::map<std::string, bool>& recStack){
            /*
            vis[curr] = true;
            resStack[curr] = true;

            for (const std::string& nxt : adjList[curr]){
                if(!vis[nxt]){
                    if (hasCycleDFS(nxt, vis, recStack)){
                        return true;
                    }
                    else if (recStack[nxt]){
                        return true;
                    }
                }
                recStack[curr] = false;
                return false;
            }
            */
            if (!vis[curr]){
                vis[curr] = true;
                recStack[curr] = true;

                for (const std::string& nxt : adjList[curr]){
                    // case 0: 방문하지 않은 Vertex를 recursion
                    if (!vis[nxt] && hasCycleDFS(nxt, vis, recStack)){
                        return true;
                    }
                    // case 1 : 재방문한 경우 true
                    else if (recStack[nxt]){
                        return true;
                    }
                }
            }
            // curr Vertex 확인 종료
            recStack[curr] = false;
            return false;
        }
        // DFS 탐색 함수
        void topologicalSortDFS(const std::string& curr,
                            std::map<std::string, bool>& vis,
                            std::stack<std::string>& resStack) {
        vis[curr] = true;

        for (const std::string& nxt : adjList[curr]) {
            if (!vis[nxt]) {
                topologicalSortDFS(nxt, vis, resStack);
            }
        }

        resStack.push(curr);
    }

        // 방문하지 않은 Vertex에 대해 topologicalDFS 수행 && 순서 뒤집기
        std::vector<std::string> topologicalSort() {
            std::map<std::string, bool> vis;
            std::stack<std::string> resStack;

            for (const auto& vertexPair : adjList) {
                if (!vis[vertexPair.first]) {
                    topologicalSortDFS(vertexPair.first, vis, resStack);
                }
            }

            std::vector<std::string> sorted;
            while (!resStack.empty()) {
                sorted.push_back(resStack.top());
                resStack.pop();
            }
            return sorted;
    }

        void printGraph() {
            for (const auto& e : adjList) {
                std::cout << "Vertex " << e.first << " -> ";
                for (const std::string& neighbor : e.second) {
                    std::cout << neighbor << " ";
                }
                std::cout << "\n";
            }
        }
};

int main() {
    Graph graph;
    graph.addEdge("A", "B");
    graph.addEdge("A", "C");
    graph.addEdge("B", "D");
    graph.addEdge("C", "E");
    graph.addEdge("C", "D");
    graph.addEdge("D", "F");

    std::cout << "Graph Cycle Detection : \n";
    if (graph.hasCycle()) {
        std::cout << "The graph has a Cycle.\n";
    } else {
        std::cout << "The graph does NOT have a cycle.\n";
    }

    std::cout << "Topological sorting order : \n";
    std::vector<std::string> res = graph.topologicalSort();
    for (const std::string& vertex : res) {
        std::cout << vertex << " ";
    }
    std::cout << "\n";

    return 0;
}
