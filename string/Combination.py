def genCombination(string, curr, idx, n):
    if (len(curr) == n):
        print(curr)
        return
    
    if idx >= len(string):
        return 

    # 현재 인덱스 문자 포함
    curr += string[idx]
    genCombination(string, curr, idx+1, n)
    
    # 현재 인덱스 문자 미포함
    curr = curr[:-1]
    genCombination(string, curr, idx+1, n)

def printCombination(string, n):
    curr = ""
    genCombination(string, curr, 0, n)


input = "ABCD"
N = 3 

printCombination(input, N)
