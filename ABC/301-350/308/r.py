def main():
  n,m = map(int,input().split())
  c = input().split()
  d = input().split()
  p = list(map(int,input().split()))
  ans = 0
  for s in c:
    done = False
    for i,t in enumerate(d):
      if s == t:
        ans += p[i+1]
        done = True
        break

    if not done:
      ans += p[0]
  print(ans)

  
if __name__ == '__main__':
  main()


