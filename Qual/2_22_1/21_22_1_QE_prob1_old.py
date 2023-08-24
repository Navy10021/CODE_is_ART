def palindrome(s: str)->bool:
    return s == s[::-1]

def substring(s:str, t:str)->bool:
    return t in s

def max_palindromes(s:str)->list:
    n = len(s); w = len(s)
    pallist= []
    while w:
        for i in range(n-w+1):
            flag = 0
            if palindrome(s[i:i+w]):
                flag = 1
                for j in range(len(pallist)):
                    if(substring(pallist[j], s[i:i+w])):
                        flag = 0
            if (flag == 1):
                pallist.append(s[i:i+w])
        w -= 1

    # 순서 맞추기
    out = []
    for i in range(n):
        for j in range(i+1, n+1):
            if s[i:j] in pallist:
                out.append(s[i:j])

    return out

s1 = "kabccbadzdefgfeda"
s2 =  "kabccba dzabccbaza"
s3 = "asdsa azazza"
print(max_palindromes(s1))
print(max_palindromes(s2))
print(max_palindromes(s3))