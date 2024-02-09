# level order traversal
# count leaf nodes
# sum of all nodes
# convert BST to Balanced BST
# Merge Two BSTs
# Find all Element in a given Range
# Vertical Order traversal

class Node:
    def __init__(self, key):
        self.left = None
        self.right = None
        self.val = key

class BST:
    def __init__(self):
        self.root = None
        
	# Base functions
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
                return root.right
            elif root.right is None:
                return root.left
            temp = self._min_value_node(root.right)
            root.val = temp.val
            root.right = self._delete(root.right, temp.val)
        return root

    def _min_value_node(self, node):
        current = node
        while current.left is not None:
            current = current.left
        return current

    def _max_value_node(self, node):
        current = node
        while current.right is not None:
            current = current.right
        return current

    def min_value(self):
        node = self._min_value_node(self.root)
        return node.val if node else None

    def max_value(self):
        node = self._max_value_node(self.root)
        return node.val if node else None

	# Inorder traversal
    def inorder_traversal(self):
        self._inorder_traversal(self.root)
        print()

    def _inorder_traversal(self, root):
        if root:
            self._inorder_traversal(root.left)
            print(root.val, end=" ")
            self._inorder_traversal(root.right)

    # Level order traversal
    def level_order_traversal(self):
        if not self.root:
            return []
        queue, result = [self.root], []
        while queue:
            current = queue.pop(0) # popleft
            result.append(current.val)
            if current.left:
                queue.append(current.left)
            if current.right:
                queue.append(current.right)
        return result
	
    # Vertical order traversal 
    # Use a hash table to store nodes by thier horizontal distance from root.
    def vertical_order_traversal(self):
        def get_vertical_order(node, dist, hash):
            if not node:
                return 
            try:
                hash[dist].append(node.val)
            except KeyError:
                hash[dist] = [node.val]
            get_vertical_order(node.left, dist-1, hash)
            get_vertical_order(node.right, dist+1, hash)
        def print_vertical_order(hash):
            res = []
            for index in sorted(hash):
                res.append(hash[index])
            return res 
        hash = {}
        get_vertical_order(self.root, 0, hash)
        return print_vertical_order(hash)
        
    # Count Leaf nodes
    def count_leaf_nodes(self):
        return self._count_leaf_nodes(self.root)

    def _count_leaf_nodes(self, node):
        if node is None:
            return 0
        if not node.left and not node.right:
            return 1
        return self._count_leaf_nodes(node.left) + self._count_leaf_nodes(node.right)
	
    # Sum of all node's values
    def sum_of_all_nodes(self):
        return self._sum_of_all_nodes(self.root)

    def _sum_of_all_nodes(self, node):
        if node is None:
            return 0
        return node.val + self._sum_of_all_nodes(node.left) + self._sum_of_all_nodes(node.right)

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
        
    # Find all elements in a Given Range
    # Perform a in-order traversal to find all elements 
    def find_range(self, low, high):
        def recursive(node, low, high, range_list):
            if not node:
                return 
            if low < node.val: 
                recursive(node.left, low, high, range_list)
            
            if low <= node.val <= high:
                range_list.append(node.val)
            
            if high > node.val:
                recursive(node.right, low, high, range_list)
        
        range_list = []
        recursive(self.root, low, high, range_list)
        return range_list
    

# Example usage
bst = BST()
nodes = [50, 30, 70, 20, 40, 60, 80]
for node in nodes:
    bst.insert(node)

bst.inorder_traversal()  # Display the BST in inorder
print("Level Order Traversal:", bst.level_order_traversal())
print("Vertical Order Traversal:", bst.vertical_order_traversal())
print("Count of Leaf Nodes:", bst.count_leaf_nodes())
print("Sum of All Nodes:", bst.sum_of_all_nodes())
print("40 ~ 70 Nodes : ", bst.find_range(40, 70))