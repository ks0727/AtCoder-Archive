def main():
  n = int(input())
  a = list(map(int,input().split()))
  b = list(map(int,input().split()))
  a = sorted(a)
  b = sorted(b)
  l,r = -1,1001001001
  while r-l > 1:
    mid = (r+l)//2
    def f(x):
      mx = -1
      mid = -1
      for i in range(n):
        if a[i] <= x and mx <= a[i]:
          mx = a[i]
          mid = i
      if mid == -1:
        return False
      bid = 0
      for i in range(n):
        if i == mid:
          continue
        if a[i] > b[bid]:
          return False
        bid+=1
      return True

    if(f(mid)):
      r = mid
    else:
      l = mid
  
  if r == 1001001001:
    r = -1

  print(r)
     
if __name__ == '__main__':
  main()


