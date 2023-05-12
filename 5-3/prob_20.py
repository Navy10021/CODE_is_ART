# Course Schedule : 위상정렬(Topological Sort)
# prerequisites[i] = [ai, bi] : bi -> ai
# Return the ordering of courses you should take to finish all courses. 

from collections import deque

def find_order(numCourses, prerequisites):
    # initialize indegree
    indegree = [0]*numCourses
    edge = [[] for _ in range(numCourses)]
    for crs, pre in prerequisites:
        edge[pre].append(crs)   # pre -> crs
        indegree[crs] += 1      # 진입차수 += 1
    
    # Topological sort
    res = []
    q = deque()
    for i in range(0, numCourses):
        if indegree[i] == 0:
            q.append(i)
    
    while q:
        curNode = q.popleft()
        res.append(curNode)
        for nei in edge[curNode]:
            indegree[nei] -= 1
            if indegree[nei] == 0:
                q.append(nei)

    return res if len(res) == numCourses else -1

print(find_order(4, [[1,0],[2,0],[3,1],[3,2]]))
print(find_order(1, []))
print(find_order(2, [[1,0]]))
