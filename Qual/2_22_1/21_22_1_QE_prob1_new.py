def palindrome(s: str)->bool:
    return s == s[::-1]

def substring(s:str, t:str)->bool:
    return t in s

def max_palindromes(s:str)->list:
    n = len(s)
    pdlist = []
    removestr = []
    for st in range(n):
        pd = s[st]
        for en in range(1, n+1):
            if(palindrome(s[st:en])):
                pd = s[st:en]
        for i in range(len(pdlist)):
            if substring(pdlist[i], pd):
                pd = None
                break;
            if substring(pd, pdlist[i]): # 반대로 pdlist[i]가 속할 수도 있음 
                removestr.append(pdlist[i])
        if pd:
            pdlist.append(pd)
    for rs in removestr:
        pdlist.remove(rs)
    return pdlist

if __name__ == '__main__':
    s1 = "kabccbadzdefgfeda"
    s2 = "kabccba dzabccbaza"
    s3 = "asdsa azazza"
    s4 = "kkak"
    print(max_palindromes(s1))
    print(max_palindromes(s2))
    print(max_palindromes(s3))
    print(max_palindromes(s4))