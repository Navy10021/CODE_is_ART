# Rearrange Characters in a sorted string such that No pair of adjacent characters are the same

def isAdj(s):
    for i in range(len(s) - 1):
        if s[i] == s[i+1]:
            return True
        # Else
    return False

def rearrange(s):
    s = list(s)

    # initalize 
    i, j, k = 0, 1, 2

    while k < len(s):
        # if adj is not equal -> increment the value 1
        if s[i] != s[j]:
            i += 1
            j += 1

            # if j == k -> increment the value 1
            if s[j] == s[k]:
                k += 1
        # adj is equal
        else:
            if s[j] == s[k]:
                k += 1
            else:
                # Swap
                temp = s[k]
                s[k] = s[j]
                s[j] = temp

                i += 1
                j += 1
                if j == k:
                    k += 1
    return "".join(s)

def foo(s):
    if not isAdj(s):
        return s

    if len(s) == 2:
        return "-1"
    
    s = rearrange(s)
    #s = s[::-1]
    #s = rearrange(s)

    if not isAdj(s):
        return s

    return -1

input = "abcde"
print(foo(input))
