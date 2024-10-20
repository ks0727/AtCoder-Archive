def main():
  n,c = map(int,input().split()) 
  t = list(map(int,input().split()))
  last = -1e9
  ans = 0
  for i in range(n):
    if t[i]-last < c:
      continue
    last = t[i]
    ans+=1

  print(ans)

if __name__ == '__main__':
  main()


