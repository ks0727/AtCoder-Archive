def main():
    n,x = map(int,input().split())
    vac = []
    for i in range(n):
        v,a,c = map(int,input().split())
        v-=1
        vac.append((v,a,c))
    
    INF = 1001001001
    dp = [[-INF]*(x+1) for _ in range(3)]
    
    dp[0][0] = dp[1][0] = dp[2][0] = 0
    
    for k in range(3):
        for i in range(n):
            v,a,c = vac[i]
            if v != k:
                continue
            for j in range(x,-1,-1):
                if j-c >= 0 and dp[k][j-c] != -INF:
                    dp[k][j] = max(dp[k][j-c]+a,dp[k][j])
    
    r = int(1e9)
    l = int(0)
    
    while r-l >1:
        mid = (r+l)//2
        def f(mm : int):
            now = 0
            for k in range(3):
                for j in range(x+1):
                    if dp[k][j] >= mm:
                        now += j
                        break
                    if j == x:
                        return False
            
            return now <= x

        if f(mid):
            l = int(mid)
        else:
            r = int(mid)

    print(l)
    
if __name__ == "__main__":
    main()