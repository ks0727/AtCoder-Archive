n = int(input())
a = [input() for _ in range(n)]
b = [input() for _ in range(n)]

for i in range(n):
  a[i] = a[i].replace(" ","")
  a[i] = [char for char in a[i]]

for i in range(n):
  b[i] = b[i].replace(" ","")
  b[i] = [char for char in b[i]]

def same(s,t):
  for i in range(n):
    for j in range(n):
      if s[i][j] == '1' and t[i][j] != '1':
        return False
  return True

def rotate(s):
  t = [['' for _ in range(n)] for _ in range(n)]
  for i in range(n):
    for j in range(n):
      t[i][j] = s[n-j-1][i]
  return t


for r in range(4):
    if same(a,b):
      print("Yes")
      exit()
    else:
      a = rotate(a)

print("No")






