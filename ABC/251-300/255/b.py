import math
def calc(a,b):
  res = (a[0]-b[0])**2 + (a[1]-b[1])**2
  return math.sqrt(res)


n,k = map(int,input().split())
a = list(map(int,input().split()))
a = [x-1 for x in a]
on = [False]*n
for x in a:
  on[x] = True

ps = []
for i in range(n):
  x,y= map(int,input().split())
  ps.append((x,y))

ans = -1
for i in range(n):
  for j in range(n):
    if i == j:
      continue
    if on[i] and on[j]:
      continue
    ans = max(ans,calc(ps[i],ps[j]))
print(ans)


