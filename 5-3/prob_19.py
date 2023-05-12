# Print shortest Path with Dijkstra 
from collections import defaultdict
from heapq import *

def dijkstra(edges, src, dst):
    adj = defaultdict(list)
    # adj = [[] for _ in range(number of Node)]
    # Undirected
    for u, v, cost in edges:
        adj[u].append((cost, v))

    q = [(0, src, ())]    # (cost, start node, path)
    visit_set = set()
    mins = {src : 0}      # {start : cost} / 
    
    while q:
        cur_cost, cur_node, path = heappop(q)
        if cur_node not in visit_set:
            visit_set.add(cur_node)
            path = (cur_node, path)
            if cur_node == dst:
                res = ""
                for char in str(path):
                      if char.isalpha():
                            res += char
                res = list(res[::-1]) 
                return cur_cost, res

            # adj
            for nei_cost, nei_node in adj.get(cur_node, ()):    # 있으면 cur_node 없으면 empty
                if nei_node in visit_set: 
                    continue
                prev = mins.get(nei_node, None) # 있으면 nei_node 없으면 None
                next = cur_cost + nei_cost
                if prev is None or next < prev:
                    mins[nei_node] = next
                    heappush(q, (next, nei_node, path))


    #return path


edges = [
        ("A", "B", 7),
        ("A", "D", 5),
        ("B", "C", 8),
        ("B", "D", 9),
        ("B", "E", 7),
        ("C", "E", 5),
        ("D", "E", 15),
        ("D", "F", 6),
        ("E", "F", 8),
        ("E", "G", 9),
        ("F", "G", 11)]

print("A -> E : " , end="")
print(dijkstra(edges, "A", "E"))
print("A -> G : ", end = "")
print(dijkstra(edges, "A", "G"))





    
