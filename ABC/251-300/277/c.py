import sys
from collections import defaultdict
sys.setrecursionlimit(10**9)

def dfs(v):
    visited.add(v)
    for u in g[v]:
        if u in visited: continue
        dfs(u)
        #visited.remove(u)

n = int(input())
g = defaultdict(list)
visited = set()
for _ in range(n):
    a,b = map(int,input().split())
    g[a].append(b)
    g[b].append(a)

dfs(1)
print(max(visited))