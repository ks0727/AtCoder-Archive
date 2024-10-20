from collections import deque

def main():
  n,m = map(int,input().split())
  g = [[] for _ in range(n)]
  for i in range(m):
    a,b = map(int,input().split())
    a-=1; b-=1
    g[a].append(b)
  INF = 1001001001
  dist = [INF]*n
  dist[0] = 0
  q = deque()
  q.append(0)
  ans = INF
  while(len(q)):
    v = q.popleft()
    for u in g[v]:
      if dist[u] != INF:
        if u == 0:
          ans = min(ans,dist[v]+1)
        continue
      q.append(u)
      dist[u] = dist[v]+1
  if ans == INF:
    ans = -1
  print(ans)
 
  
if __name__ == '__main__':
  main()


