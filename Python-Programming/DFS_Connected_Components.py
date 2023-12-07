class GNode:
    def __init__(self, data, color="W"):
        self.data = data
        self.color = color

    def __str__(self):
        return "(" + str(self.data) + ")"
    

def DFS(graph, curr, component):
    curr.color = "G"
    component.append(curr.data)
    # Lexicographical order: Sorting adj List
    graph[curr] = sorted(graph[curr], key=lambda x: x.data)
    
    for nxt in graph[curr]:
        if nxt.color == "W":
            DFS(graph, nxt, component)


def Connected_vertex(graph):
    components = []
    
    for vertex in graph:
        if vertex.color == "W":
            connected = []
            DFS(graph, vertex, connected)
            components.append(connected)
            
    return components


# Example undirected graph
A, B, C, D, E, F, G, H = GNode("A"), GNode("B"), GNode("C"), GNode("D"), GNode("E"), GNode("F"), GNode("G"), GNode("H")

undirected_graph = {
    A: [B, C],
    B: [A, D],
    C: [A, D],
    D: [B, C],
    E: [F],
    F: [E],
    G: [H],
    H: [G]
}

res = Connected_vertex(undirected_graph)

print(res)
