lc = [0, 2, 4, 6, 0, 0, 0, 0, 0]
rc = [0, 3, 5, 7, 0, 8, 0, 0, 0]

def preorder(curr):
    if (curr == 0):
        return
    print(curr, end = " ")
    preorder(lc[curr])
    preorder(rc[curr])
    
preorder(1)

def inorder(curr):
    if (curr == 0):
        return 
    inorder(lc[curr])
    print(curr, end = " ")
    inorder(rc[curr])

print()
inorder(1)

def postorder(curr):
    if (curr == 0):
        return 
    postorder(lc[curr])
    postorder(rc[curr])
    print(curr, end = " ")

print()
postorder(1)
