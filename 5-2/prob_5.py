# Lexicographically n-th permutation of string
# next permutation function

def next_permutation(arr):
    # arr = list(arr)
    n = len(arr)

    # 1. find the largest index i such that arr[i] < arr[i+1]
    i = n - 2
    while i >= 0 and arr[i] >= arr[i+1]:
        i -= 1

    # no such index exists
    if i == -1:
        return False
    
    # 2. find the largest index j such that arr[i] < arr[j]
    j = i + 1
    while j < n and arr[j] > arr[i]:
        j += 1
    j -= 1

    # 3. Swap arr[i] <-> arr[j]
    arr[i], arr[j] = arr[j], arr[i]

    # 4. Reverse
    left, right = i+1, n-1
    while left < right:
        arr[left], arr[right] = arr[right], arr[left]
        left += 1
        right -= 1
    # "".join(arr)
    return True

# n-th permutation using next_permuation
def n_permutation(s, n):
    arr = list(s)
    res = ["".join(arr)]
    # Ascending Order
    arr.sort()

    # keep iterating until reach n-th position
    while next_permutation(arr):
        res.append("".join(arr))

    return res[n-1]

input = "abc"
print(n_permutation(input, 3))
