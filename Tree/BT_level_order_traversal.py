lc = [0, 2, 4, 6, 0, 0, 0, 0, 0]
rc = [0, 3, 5, 7, 0, 8, 0, 0, 0]

from collections import deque

def BFS(root):
    Q = deque()
    Q.append(root)
    while (Q):
        curr = Q.popleft()
        print(curr, end = " ")
        if (lc[curr]):
            Q.append(lc[curr])
        if (rc[curr]):
            Q.append(rc[curr])
            
BFS(1)
    
