def main():
  n,m = map(int,input().split())
  cnt = [0]*m
  ftop = [[] for _ in range(n)]
  for i in range(m):
    ka = list(map(int,input().split()))
    k = ka[0]
    a = ka[1:]
    cnt[i] = k
    for ai in a:
      ai-=1
      ftop[ai].append(i)
  
  b = list(map(int,input().split()))
  ans = 0
  for bi in b:
    bi-=1
    for p in ftop[bi]:
      cnt[p] -= 1
      if cnt[p] == 0:
        ans += 1

    print(ans)

if __name__ == '__main__':
  main()


