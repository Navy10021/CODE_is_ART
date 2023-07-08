def check_consecutive(s):
    for i in range(len(s) - 1):
        # Consequtive -> True
        if abs(ord(s[i]) - ord(s[i + 1])) == 1:
            return True
    return False

#print(check_consecutive("abc"))

def rearrange(str):
    str = str.lower()
    # Store the odd and the even positioned Chars
    odd, even = "", ""

    # Traverse
    for c in range(len(str)):
        if ord(str[c]) % 2 == 0:
            even += str[c]
        else:
            odd += str[c]
    
    # Sorting list
    odd = sorted(odd)
    even = sorted(even)

    # Check consequtive
    if not check_consecutive(odd + even):
        res = "".join(odd + even)
    elif not check_consecutive(even + odd):
        res = "".join(even + odd)
    else:
        res = ""

    return res

#################################################

# remove duplicate
def remove_dup(s):
    return "".join(sorted(set(s)))

def rearrange_2(str):
    str = str.lower()
    str = remove_dup(str)
    # Store the odd and the even positioned Chars
    odd, even = "", ""

    # Traverse
    for c in range(len(str)):
        if ord(str[c]) % 2 == 0:
            even += str[c]
        else:
            odd += str[c]
    
    # Sorting list
    odd = sorted(odd)
    even = sorted(even)

    # Check consequtive
    if not check_consecutive(odd + even):
        res = "".join(odd + even)
    elif not check_consecutive(even + odd):
        res = "".join(even + odd)
    else:
        res = ""

    return res

input = "abbccde"
print(rearrange(input))
print(rearrange_2(input))
