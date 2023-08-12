MX = 30
lc = [0] * MX
rc = [0] * MX
n = int(input())

for _ in range(n):
    C, L, R = input().split()
    cur = ord(C) - ord('A') + 1
    if L != '.':
        lc[cur] = ord(L) - ord('A') + 1
    if R != '.':
        rc[cur] = ord(R) - ord('A') + 1

def preorder(cur):
    if cur == 0:
        return
    print(chr(cur + ord('A') - 1), end='')
    preorder(lc[cur])
    preorder(rc[cur])

def inorder(cur):
    if cur == 0:
        return
    inorder(lc[cur])
    print(chr(cur + ord('A') - 1), end='')
    inorder(rc[cur])

def postorder(cur):
    if cur == 0:
        return
    postorder(lc[cur])
    postorder(rc[cur])
    print(chr(cur + ord('A') - 1), end='')

preorder(1)
print()
inorder(1)
print()
postorder(1)
print()
