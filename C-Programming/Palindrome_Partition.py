def isPalindrome(str):
    st = 0
    en = len(str) - 1
    while(st < en):
        if(str[st] != str[en]):
            return 0
        st+=1 
        en-=1
    return 1

def get_partitioned_substr(str):
    partitions = []
    
    def backtrack(start, curr_partition):
        if (start == len(str)):
            #  Check if all substrings in the current partition are palindromes
            flag = 0 
            for substr in curr_partition:
                if(isPalindrome(substr) == 0):
                    flag = 1 
                    break
            if (flag == 0):
                partitions.append(curr_partition[:])
                return 
        
        for end in range(start + 1, len(str) + 1):
            curr_partition.append(str[start : end])
            backtrack(end, curr_partition)
            curr_partition.pop()        # backtrack
            
    backtrack(0, [])
    
    return partitions

input = "abba"
res = get_partitioned_substr(input)
print(res)
            
