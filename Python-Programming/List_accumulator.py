def list_accumlator(L):
    sum_res = 0
    for ele in L:
        if isinstance(ele, list):
            sum_res += list_accumlator(ele)  # Recursive
        else:
            sum_res += ele
    return sum_res

L = [1, [2,3], [[4]]]
result = list_accumlator(L)
print(result)