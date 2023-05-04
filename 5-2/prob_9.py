# Longest substring with No pair of adjacent characters are adjacent English alphabets
def find_long_sub(s):
    temp_substr = ""
    temp_substr_len = 0
    res = ""
    # substring
    temp_substr += s[0]
    # Traverse
    for i in range(1, len(s)):
        # if adjacent characters -> Update
        if abs(ord(s[i]) - ord(s[i-1])) == 1:
            # Update length
            temp_substr_len = len(temp_substr)
            # Update longest substring
            if temp_substr_len > len(res):
                res = temp_substr
            # initalize & add
            temp_substr = ""
            temp_substr += s[i]

        # No adjacent -> add
        else:
            temp_substr += s[i]

    # Double check
    if temp_substr_len > len(res):
        res = temp_substr_len
    
    return res

input = "aabdml"
print(find_long_sub(input))
