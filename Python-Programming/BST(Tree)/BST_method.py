# Binary Search Tree 
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
            
    def delete(self, key):
        self.root = self._delete(self.root, key)
    
    def _delete(self, root, key):
        if root is None:
            return root 
        
        if key < root.val:
            root.left = self._delete(root.left, key)
        elif key > root.val:
            root.right = self._delete(root.right, key)
        else:
            if root.left is None:
                temp = root.right 
                root = None 
                return temp 
            elif root.right is None:
                temp = root.left 
                root = None 
                return temp 
            temp = self._min_value_node(root.right)
            root.val = temp.val 
            root.right = self._delete(root.right, temp.val)
        return root
        
    def _min_value_node(self, node):
        curr = node 
        while curr.left is not None:
            curr = curr.left 
        return curr
    
    def _max_value_node(self, node):
        curr = node 
        while curr.right is not None:
            curr = curr.right
        return curr 
    
    def min_value(self):
        node = self._min_value_node(self.root)
        if node:
            return node.val 
        return None 
        
    def max_value(self):
        node = self._max_value_node(self.root)
        if node:
            return node.val 
        return None
        
    def height(self):
        return self._height(self.root)
    
    def _height(self, node):
        if node is None:
            return -1 
        else:
            left_height = self._height(node.left)
            right_height = self._height(node.right)
            return max(left_height, right_height) + 1 
            
    def inorder_traversal(self):
        self._inorder_traversal(self.root)
        print()
    
    def _inorder_traversal(self, root):
        if root:
            self._inorder_traversal(root.left)
            print(root.val, end = " ")
            self._inorder_traversal(root.right)
    
    # Find Successor(next higher value) and Predecessor(next lower value)
    def find_successor(self, key):
        node = self.search(key)
        if node:
            if node.right:
                return self._min_value_node(node.right).val
            else:
                successor = None 
                ancestor = self.root 
                while(ancestor != node):
                    if node.val < ancestor.val:
                        successor = ancestor
                        ancestor = ancestor.left 
                    else:
                        ancestor = ancestor.right
                return ancestor.val if successor else None 
        
        return None
    
    def find_predecessor(self, key):
        node = self.search(key)
        if node:
            if node.left:
                return self._max_value_node(node.left).val 
            else:
                predecessor = None 
                ancestor = self.root 
                while(ancestor != node):
                    if node.val < ancestor.val:
                        successor = ancestor
                        ancestor = ancestor.left 
                    else:
                        ancestor =ancestor.right
                return successor.val if successor else None 

        return None 
        
    # is BST Valid 
    def is_valid_bst(self):
        def validate(node, low = float('-inf'), high = float('inf')):
            if not node:
                return True 
            if not (low < node.val < high):
                return False 
            return (validate(node.left, low, node.val) and validate(node.right, node.val, high))
        return validate(self.root)
    
    # Count Total number of Nodes
    def count_nodes(self):
        return self._count_nodes(self.root)
    
    def _count_nodes(self, node):
        if not node:
            return 0
        else:
            return 1 + self._count_nodes(node.left) + self._count_nodes(node.right)
    
    # Find K-th Smallest / Largest element
    def kth_smallest(self, k):
        def inorder(node):
            if not node:
                return []
            return inorder(node.left) + [node.val] + inorder(node.right)
            
        elements = inorder(self.root)
        if k <= len(elements):
            return elements[k-1]
        else:
            return None 
    
    def kth_largest(self, k):
        def inorder(node):
            if not node:
                return []
            return inorder(node.right) + [node.val] + inorder(node.left)
        elements = inorder(self.root)
        if k <= len(elements):
            return elements[k-1]
        else:
            return None 
    
    # Path Sum Exists : check if there's path from root to leaf with a given Sum
    def has_path_sum(self, sum):
        path = []
        def path_sum(node, curr_sum):
            if not node:
                return False 
            curr_sum += node.val 
            path.append(node.val)
            # if leaf node 
            if not node.left and not node.right:
                return curr_sum == sum
            # else 
            return (path_sum(node.left, curr_sum) or path_sum(node.right, curr_sum))
        
        if path_sum(self.root, 0):
            print("has path sum :", path)
        else:
            print("Not has path sum")
            
    # Lowest Common Ancestor(LCA) : Find the LCA of two nodes
    
    # Convert BST to Sotred Linked List 
    
    # Serialize and Deserialize BST : serialize BST <-> string 

bst = BST()
nodes = [50, 30, 70, 20, 40, 60, 80]
for node in nodes:
    bst.insert(node)
    
bst.inorder_traversal()

if (bst.search(100)):
    print("Found!")
else:
    print("Not Found!")
    
bst.delete(70)
bst.inorder_traversal()
bst.insert(70)
bst.inorder_traversal()

height = bst.height()
print("BST height : ", height)
min_node = bst.min_value()
max_node = bst.max_value()
print("BST max node : ", max_node)
print("BST min node : ", min_node)

if (bst.is_valid_bst()):
    print("Is valid BST.")
    
print("Successor of 30 : ", bst.find_successor(30))
print("Predecessor of 30 : ", bst.find_predecessor(30))
print("Total number of BST's Nodes : ", bst.count_nodes())

print("3th Smallest Node : ", bst.kth_smallest(3))
print("3th Largest Node : ", bst.kth_largest(3))

bst.has_path_sum(100)
 
