a,b,c = map(int,input().split())
ok = False
if a == b == c:
    ok = True
elif a+b == c:
    ok = True
elif a+c == b:
    ok = True
elif b+c == a:
    ok = True

if ok:
    print("Yes")
else:
    print("No")