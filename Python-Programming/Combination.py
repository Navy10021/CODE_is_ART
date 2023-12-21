def combination(my_list, start, path, res):
    if len(path) == 2:
        res.append(path[:])  # Append a copy of the current path

    else:
        for i in range(start, len(my_list)):
            duplicate_found = False
            for j in range(start, i):
                if my_list[i] == my_list[j]:
                    duplicate_found = True
                    break
            
            if duplicate_found:
                continue

            path.append(my_list[i])  # include current element
            combination(my_list, i + 1, path, res)  # next index
            path.pop()

    return res

mylist = [1, 2, 3, 2]
mylist = sorted(mylist)

ans = combination(mylist, 0, [], [])
print(ans)