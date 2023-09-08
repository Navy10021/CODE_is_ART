def generateParentheses(n):
    def backtrack(s, left, right):
        if len(s) == 2 * n:
            result.append(s)
            return

        if left < n:
            backtrack(s + '(', left + 1, right)

        if right < left:
            backtrack(s + ')', left, right + 1)

    result = []
    backtrack('', 0, 0)
    return result

# Example usage:
n = 3
print(generateParentheses(n))
