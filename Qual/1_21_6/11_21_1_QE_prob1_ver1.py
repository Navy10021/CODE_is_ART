# Time complexity O(N)
# Auxiliary Space O(N)

def smallest_pos_int(array: list) -> int:
    m = max(array)
    l = [0 for i in range(m+1)]
    for i in range(len(array)):
        if array[i] > 0:
            l[array[i]-1] = 1
    for i in range(m+1):
        if l[i] == 0:
            return i+1
        
if __name__ == "__main__":
    array = [4, 7, -1, 1, 2]
    print(smallest_pos_int(array))
    array = [100, 101, 102]
    print(smallest_pos_int(array))
    array = [3, 2, 1, 0, -1] 
    print(smallest_pos_int(array))
    array = [3] 
    print(smallest_pos_int(array))
    array = [3,1] 
    print(smallest_pos_int(array))