# Lexicographically Next String
def next_str(s):
    # string is empty
    if s == "" or s == " ":
        return "a"
    
    # Find first character index from right, Not 'Z'
    i = len(s) - 1
    while s[i] == "z" and i >= 0:
        i -= 1

    # If all chars are 'Z' -> add 'A'
    if i == -1:
        s += "a"
    
    else:
        s = s.replace(s[i], chr(ord(s[i])+1), 1)    # Count 1
    
    return s

# Lexicographically N-th String
def next_n_str(s, n):
    for _ in range(n):
        s = next_str(s)
    return s


input = "abc"
print(next_str(input))
print(next_n_str(input, 2))
