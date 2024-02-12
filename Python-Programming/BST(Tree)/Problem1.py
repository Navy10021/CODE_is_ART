class Node:
    def __init__(self, key):
        self.left = None
        self.right = None
        self.val = key

class Tree:
    def __init__(self):
        self.root = None
    
    def build_tree(self, tree_dict):
        nodes = {}
        
        def create_node(value):
            if value is None:
                return None 
            if value not in nodes:
                nodes[value] = Node(value)
            return nodes[value]
            
        root_key = next(iter(tree_dict)) # first key is root 
        self.root = create_node(root_key)
        
        for parent, (left_child, right_child) in tree_dict.items():
            parent_node = create_node(parent)
            parent_node.left = create_node(left_child)
            parent_node.right = create_node(right_child)
        
    # Binary Tree Structure : NO cycle...    
    def isValid(self):
        visited = set()
        
        def traverse(node):
            if node in visited:
                return False 
            if node:
                visited.add(node)
                return traverse(node.left) and traverse(node.right)
            return True
        
        return traverse(self.root)

    def level_order(self):
        levels = []
        if not self.root:
            return levels
        queue = [(self.root, 0)]
        while queue:
            curr_node, level = queue.pop(0)
            #print(curr_node.val, end=' ')
            levels.append((curr_node.val, level))
            if curr_node.left:
                queue.append((curr_node.left, level+1))
            if curr_node.right:
                queue.append((curr_node.right, level+1))
        
        # convert to dict
        levels_dict = {}
        for node, level in levels:
            if level in levels_dict:
                levels_dict[level].append(node)
            else:
                levels_dict[level] = [node]
        
        return levels_dict
    
    def find_boundary(self):
        
        def find_leaves(node):
            if not node:
                return []
            if not node.left and not node.right:
                return [node.val]
            return find_leaves(node.left) + find_leaves(node.right)
        
        def find_left_boundary(node):
            boundary = []
            while node:
                if node.left or node.right:
                    boundary.append(node.val)
                if node.left:
                    node = node.left 
                else:
                    node = node.right
            return boundary # exclude the leaf 
        
        def find_right_boundary(node):
            boundary = []
            while node:
                if node.left or node.right:
                    boundary.append(node.val)
                if node.right:
                    node = node.right
                else:
                    node = node.left 
            return boundary[::-1]  # reverse
        
        left_boundary = find_left_boundary(self.root.left) if self.root.left else []
        right_boundary = find_right_boundary(self.root.right) if self.root.right else []
        top = [self.root.val]
        bottom = find_leaves(self.root)
        return top + left_boundary + bottom + right_boundary
# Tree edge
T = {
    1: [2, 3],
    2: [4, 5],
    4: [None, None],
    5: [7, 8],
    3: [6, None],
    6: [9, 10],
    7: [None, None],
    8: [None, None],
    9: [None, None],
    10: [None, None],
}

tree = Tree()
tree.build_tree(T)
print("Problem 1 :", end = ' ')
if tree.isValid():
    print("Is Binary Tree.")
else:
    print("Is NOT Binary Tree.")

level_order = tree.level_order()
#print(level_order)

# Next right pointer
print("Problem 2:", end = ' ')
res = []
for node_list in level_order.values():
    res.extend(node_list)
    res.append("#")
print(res)

# Boundary of Binary Tree
print("Problem 3:", end = ' ')
print(tree.find_boundary())