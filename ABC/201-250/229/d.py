def main():
  s = input()
  k = int(input())
  a = []
  n = len(s)
  for c in s:
    ai = 1 if c == '.' else 0
    a.append(ai)
  s = [0]*(n+1)
  for i in range(n):
    s[i+1] = s[i] + a[i]
  l,r = -1,1001001001                 
  while r-l>1:
    mid = (r+l)//2
    ok = False
    for i in range(n-mid):
      if s[i+mid+1]-s[i] <= k:
        ok = True

    if ok:
      l = mid
    else:
      r = mid
  
  print(r)
  

if __name__ == '__main__':
  main()


