def is_palindrome(s):
    l, r = 0, len(s)-1
    while l < r and not s[l].isalnum():
        l += 1
    while l < r and not s[r].isalnum():
        r -= 1
    
    if s[l].lower() != s[r].lower():
        return False

    return True

def sub_string(s, t):
    if t not in s:
        return False
    return True


def max_palindrome(s):
    # Find all sub_string palindrome -> to list
    sub_list = []
    
    # if is palindrome
    for i in range(len(s)):
        for j in range(i, len(s)):
            if s[i:j+1] == s[i:j+1][::-1]:
                sub_list.append(s[i:j+1])
    sub_list = list(set(sub_list))
    sub_list = sorted(sub_list, key=len)
    res = []
    # sub_list check
    for i in range(len(sub_list)):
        join_str = ''.join(sub_list[i+1:])
        if not sub_string(join_str, sub_list[i]):
            res.append(sub_list[i])

    return res

input_s = "kabccba dzdefgfeda"
print(max_palindrome(input_s))
