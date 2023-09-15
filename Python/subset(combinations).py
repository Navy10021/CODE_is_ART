def get_combinations(arr, k):
    def backtrack(start, current_combination):
        if len(current_combination) == k:
            combinations.append(list(current_combination))
            return
        for i in range(start, len(arr)):
            current_combination.append(arr[i])
            backtrack(i + 1, current_combination)
            current_combination.pop()
    
    combinations = []
    backtrack(0, [])
    return combinations

# Example usage:
#my_list = [1, 2, 3, 4]
#k = 2
#combinations_k = get_combinations(my_list, k)
#print(f"Combinations of length {k}:", combinations_k)

def get_all_subset(arr):
    subsets = []
    for i in range(len(arr) + 1):
        subsets.extend(get_combinations(arr, i))
    
    return [list(subset) for subset in subsets]

# Example usage:
my_list = [1, 2, 3]
all_subsets = get_all_subset(my_list)
print(all_subsets)
