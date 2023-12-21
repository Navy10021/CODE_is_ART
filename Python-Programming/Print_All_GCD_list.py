def GCD(a, b):
  if b == 0:
    return a
  else:
    return GCD(b, a%b)

def all_GCD(L):
  res = []
  for i in L:
    GCD_list = []
    for j in L:
      GCD_list.append(GCD(i,j))
    res.append(GCD_list)
  return res
  

ans = all_GCD([36, 100, 50, 128])
print(ans)