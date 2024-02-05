class Vertex:
    def __init__(self, label):
        self.label = label
        self.color = None

def graph_coloring(graph):
    max_color = 0
    vertex_colors = {}
    
    for vertex in graph.keys():
        available_colors = [True] * len(graph)
        for neighbor in graph[vertex]:
            if neighbor.color is not None:
                available_colors[neighbor.color] = False
        for color, available in enumerate(available_colors):
            if available:
                vertex.color = color
                vertex_colors[vertex.label] = color
                max_color = max(max_color, color)
                break
                
    return vertex_colors, max_color + 1  # +1 because colors start at 0

# Example usage
A = Vertex('A')
B = Vertex('B')
C = Vertex('C')
D = Vertex('D')
E = Vertex('E')

# Example graph: A simple undirected graph
graph = {
    A: [B, C],
    B: [A, D, E],
    C: [A, D],
    D: [B, C, E],
    E: [B, D]
}

vertex_colors, total_colors = graph_coloring(graph)

print("Vertex Colors:", {vertex: color for vertex, color in vertex_colors.items()})
print("Total Colors Used:", total_colors)