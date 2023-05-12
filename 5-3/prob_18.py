# The shortest path algorithm
# Dijkstra with Heap
import heapq
class Graph:
    def __init__(self, N):
        self.N = N
        self.adj = [[] for _ in range(N)]

    # Undirected Graph
    def add_edge(self, u, v, w):
        self.adj[u].append((v, w))
        self.adj[v].append((u, w))
    
    def shortest_path(self, src):
        # Distance
        minH = [(0, src)]   # cost, start node
        # Initialize visit list
        dist = [float("inf")] * self.N
        dist[src] = 0
        # parent array to store shortest node
        #parents = [-1] * self.N
        parents = [[] for _ in range(self.N)]
        #parents[src] = None
        
        while minH:
            cost, curNode = heapq.heappop(minH)

            for nei, nei_cost in self.adj[curNode]:
                if dist[nei] > dist[curNode] + nei_cost:
                    parents[curNode].append(nei)
                    dist[nei] = dist[curNode] + nei_cost
                    heapq.heappush(minH, (dist[nei], nei))
        

        # print shortest distance stored in dist(visit list)
        for end in range(self.N):
            
            print("{} -> {} : short cost is {}".format(src, end, dist[end]))
        
        return parents

        
Node_num = 9
Node_start = 0
g = Graph(Node_num)
# making above shown graph
g.add_edge(0, 1, 4)
g.add_edge(0, 7, 8)
g.add_edge(1, 2, 8)
g.add_edge(1, 7, 11)
g.add_edge(2, 3, 7)
g.add_edge(2, 8, 2)
g.add_edge(2, 5, 4)
g.add_edge(3, 4, 9)
g.add_edge(3, 5, 14)
g.add_edge(4, 5, 10)
g.add_edge(5, 6, 2)
g.add_edge(6, 7, 1)
g.add_edge(6, 8, 6)
g.add_edge(7, 8, 7)      

print(g.shortest_path(Node_start))
