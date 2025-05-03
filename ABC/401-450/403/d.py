def main():
  n,d = map(int,input().split())
  a = list(map(int,input().split()))
  a = sorted(a)
  MX = 1e6+5
  cnt = [0]*int(MX)
  arr = []
  done = set()
  if d == 0:
    for i in range(n):
      if a[i] in done:
        continue
      done.add(a[i])
    print(n - len(done))
    exit(0)

  for x in a:
    cnt[x]+=1

  for i in range(n):
    if a[i] in done:
      continue
    now = []
    cur = a[i]
    while cur < MX and cnt[cur] != 0:
      done.add(cur)
      now.append(cnt[cur])
      cur += d
    arr.append(now)

  ans = 0
  for x in arr:
    if len(x) <= 1:
      continue
    dp0 = 0
    dp1 = 0
    ndp0 = 0
    ndp1 = 0
    for xi in x:
      ndp0 = dp1
      ndp1 = min(dp0,dp1) + xi
      dp0 = ndp0
      dp1 = ndp1
    ans += min(dp0,dp1)

  print(ans)
    

if __name__ == '__main__':
  main()


