import sys
sys.setrecursionlimit(10**6)

n,k = map(int,input().split())
g = [[] for _ in range(n)]

for i in range(n-1):
    a,b = map(int,input().split())
    a-=1 
    b-=1
    g[a].append(b)
    g[b].append(a)

vs = list(map(int,input().split()))
vs = [v-1 for v in vs]
need = [False]*n
need[vs[0]] = True

for i in range(1,k):
    v = vs[i]
    if need[v]:
        continue
    seen = [False]*n
    seen[v] = True
    visited = []
    def dfs(v):
        if need[v]:
            for x in visited:
                need[x] = True
            return
        seen[v] = True
        visited.append(v)
        for u in g[v]:
            if seen[u]:
                continue
            dfs(u)
            visited.pop()
    dfs(v)

ans = 0

for i in range(n):
    if need[i]:
        ans += 1

print(ans)

def main():
    pass

if __name__ == "__main__":
    main()