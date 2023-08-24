'''
1. 음수를 없앤다. 음수는 필요가 없고 음수를 활용하여 mark할 것이기 때문
2. 이미 있는 수들의 index (num-1)에다 음수를 표기하여 해당 수가 있음을 표시
   이때 abs function을 사용하는데, 이유는 이미 음수로 표기되어 있는 경우가 있을 수도 있기 때문
   그때 array보다 큰 싸이즈면 알빠노~ 필요 없는 수임.
3. 음수가 아닌 index가 첫번째 양수
time complexity : O(N)
Space complexity : O(1)

array = [-2, -1, 1, 5, 4, 5, 100]
array = [1, 5, 4, 5, 100]
array = [-1 , 5, 4, 5, 100]
array = [-1 , 5, 4, 5, -100]
array = [-1 , 5, 4, -5, -100]
array = [-1 , 5, 4, -5, -100]
array = [-1 , 5, 4, -5, -100]
-> 2 
'''

def smallest_pos_int(array):
    N = len(array)

    # Step 1: Move all the non-positive numbers to the left
    j = 0
    for i in range(N):
        if array[i] <= 0:
            array[i], array[j] = array[j], array[i]
            j += 1

    # Now we only care about the positive part of the array, so let's ignore the non-positive part
    positive_array = array[j:]
    # Step 2: Mark the numbers that are present
    for i in range(len(positive_array)):
        num = abs(positive_array[i])
        if num - 1 < len(positive_array) and positive_array[num - 1] > 0:
            positive_array[num - 1] = -positive_array[num - 1]

    # Step 3: Find the first index with a positive value
    for i in range(len(positive_array)):
        if positive_array[i] > 0:
            return i + 1

    return len(positive_array) + 1 # 마지막에 수가 아예 없을 경우 대비..

# Testing the function
array1 = [4, 7, -1, 1, 2]
array2 = [100, 101, 102]
array3 = [3, 2, 1, 0, -1]

print(smallest_pos_int(array1))  # Output: 3
print(smallest_pos_int(array2))  # Output: 1
print(smallest_pos_int(array3))  # Output: 4
