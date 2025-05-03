def main():
  n,m = map(int,input().split())
  ans = m*(m-1)//2
  cnt = [0]*n
  for i in range(m):
    a,b = map(int,input().split())  
    cnt[(a+b)%n]+=1

  for i in range(n):
    ans -= cnt[i]*(cnt[i]-1)//2

  print(ans)
if __name__ == '__main__':
  main()


