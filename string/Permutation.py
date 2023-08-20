def genPermutation(string, curr, used):
    if len(curr) == len(string):
        print(curr)
        return
    
    for i in range(len(string)):
        if not used[i]:
            used[i] = True 
            genPermutation(string, curr+string[i], used)
            used[i] = False

def printPermutation(string):
    used = [False] * len(string)
    genPermutation(string, "", used)
    
input_str = "ABC"
printPermutation(input_str)
