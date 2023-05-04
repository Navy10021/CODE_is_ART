# LCS : if S1[i-1] == S2[j-1] -> DP[i-1][j-1]+1 / else max(DP[i-1][j], DP[i][j-1])
def LCS(X, Y):
    M, N = len(X), len(Y)
    DP = [[None]*(N+1) for i in range(M+1)]

    for i in range(M+1):
        for j in range(N+1):
            if i == 0 or j == 0:
                DP[i][j] = 0
            elif X[i-1] == Y[j-1]:
                DP[i][j] = DP[i-1][j-1] + 1
            else:
                DP[i][j] = max(DP[i-1][j], DP[i][j-1])
    
    return DP[M][N], DP

# print LCS
def print_LCS(X, Y):
    _, DP = LCS(X, Y)
    # create string
    lcs = ""
    i, j = len(X), len(Y)
    while i > 0 and j > 0:
        if X[i-1] == Y[j-1]:
            lcs += X[i-1]
            i -= 1
            j -= 1
        elif DP[i-1][j] > DP[i][j-1]:
            i -= 1
        else:
            j -= 1
    # reverse string
    res = lcs[::-1]
    return res

S1 = "AGGTAB"
S2 = "GXTXAYB"
print(LCS(S1, S2)[0])
print(print_LCS(S1, S2))
