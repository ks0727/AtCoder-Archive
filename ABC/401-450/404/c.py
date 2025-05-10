import sys
sys.setrecursionlimit(10**6)

def main():
  n,m = map(int,input().split())
  dim = [0]*n
  g = [[] for _ in range(n)]
  for _ in range(m):  
    a,b = map(int,input().split())
    a-=1; b-=1;
    dim[a] += 1
    dim[b] += 1
    g[a].append(b)
    g[b].append(a)

  seen = [False]*n
  cs = 0
  for i in range(n):
    if not seen[i]:
      cs += 1
      stack = []
      stack.append(i)
      while len(stack) != 0:
        v = stack[-1]
        stack.pop()
        for u in g[v]:
          if seen[u]:
            continue
          stack.append(u)
          seen[u] = True
  
  if cs != 1:
    print("No")
    exit()

  for i in range(n):
    if dim[i] != 2:
      print("No")
      exit()

  print("Yes")
    
if __name__ == '__main__':
  main()


