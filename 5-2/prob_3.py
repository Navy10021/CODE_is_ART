# Replace multiple occurrence of chars by single

def foo(s, ch):
    i = 0
    res = ""

    while i < len(s):
        if s[i] == ch:
            res += ch
            i += 1
            while i < len(s) and s[i] == ch:
                i += 1
        else:
            res += s[i]
            i += 1
    return res

def bar(s):
    count = {}
    for i in s:
        if i not in count:
            count[i] = 1
        else:
            count[i] += 1

    for key, val in count.items():
        if val > 1:
            s = foo(s, key)     # recursive
    return s

s = "Winnnner issss habittttt !!!!!!"

print(bar(s))
