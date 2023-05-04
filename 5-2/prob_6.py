# Print all Non-empty Substring
def all_substr(s):
    n = len(s)
    res = []
    for i in range(n):
        temp = ""
        for j in range(i, n):
            temp += s[j]
            res.append(temp)
    res = sorted(res, key = len)
    return res

# print all Subsequnce
def all_subseq(s):
    res = []
    def subseq(sub, out):
        if len(sub) == 0:
            res.append(out)
            return
        # including the first character
        subseq(sub[1:], out + sub[0])
        # excluding the first character
        subseq(sub[1:], out)
    subseq(s, "")
    #res.remove("")
    res = sorted(res, key=len)
    return res


input = "abc"
#print(all_substr(input))
#print(all_subseq(input))
# Count Distinct Subsequences
#print(len(set(all_subseq(input))))
