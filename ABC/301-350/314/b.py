def main():
  n = int(input())
  a = []
  for i in range(n):
    c = int(input())
    b = list(map(int,input().split()))
    a.append(b)

  x = int(input())
  wins = []
  ls = []
  for i in range(n):
    for j in range(len(a[i])):
      if a[i][j] == x:
        wins.append(i)
        ls.append(len(a[i]))
  ans = []
  for w in wins:
    if len(a[w]) == min(ls):
      ans.append(w)
  ans_l = len(ans)
  ans = [str(i+1) for i in ans]
  ans = " ".join(ans)
  print(ans_l)
  print(ans)

    
if __name__ == '__main__':
  main()


