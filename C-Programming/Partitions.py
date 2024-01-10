# 주어진 string에서 모든 파티션을 구하는 경우
# 'abc' -> [['a', 'b', 'c'], ['a', 'bc'], ['ab', 'c'], ['abc']]

def get_partitioned_substr(str):
    partitions = []
    
    def backtrack(start, curr_partition):
        if start == len(str):
            partitions.append(curr_partition[:])
            return 
        
        for end in range(start + 1, len(str) + 1):
            curr_partition.append(str[start : end])
            backtrack(end, curr_partition)
            curr_partition.pop()        # backtrack
            
    backtrack(0, [])
    
    return partitions

input = "abcd"
res = get_partitioned_substr(input)
print(res)
            
