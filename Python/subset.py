def make_subset(arr):
    n = len(arr)
    res = []
    
    def Subset(subset, subsetsize, idx):
        if idx == n:
            temp = []
            for i in range(subsetsize):
                temp.append(subset[i])
            res.append(temp)
            return

        # Include the current element in the subset
        subset[subsetsize] = arr[idx]
        Subset(subset, subsetsize + 1, idx + 1)

        # Exclude the current element from the subset
        Subset(subset, subsetsize, idx + 1)

    Subset([0] * n, 0, 0)  # Initialize the subset list

    return res

print("All subsets of the array \n")
arr = [1, 2, 3]
subsets = make_subset(arr)

for subset in subsets:
    print(subset)
