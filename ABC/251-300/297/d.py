a,b = map(int,input().split())
if a < b:
  a,b = b,a

ans = 0
while(a%b != 0):
  if(a < b):
    a,b = b,a
  sbt = a//b
  ans += sbt
  a = a-sbt*b

ans += a//b-1
print(ans)

