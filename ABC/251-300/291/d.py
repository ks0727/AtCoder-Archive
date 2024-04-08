n = int(input())
a = []
b = []
for _ in range(n):
    ai,bi = map(int,input().split())
    a.append(ai)
    b.append(bi)
MOD = 998244353
dp = [[ 0 for _ in range(2)] for _ in range(n+1)]
dp[0][0] = dp[0][1] = 1
for i in range(1,n):
    if a[i] != a[i-1]:
        dp[i][0] += dp[i-1][0]%MOD
        dp[i][0] %= MOD
    if a[i] != b[i-1]:
        dp[i][0] += dp[i-1][1]%MOD
        dp[i][0] %= MOD
    if b[i] != a[i-1]:
        dp[i][1] += dp[i-1][0]%MOD
        dp[i][1] %= MOD
    if b[i] != b[i-1]:
        dp[i][1] += dp[i-1][1]%MOD
        dp[i][1] %= MOD
ans = dp[n-1][0]%MOD+dp[n-1][1]%MOD
print(ans % MOD)