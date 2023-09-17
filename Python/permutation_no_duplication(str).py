def permute(string, left, right):
    if left == right:
        print(''.join(string))
    else:
        for i in range(left, right + 1):
            should_swap = True

            # Check for duplicates and avoid swapping if duplicates are found
            for j in range(left, i):
                if string[j] == string[i]:
                    should_swap = False
                    break

            if should_swap:
                string[left], string[i] = string[i], string[left]
                permute(string, left + 1, right)
                string[left], string[i] = string[i], string[left]  # Backtrack

def generate_permutations(s):
    string = list(s)
    n = len(string)

    print(f"Permutations of '{s}' with duplicates:")
    permute(string, 0, n - 1)

if __name__ == "__main__":
    input_string = "aab"
    generate_permutations(input_string)
