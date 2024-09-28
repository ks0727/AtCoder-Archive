x = int(input())
s=""
while x:
  s += '1' if x%2 else '0'
  x>>=1
reversed(s)
print(s)
  
