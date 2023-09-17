def permute(arr, left, right):
    if left == right:
        print(arr)
    else:
        for i in range(left, right + 1):
            should_swap = True

            # Check for duplicates and avoid swapping if duplicates are found
            for j in range(left, i):
                if arr[j] == arr[i]:
                    should_swap = False
                    break

            if should_swap:
                arr[left], arr[i] = arr[i], arr[left]
                permute(arr, left + 1, right)
                arr[left], arr[i] = arr[i], arr[left]  # Backtrack

def generate_permutations(arr):
    n = len(arr)

    print(f"Permutations of {arr} with duplicates:")
    permute(arr, 0, n - 1)

if __name__ == "__main__":
    input_array = [1, 2, 2]
    generate_permutations(input_array)
