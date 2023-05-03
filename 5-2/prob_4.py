# Lexicographically Next Permutation of given String
# Lexicographical order : All the permutations of a word when arranged in dictionary
def swap(arr, i, j):
    temp = arr[i]
    arr[i] = arr[j]
    arr[j] = temp

def reverse(arr, start, end):
    while start < end:
        swap(arr, start, end)
        start += 1
        end -= 1

def next_permutation(s):
    # string -> list
    arr = list(s)
    n = len(arr)
    # 1. Find the largest index i such that arr[i] < arr[i+1]
    i = n - 2
    while i >= 0 and arr[i] >= arr[i+1]:
        i -= 1
    
    # if no such index exists
    if i < 0:
        return "No next permutation"
    
    # 2. Find the largest index j such that arr[i] < arr[j]
    j = n - 1
    while j >= 0 and arr[j] <= arr[i]:
        j -= 1
    
    # 3. Swap arr[i] <-> arr[j]
    arr[i], arr[j] = arr[j], arr[i]
    
    # 4. Reverse the sublist arr[start : end + 1]
    #reverse(arr, i+1, n-1)
    left, right = i+1, n-1
    while left < right:
        arr[left], arr[right] = arr[right], arr[left]
        left += 1
        right -=1

    return "".join(arr)

input = "ABEDC"
print(next_permutation(input))
