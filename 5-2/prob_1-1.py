# Rearrange Characters in a string such that no two adjacent characters are same
# Find the char with maximum frequency in the given string
def get_max_char(count):
    """
    count : hashmap for alphabets
    """
    max_count = 0
    for i in range(26):
        if count[i] > max_count:
            max_count = count[i]
            max_char = chr(i + ord('a'))
    
    return max_count, max_char


def rearrage(s):
    N = len(s)
    if not N:
        return ""
    
    # Hash map
    count = [0]*26
    for char in s:
        count[ord(char) - ord('a')] += 1  
    
    max_count, max_char = get_max_char(count)

    # if the char with maximum freq is more than half of the total lenght -> Impossible
    if max_count > (N + 1) // 2:
        return ""
    
    # sorting list
    res = [None] * N
    idx = 0

    # Even position
    while max_count:
        res[idx] = max_char
        idx += 2
        max_count -= 1
    
    count[ord(max_char) - ord('a')] = 0

    # Remain even position and then fill the odd position
    for i in range(26):
        while count[i] > 0:
            if idx >= N:
                idx = 1
            res[idx] = chr(i + ord('a'))
            idx += 2
            count[i] -= 1

    return "".join(res)


input = "aaabcd"
print(rearrage(input))
