# Mirror the BST 
# Find the closest value
# Path to Given Node 
# Find Nodes at 'K-Distance'

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
    
    def _insert(self, root, key):
        if key < root.val:
            if root.left is None:
                root.left = Node(key)
            else:
                self._insert(root.left, key)
        
        else:
            if root.right is None:
                root.right = Node(key)
            else:
                self._insert(root.right, key)
    
    def search(self, key):
        return self._search(self.root, key)
        
    def _search(self, root, key):
        if root is None or root.val == key:
            return root 
        if key < root.val:
            return self._search(root.left, key)
        else:
            return self._search(root.right, key)
    
    def inorder_traversal(self):
        self._inorder_traversal(self.root)
        print()
    
    def _inorder_traversal(self, root):
        if root:
            self._inorder_traversal(root.left)
            print(root.val, end=" ")
            self._inorder_traversal(root.right)

    # Convert BST to Balanced BST
    def contvert_to_balanced_bst(self):
        # in-order traversal to get the elements in sorted order 
        def store_inorder(node, arr):
            if not node:
                return 
            store_inorder(node.left, arr)
            arr.append(node.val)
            store_inorder(node.right, arr)
        # construct a balanced BST from sorted list of elements
        def sorted_arr_to_bst(arr):
            if not arr:
                return None 
            mid = len(arr) // 2 
            node = Node(arr[mid])
            node.left = sorted_arr_to_bst(arr[:mid])
            node.right = sorted_arr_to_bst(arr[mid+1:])
            return node  # Amaizaing...
        arr = []
        store_inorder(self.root, arr)
        self.root = sorted_arr_to_bst(arr)
    
    # Mirror BST : reverse the tree, turning it its mirror
    def mirror(self):
        def _mirror(node):
            if node:
                node.left, node.right = node.right, node.left
                _mirror(node.left)
                _mirror(node.right)
        _mirror(self.root)
            
    # Find closest value 
    def find_closest_value(self, target):
        def _find_closest(node, target, closest):
            if node is None:
                return closest 
            if abs(target - closest) > abs(target - node.val):
                closest = node.val 
            if target < node.val:
                return _find_closest(node.left, target, closest)
            else:
                return _find_closest(node.right, target, closest)
        
        return _find_closest(self.root, target, self.root.val)
    
    # Find K-Distance nodes
    def find_node_k_distance(self, root, k):
        nodes = []
        def _find(node, k):
            if node is None :
                return
            if k == 0:
                nodes.append(node.val)
            else:
                _find(node.left, k-1)
                _find(node.right, k-1)
        _find(root, k)
        return nodes 
    
    # Path to given node : returns path from the root to the specific value
    # DFS in Tree
    def path_to_given_node(self, value):
        path = []
        def _find_path(node, value):
            if not node:
                return False 
            path.append(node.val)
            if node.val == value:
                return True 
                
            if (_find_path(node.left, value) or _find_path(node.right, value)):
                return True 
            path.pop()  # Bactrack. Remove the node from the path if NOT correct path 
            return False
        if _find_path(self.root, value):
            return path 
        return []   # else no path 
    

bst = BST()
nodes = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
for node in nodes:
    bst.insert(node) # Not balanced...

print("Root of BST : ", bst.root.val)

print("After Balanced BST")
bst.contvert_to_balanced_bst()
print("Root of BST : ", bst.root.val)

# Uncomment these lines to see the effect of mirroring the BST
# bst.mirror()
closest_value = bst.find_closest_value(13)
print("The Closest value to 13:", closest_value)

k_distance_nodes = bst.find_node_k_distance(bst.root, 3)
print("Nodes at 3-distance from root:", k_distance_nodes)

path_to_node = bst.path_to_given_node(8)
print("Path from root to 8:", path_to_node)