class TreeNode:
    def __init__(self, key):
        self.key = key
        self.left = None
        self.right = None
        self.parent = None

class BinarySearchTree:
    def __init__(self):
        self.root = None

    def insert(self, key):
        self.root = self._insert_recursive(self.root, key)

    def _insert_recursive(self, root, key):
        if root is None:
            return TreeNode(key)
        if key < root.key:
            root.left = self._insert_recursive(root.left, key)
            root.left.parent = root  # Set parent pointer
        else:
            root.right = self._insert_recursive(root.right, key)
            root.right.parent = root  # Set parent pointer
        return root

    def transplant(self, u, v):
        if u.parent is None:
            self.root = v
        elif u == u.parent.left:
            u.parent.left = v
        else:
            u.parent.right = v

        if v is not None:
            v.parent = u.parent

    def delete(self, z_key):
        z = self.search(self.root, z_key)
        if z is not None:
            self._delete_node(z)

    def _delete_node(self, z):
        if z.left is None:
            self.transplant(z, z.right)
        elif z.right is None:
            self.transplant(z, z.left)
        else:
            y = self.minimum(z.right)
            if y.parent != z:
                self.transplant(y, y.right)
                y.right = z.right
                y.right.parent = y
            self.transplant(z, y)
            y.left = z.left
            y.left.parent = y

    def inorder_traversal(self):
        result = []
        self._inorder_recursive(self.root, result)
        return result

    def _inorder_recursive(self, node, result):
        if node:
            self._inorder_recursive(node.left, result)
            result.append(node.key)
            self._inorder_recursive(node.right, result)

    def minimum(self, node):
        while node.left is not None:
            node = node.left
        return node

    def maximum(self, node):
        while node.right is not None:
            node = node.right
        return node

    def successor(self, x):
        if x.right is not None:
            return self.minimum(x.right)

        y = x.parent
        while y is not None and x == y.right:
            x = y
            y = y.parent
        return y

    def predecessor(self, x):
        if x.left is not None:
            return self.maximum(x.left)

        y = x.parent
        while y is not None and x == y.left:
            x = y
            y = y.parent
        return y

    def search(self, node, key):
        if node is None or key == node.key:
            return node
        if key < node.key:
            return self.search(node.left, key)
        else:
            return self.search(node.right, key)

    def print_tree(self):
        if self.root is not None:
            self._print_tree_recursive(self.root, "", True)

    def _print_tree_recursive(self, node, indent, last):
        if node is not None:
            print(indent, end="")
            if last:
                print("└──", end="")
                indent += "    "
            else:
                print("├──", end="")
                indent += "│   "

            print(node.key)

            self._print_tree_recursive(node.left, indent, False)
            self._print_tree_recursive(node.right, indent, True)

# Example usage:
bst = BinarySearchTree()
bst.insert(50)
bst.insert(30)
bst.insert(70)
bst.insert(20)
bst.insert(40)

# Print the Binary Search Tree
bst.print_tree()
#bst.insert(10)
#bst.insert(60)
#bst.insert(80)
#bst.print_tree()
print(bst.maximum(bst.root).key)
print(bst.minimum(bst.root).key)
print(bst.search(bst.root, 20))
