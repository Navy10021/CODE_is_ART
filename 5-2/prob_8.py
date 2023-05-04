# Longest Subsequence with consecutive English alphabets

# 1. Find the length of subsequence starting with character
def find_subseq(S, char):
    N = len(S)
    res = 0     # store maximum length
    for i in range(N):
        if S[i] == char:
            # increment res += 1
            res += 1
            # increment alphabet char
            char = chr(ord(char) + 1)
    return res

# 2. Find the maximum length of subsequence of consecutive characters
def find_max_subseq(S):
    res = 0

    for char in range(ord('a'), ord('z')+1):
        res = max(res, find_subseq(S, chr(char)))

    return res

 # 3. Find the maximum subsequence strings 
def find_max_subseq_str(S):
    arr = list(S)
    start = ord(min(arr))
    max_len = find_max_subseq(S)
    res = []
    for i in range(max_len):
        res.append(chr(start + i))
    return "".join(res)


input = "ababcabd"
print(find_max_subseq(input))
print(find_max_subseq_str(input))
