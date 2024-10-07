def main():
  n = int(input())
  k = list(map(int,input().split()))
  ans = 1e18
  for i in range(1<<n):
    a,b = 0,0
    for j in range(n):
      if i>>j&1:
        a += k[j]
      else:
        b += k[j]
    ans = min(max(a,b),ans)
  print(ans)

if __name__ == '__main__':
  main()


