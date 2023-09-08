def permute(nums):
    def backtrack(start):
        if start == len(nums):
            # When we have generated a full permutation, add it to the result.
            result.append(nums[:])
            return

        for i in range(start, len(nums)):
            # Swap the current element with the element at index 'start'.
            nums[start], nums[i] = nums[i], nums[start]

            # Recursively generate permutations for the remaining elements.
            backtrack(start + 1)

            # Restore the original order (backtrack).
            nums[start], nums[i] = nums[i], nums[start]

    result = []
    backtrack(0)
    return result

# Example usage:
nums = [1, 2, 3]
print(permute(nums))  # Should return all possible permutations of [1, 2, 3]
