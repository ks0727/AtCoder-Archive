import sys
n,x = map(int,input().split())
a = list(map(int,input().split()))

a = set(a)
for ai in a:
  if ai - x in a:
    print("Yes")
    sys.exit(0)

print("No")


