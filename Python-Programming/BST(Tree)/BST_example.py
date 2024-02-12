class Node:
    def __init__(self, key):
        self.left = None
        self.right = None
        self.val = key

class BST:
    def __init__(self):
        self.root = None
    
    def insert(self, key):
        if self.root is None:
            self.root = Node(key)
        else:
            self._insert(self.root, key)
    
    def _insert(self, curr_node, key):
        if key < curr_node.val:
            if curr_node.left is None:
                curr_node.left = Node(key)
            else:
                self._insert(curr_node.left, key)
                
        elif key > curr_node.val:
            if curr_node.right is None:
                curr_node.right = Node(key)
            else:
                self._insert(curr_node.right, key)
    
    def build_bst_tree(self, tree_dict):
        for key in tree_dict:
            self.insert(key)
            for child in tree_dict[key]:
                if child is not None:
                    self.insert(child)
        
    def isValid(self):
        def validate(node, low = float('-inf'), high = float('inf')):
            if not node:
                return True 
            if not (low < node.val < high):
                return False 
            return (validate(node.left, low, node.val) and validate(node.right, node.val, high))
        return validate(self.root)

    def print_level_order(self):
        levels = []
        if not self.root:
            return levels
        queue = [(self.root, 0)]
        while queue:
            curr_node, level = queue.pop(0)
            print(curr_node.val, end=' ')
            levels.append((curr_node.val, level))
            if curr_node.left:
                queue.append((curr_node.left, level+1))
            if curr_node.right:
                queue.append((curr_node.right, level+1))
        return levels

# Tree edge
T = {
    10: [12, 15],
    12: [25, 30],
    15: [36, None],
    25: [None, None],
    30: [None, None],
    36: [None, None]
}

bst = BST()
bst.build_bst_tree(T)
if (bst.isValid()):
    print("is valid BST\n")
else:
    print("is NOT valid BST")
level_order = bst.print_level_order()
print("\nLevel order as list of tuples (value, level):")
print(level_order)