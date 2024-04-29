s = input()
b1,b2 = -1,-1
r1,r2 = -1,-1
k = -1
for i,c in enumerate(s):
  if c == 'B' and b1 == -1:
    b1 = i
  elif c == 'B' and b1 != -1:
    b2 = i
  elif c == 'R' and r1 == -1:
    r1 = i
  elif c == 'R' and r1 != -1:
    r2 = i
  elif c == 'K':
    k = i
ans = True
if (b1+b2) %2 == 0:
  ans = False
if k < r1 or k > r2:
  ans = False
if ans:
  print("Yes")
else:
  print("No")
