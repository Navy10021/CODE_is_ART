# Combination SUM

def combinationSUM(arr, target):
    
    def backtrack(start, target, path):
        if target == 0:
            res.append(path[:])
            return

        for i in range(start, len(arr)):
            if arr[i] > target:
                continue
            path.append(arr[i]) # Include current element
            backtrack(i, target - arr[i], path)
            path.pop()          # backtrack
    res = []
    arr.sort()
    backtrack(0, target, [])
    return res


candidate = [2,3,6,7]
target = 7
print(combinationSUM(candidate, target))