def wordExists(board, word):
    def dfs(row, col, word_index):
        # Check if we have found the entire word
        if word_index == len(word):
            return True

        # Check if we are out of bounds or the current cell does not match the word
        if (
            row < 0
            or row >= len(board)
            or col < 0
            or col >= len(board[0])
            or board[row][col] != word[word_index]
        ):
            return False

        # Temporarily mark the current cell as visited
        temp = board[row][col]
        board[row][col] = "#"

        # Recursively explore adjacent cells
        if (
            dfs(row + 1, col, word_index + 1)
            or dfs(row - 1, col, word_index + 1)
            or dfs(row, col + 1, word_index + 1)
            or dfs(row, col - 1, word_index + 1)
        ):
            return True

        # Restore the original value of the cell
        board[row][col] = temp
        return False

    # Iterate through each cell in the board and start DFS from there
    for row in range(len(board)):
        for col in range(len(board[0])):
            if dfs(row, col, 0):
                return True

    return False

# Example usage:
board = [
    ['A', 'B', 'C', 'E'],
    ['S', 'F', 'C', 'S'],
    ['A', 'D', 'E', 'E']
]

word1 = "ABCCED"
word2 = "SEE"
word3 = "ABCB"

print(wordExists(board, word1))  # Should return True
print(wordExists(board, word2))  # Should return True
print(wordExists(board, word3))  # Should return False
