def main():
  n = int(input())
  ss = []
  tt = []
  for i in range(n):
    s,t = map(str,input().split())  
    ss.append(s)
    tt.append(t)

  for i in range(n):
    for j in range(i+1,n):
      if(ss[i] == ss[j] and tt[i] ==tt[j]):
        print("Yes")
        exit()

  print("No")
if __name__ == '__main__':
  main()


