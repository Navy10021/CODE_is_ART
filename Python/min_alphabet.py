string = "LEE YOON AN"
string = string.replace(" ", "")
string = list(string)

# 알파벳 리스트
L = [0 for i in range(26)]

# 존재하면 1 존재하지 않으면 0 
for i in string:
    L[ord(i)-65] = 1
    
# 알파벳 리스트를 돌면서 가장 작은 알파벳 출력
for idx in range(26):
    if (L[idx] == 0):
        print(chr(idx+65))
        break
