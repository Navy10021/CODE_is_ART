def str_perm(s:str)->list:
    tmp = ""
    isused = [0 for _ in range(len(s))]
    out = []
    def backtrack(k, tmp): # 현재까지 k개의 알파벳을 택함
        if k == len(s):
            out.append(tmp)
        for i in range(len(s)):
            if (not isused[i]):
                isused[i] = 1
                tmp += s[i]
                backtrack(k+1, tmp)
                isused[i] = 0
                tmp = tmp[:-1]
    backtrack(0, tmp)
    out = list(set(out))
    out.sort()
    return out

if __name__ == "__main__":
    print(str_perm("abc"))
    print(str_perm("abb"))


