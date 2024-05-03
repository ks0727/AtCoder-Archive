n = int(input())
s = input()
ans = False
for c in s:
  if c == 'o':
    ans = True
    break

for c in s:
  if c == 'x':
    ans = False
    break

if ans:
  print("Yes")
else:
  print("No")
