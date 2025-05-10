def rot(x):
  n = len(x)
  ret = [['.']*n for _ in range(n)]
  for i in range(n):
    for j in range(n):
      ret[j][n-i-1] = x[i][j]
  
  return ret

def dif(x,y):
  n = len(x)
  ret = 0
  for i in range(n):
    for j in range(n):
      if x[i][j] != y[i][j]:
        ret += 1

  return ret

def main():
  n = int(input())
  s = [list(input()) for _ in range(n)] 
  t = [list(input()) for _ in range(n)]
  ans = 1001001001
  for i in range(4):
    now = dif(s,t)
    ans = min(ans,now+i)
    s = rot(s)
  print(ans)

   
if __name__ == '__main__':
  main()


