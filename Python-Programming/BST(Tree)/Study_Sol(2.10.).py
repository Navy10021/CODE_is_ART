# 1번 문제 솔루션
def isValidTree(dictionary):
    def FindtheRootNode(dic):
        gr_parents = set()
        gr_children = set()

        for node, children in dic.items():
          if node not in gr_parents:
            gr_parents.add(node)
          for child in children:
            if child not in gr_children:
              gr_children.add(child)

        num_root = 0 # 루트 개수 
        for parent in gr_parents:
          if parent not in gr_children:
            num_root += 1
            root_node = parent

        if num_root != 1:
          return False, None
        else:
          return True, root_node
    
    if FindtheRootNode(dictionary)[0] != True:
      return False

    if FindtheRootNode(dictionary)[0] == True:
      root_node = FindtheRootNode(dictionary)[1]
   
    num_nodes = len(dictionary)

    # Check for cycles using a depth-first search

    visited = set()
    has_cycle = False

    def dfs(node, parent):
        global has_cycle
        if node not in visited:
            visited.add(node)
            for neighbor in dictionary[node]:
                if neighbor is not None and neighbor != parent:
                    if neighbor in visited:
                        has_cycle = True
                        return
                    dfs(neighbor, node)

    # Start DFS from the root node
    dfs(root_node, None)

    # Check for connectivity and count edges
    num_edges = 0
    for node, neighbors in dictionary.items():
        num_edges += sum(neighbor is not None for neighbor in neighbors)

    # A valid tree has no cycles, is connected, and all nodes are reachable from the root
    return not has_cycle and num_edges == num_nodes - 1 and len(visited) == num_nodes

# 2번 문제 솔루션
def NextRightPointer(root):
        if root is None:
            return root
        q = list(root)
        while q:
            point = None
            for _ in range(len(q)):
                node = q.pop(0)
                if point:
                    point.next = node
                point = node
                if node.left:
                    q.append(node.left)
                if node.right:
                    q.append(node.right)
        return root

# 3번 문제 솔루션
def SumupBoundary(root):
    def add_leaves(root):
        if is_leaf(root):
            res.append(root.val)
            return
        if root.left:
            add_leaves(root.left)
        if root.right:
            add_leaves(root.right)

    def is_leaf(node):
        return node and node.left is None and node.right is None

    res = []
    if not root:
        return res

    if not is_leaf(root):
        res.append(root.val)

    t = root.left
    while t:
        if not is_leaf(t):
         res.append(t.val)
        t = t.left if t.left else t.right
    
    # leaves
    add_leaves(root)

    # right boundary(reverse order)
    s = []
    t = root.right
    while t:
        if not is_leaf(t):
            s.append(t.val)
        t = t.right if t.right else t.left
    while s:
     res.append(s.pop())
    
    # output
    return res
