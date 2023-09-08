class Graph:
    def __init__(self, vertices):
        self.vertices = vertices    # 정점 개수 
        self.adj_list = {vertex : [] for vertex in range(vertices)}
    
    def add_edge(self, u, v):       # u -> v
        self.adj_list[u].append(v)
    
    def has_cycle(self):
        vis = [False] * self.vertices
        recursion_stack = [False] * self.vertices
        
        def DFS(curr):
            vis[curr] = True 
            recursion_stack[curr] = True 
            
            for nxt in self.adj_list[curr]:
                if not vis[nxt]:
                    if DFS(nxt):
                        return True
                elif recursion_stack[nxt]:
                    return True 
            
            recursion_stack[curr] = False 
            return False
        
        for vertex in range(self.vertices):
            if not vis[vertex]:
                if DFS(vertex):
                    return True 
        
        return False  
    
# Example usage:
g = Graph(4)
g.add_edge(0, 1)
g.add_edge(1, 2)
g.add_edge(2, 0)
g.add_edge(2, 3)

if g.has_cycle():
    print("Graph contains a cycle")
else:
    print("Graph does not contain a cycle")
