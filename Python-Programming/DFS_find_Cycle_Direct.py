class GNode:
    def __init__(self, data, color="W", dist=-1, fin=-1, parent=None):
        self.data = data
        self.color = color
        self.dist = dist
        self.fin = fin
        self.parent = parent

    def __str__(self):
        return "(" + self.data + ")"


def DFS(graph, curr, visited, path):
    if visited[curr]:
        return True  # Cycle detected: Already visited

    visited[curr] = True  # Mark as visited
    path.append(curr)

    for nxt in graph[curr]:
        if not visited[nxt]:
            if DFS(graph, nxt, visited, path):
                return True

        elif nxt in path:
            # Cycle detected: The neighbor is already in the current path
            print("Cycle found : ", [vertex.data for vertex in path] + [path[0].data], end = "\n")
            return True

    path.pop()  # Backtrack : This step is crucial in DFS! -> Explore Other possible paths(Cycle) in the Graph.
    return False


def has_cycle(graph):
    visited = {node: False for node in graph}

    for node in graph:
        if not visited[node]:
            path = []
            if DFS(graph, node, visited, path):
                return True

    return False


# Example Usage:
A, B, C, D, E = GNode("A"), GNode("B"), GNode("C"), GNode("D"), GNode("E")

# Directed edges
G = dict()
G[A] = [E]
G[B] = [C]
G[C] = [D]
G[D] = [A, B, E]
G[E] = []

if has_cycle(G):
    print("The graph has a cycle.")
else:
    print("The graph does not have a cycle.")
