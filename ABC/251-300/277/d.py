n,m = map(int,input().split())
a = list(map(int,input().split()))
a.sort()
visited = [False for _ in range(n)]
s = 0
for x in a:
    s += x
ans = s
for i in range(n):
    if(visited[i]): continue
    visited[i] = True
    now = 0
    now += a[i]
    j = i
    while(j < n-1):
        if visited[j+1]: break
        if a[j+1] != a[j] and a[j+1] != a[j]+1 : break
        now += a[j+1]
        visited[j+1] = True
        j += 1
    ans = min(ans,s-now)
    
if a[-1] == m-1: #m-1が存在して0につながる場合を考える
    cur = a[0]
    con = False
    #前から消していく
    for i in range(n-1):
        if a[i+1] != a[i] and a[i+1] != a[i]+1:
            if a[i+1] != m-1:
                con = True
            break
        cur += a[i+1]
    #後ろから消していく
    if con:
        a.reverse()
        cur += a[0]
        for i in range(n):
            if a[i+1] != a[i] and a[i+1] != a[i]-1:
                break
            cur += a[i+1]
    ans = min(ans,s-cur)
print(ans)
