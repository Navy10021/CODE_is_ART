# Alticulation Points : 해당 노드가 없으면 두 개의 그래프로 나눠지는 노드.
class GNode:
    def __init__(self, data, c="W", d=float('inf'), p=None):
        self.data = data
        self.color = c
        self.disc = d  # Discovery time
        self.low = d   # Low-link value : The smallest discovery time reachable from the node including itself.
        self.parent = p

def find_articulation_points(graph):
    articulation_points = set()
    time = 0
    def DFS(current):
        nonlocal time
        children = 0
        current.color = "B"
        current.disc = time
        current.low = time
        time += 1

        for neighbor in graph[current]:
            if neighbor.color == "W":
                children += 1
                neighbor.parent = current

                DFS(neighbor)
                current.low = min(current.low, neighbor.low)

                # Case 1
                if current.parent is None and children > 1:
                    articulation_points.add(current.data)
                # Case 2
                if current.parent is not None and neighbor.low >= current.disc:
                    articulation_points.add(current.data)

            elif neighbor != current.parent:
                current.low = min(current.low, neighbor.disc)

    for start_node in graph:
        if start_node.color == "W":
            DFS(start_node)

    print("Articulation Points:", articulation_points)
    #print("Low link : ", [(node.data, node.disc, node.low) for node in graph])
    return articulation_points

# Example usage
A, B, C, D = GNode('A'), GNode('B'), GNode('C'), GNode('D')
E, F, G = GNode('E'), GNode('F'), GNode('G')

graph = {
    A: [B, C],
    B: [A, D],
    C: [A, D],
    D: [B, C, E, F],
    E: [D, F],
    F: [D, E]
}

find_articulation_points(graph)
