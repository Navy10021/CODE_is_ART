def smallest_pos_int(array):
    n = len(array)
    i = 1
    while True:
        if i in array:
            i += 1
        else:
            return i
        

# Testing the function
array1 = [4, 7, -1, 1, 2]
array2 = [100, 101, 102]
array3 = [3, 2, 1, 0, -1]

print(smallest_pos_int(array1))  # Output: 3
print(smallest_pos_int(array2))  # Output: 1
print(smallest_pos_int(array3))  # Output: 4
