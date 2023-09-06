my_list = [3, 1, 4, 1, 5, 9, 2, 6, 5, 3, 5]

# 오름차순으로 정렬
sorted_list = sorted(my_list)
print(sorted_list)

# 내림차순으로 정렬
reverse_sorted_list = sorted(my_list, reverse=True)
print(reverse_sorted_list)

# 오름차순으로 정렬
my_list.sort()
print(my_list)

# 내림차순으로 정렬
my_list.sort(reverse=True)
print(my_list)

# 리스트를 뒤집기
my_list.reverse()
print(my_list)

# 슬라이싱을 사용하여 리스트를 뒤집기
reversed_list = my_list[::-1]
print(reversed_list)



my_list = ["apple", "banana", "cherry", "date", "elderberry"]

# 문자열 길이를 기준으로 오름차순 정렬
sorted_list = sorted(my_list, key=lambda x: len(x))
print(sorted_list)

my_dict = {'apple': 3, 'banana': 1, 'cherry': 2, 'date': 5, 'elderberry': 4}

# 딕셔너리의 키를 기준으로 오름차순 정렬
sorted_dict_keys = sorted(my_dict.keys())
for key in sorted_dict_keys:
    print(key, my_dict[key])

# 딕셔너리의 값(value)을 기준으로 오름차순 정렬
sorted_dict_values = sorted(my_dict.items(), key=lambda item: item[1])
for key, value in sorted_dict_values:
    print(key, value)

