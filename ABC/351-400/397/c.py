def main():
  n = int(input())
  a = list(map(int,input().split()))
  fr = [0]*n
  bk = [0]*n
  st = set()
  for i in range(n):
    st.add(a[i])
    fr[i] = len(st)

  st = set()
  for i in range(n-1,-1,-1):
    st.add(a[i])
    bk[i] = len(st)
  ans = 0
  for i in range(n-1):
     ans = max(ans,fr[i]+bk[i+1])

  print(ans)
if __name__ == '__main__':
  main()


