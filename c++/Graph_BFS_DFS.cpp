#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <map>

class Vertex {
public:
    Vertex(const std::string& label) : label(label) {}  // input parameter : string

    std::string getLabel() const {
        return label;
    }

private:
    std::string label;
};

class Graph {
public:
    Graph() {}      // no input parameters

    void addVertex(const std::string& label) {
        if (adjList.find(label) == adjList.end()) {
            adjList[label] = std::vector<std::string>();
        }
    }

    void addEdge(const std::string& from, const std::string& to) {
        addVertex(from);
        addVertex(to);
        adjList[from].push_back(to);
        adjList[to].push_back(from);
    }

    void BFS(const std::string& startLabel, std::map<std::string, unsigned int>& dist){
        std::queue<std::string> Q;
        std::unordered_map<std::string, bool> vis;
        // 초기화
        for (const auto & vertexPair : adjList){
            vis[vertexPair.first] = false;
            dist[vertexPair.first] = -1;
        }
        Q.push(startLabel);
        vis[startLabel] = true;
        dist[startLabel] += 1;

        while(!Q.empty()){
            std::string curr = Q.front(); Q.pop();
            for (const std::string& nxt : adjList[curr]){
                if(!vis[nxt]){
                    vis[nxt] = true;
                    Q.push(nxt);
                    dist[nxt] = dist[curr] + 1;
                }
            }
        }

    }

    void DFS(const std::string& currLabel, unsigned int& timestamp,
             std::map<std::string, unsigned int>& discovery_time,
             std::map<std::string, unsigned int>& finising_time){
            /*
            DFS(st):
                time += 1
                st.discovery_time = time 
                vis[st] = true
                for nxt in adj[st]: if (!vis[nxt])
                time += 1
                st.finishing_time = time
            */
           if (discovery_time.find(currLabel) != discovery_time.end()){
            // Vertex has already been visited : No need vis list
            return;
           }
           discovery_time[currLabel] = ++timestamp; // visited && store time

           for (const std::string& nxt : adjList[currLabel]){
            DFS(nxt, timestamp, discovery_time, finising_time);
           }
           finising_time[currLabel] = ++timestamp;
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


private:
    std::unordered_map<std::string, std::vector<std::string>> adjList;
};

int main() {
    Graph graph;
    graph.addEdge("A", "B");
    graph.addEdge("A", "C");
    graph.addEdge("B", "C");
    graph.addEdge("B", "D");
    graph.addEdge("C", "D");

    graph.printGraph();

    std::map<std::string, unsigned int> distance;
    std::map<std::string, unsigned int> discovery_time;
    std::map<std::string, unsigned int> finishing_time;
    unsigned int timestamp = 0;

    std::cout << "=============== BFS ===============" << "\n";
    graph.BFS("A", distance);
    
    for (const auto& e : distance){
        std::cout << "Vertex " << e.first << ", " << "Distance : " << e.second << "\n";  
    }

    std::cout << "=============== DFS ===============" << "\n";
    graph.DFS("A", timestamp, discovery_time, finishing_time);

    for (const auto& e : discovery_time){
        std::cout << "Vertex " << e.first << "  Discovery time : " << e.second 
                  << ", Finising time : " << finishing_time[e.first] << "\n";
    }

    return 0;
}
