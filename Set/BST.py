class Node:
    def __init__(self, key):
        self.left = None
        self.right = None
        self.val = key

class BST:
    def __init__(self):
        self.root = None

    def insert(self, key):
        self.root = self._insert_recursive(self.root, key)

    def _insert_recursive(self, root, key):
        if root is None:
            return Node(key)
        else:
            if root.val < key:
                root.right = self._insert_recursive(root.right, key)
            else:
                root.left = self._insert_recursive(root.left, key)
        return root

    def delete(self, key):
        self.root = self._delete_recursive(self.root, key)

    def _delete_recursive(self, root, key):
        if root is None:
            return root
        if key < root.val:
            root.left = self._delete_recursive(root.left, key)
        elif key > root.val:
            root.right = self._delete_recursive(root.right, key)
        else:
            if root.left is None:
                return root.right
            elif root.right is None:
                return root.left
            temp = self._min_value_node(root.right)
            root.val = temp.val
            root.right = self._delete_recursive(root.right, temp.val)
        return root

    def _min_value_node(self, node):
        current = node
        while current.left is not None:
            current = current.left
        return current

    def inorder_traversal(self):
        self._inorder_recursive(self.root)

    def _inorder_recursive(self, root):
        if root:
            self._inorder_recursive(root.left)
            print(root.val, end=' ')
            self._inorder_recursive(root.right)

    def inorder_traversal_to_array(self, node, arr):
        if node:
            self.inorder_traversal_to_array(node.left, arr)
            arr.append(node.val)
            self.inorder_traversal_to_array(node.right, arr)

    def sorted_array_to_bst(self, arr):
        if not arr:
            return None
        mid = len(arr) // 2
        root = Node(arr[mid])
        root.left = self.sorted_array_to_bst(arr[:mid])
        root.right = self.sorted_array_to_bst(arr[mid+1:])
        return root

    def convert_to_balanced_bst(self):
        arr = []
        self.inorder_traversal_to_array(self.root, arr)
        self.root = self.sorted_array_to_bst(arr)

    def is_balanced(self):
        return self._check_balanced(self.root)[0]

    def _check_balanced(self, node):
        if node is None:
            return True, 0
        left_balanced, left_height = self._check_balanced(node.left)
        right_balanced, right_height = self._check_balanced(node.right)
        current_balanced = left_balanced and right_balanced and abs(left_height - right_height) <= 1
        current_height = max(left_height, right_height) + 1
        return current_balanced, current_height

# 사용 예
bst = BST()
# 예제: 삽입
bst.insert(50)
bst.insert(30)
bst.insert(70)
bst.insert(20)
bst.insert(40)
bst.insert(60)
bst.insert(80)

print("Inorder traversal of the given tree:")
bst.inorder_traversal()
print("\n")

# 예제: 삭제
bst.delete(20)
print("Inorder traversal after deletion of 20:")
bst.inorder_traversal()
print("\n")

# 예제: 균형 확인
print("Is the tree balanced? ", bst.is_balanced())

# 예제: 균형 잡힌 트리로 변환
bst.convert_to_balanced_bst()
print("Inorder traversal after converting to balanced BST:")
bst.inorder_traversal()
print("\n")

# 변환 후 균형 확인
print("Is the tree balanced after conversion? ", bst.is_balanced())
