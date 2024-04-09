import sys
sys.setrecursionlimit(10**9)

n,m = map(int,input().split())
g = [[] for _ in range(n)]
for i in range(m):
    u,v = map(int,input().split())
    u -= 1
    v -= 1
    g[u].append(v)
    g[v].append(u)

seen = [False for _ in range(n)]
uni = [0 for _ in range(n)]

def dfs(v,unions):
    uni[v] = unions
    seen[v] = True 
    for u in g[v]:
        if seen[u]:
            continue
        dfs(u,unions)
        
unions = 0
for i in range(n):
    if not seen[i]:
        unions += 1
        dfs(i,unions)
        
ns = [0 for _ in range(unions)]
es = [0 for _ in range(unions)]

for i in range(n):
    u = uni[i]
    u -= 1
    ns[u] += 1
    es[u] += len(g[i])

for i in range(unions):
    if ns[i] != es[i]/2:
        print("No")
        exit()
print("Yes")