def solve()->int:
  n,m = map(int,input().split())
  ans = 2e18
  if n*n < m:
    return -1
  for i in range(1,n+1):
    b = (m+i-1)//i
    if b <= n:
      ans = min(ans,i*b)
      if(i >= b):
        return ans
       
if __name__ =="__main__":
  ans = solve()
  print(ans)

