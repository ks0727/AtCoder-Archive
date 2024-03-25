n,k,d = map(int,input().split())
a = list(map(int,input().split()))

dp = [[[-1 for l in range(100)] for j in range(105)] for i in range(105)]
dp[0][0][0] = 0
for i in range(0,n):
    for j in range(0,k+1):
        for l in range(0,d):
            if dp[i][j][l] == -1:
                continue
            dp[i+1][j+1][(l+a[i])%d] = max(dp[i+1][j+1][(l+a[i])%d],dp[i][j][l]+a[i])
            dp[i+1][j][l] = max(dp[i+1][j][l],dp[i][j][l])

print(dp[n][k][0])



