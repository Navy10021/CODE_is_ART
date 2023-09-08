def canFinish(numCourses, prerequisites):
    def hasCycle(course):
        if visited[course] == 1:
            return True
        if visited[course] == -1:
            return False

        visited[course] = 1
        for prereq in graph[course]:
            if hasCycle(prereq):
                return True
        visited[course] = -1
        return False

    graph = [[] for _ in range(numCourses)]
    for course, prereq in prerequisites:
        graph[course].append(prereq)

    visited = [0] * numCourses

    for course in range(numCourses):
        if not visited[course]:
            if hasCycle(course):
                return False

    return True

# Example usage:
numCourses = 4
prerequisites = [[1, 0], [2, 1], [3, 2]]

print(canFinish(numCourses, prerequisites))  # Should return True
