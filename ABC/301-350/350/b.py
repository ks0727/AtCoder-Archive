n,q = map(int,input().split())
exist = [True]*n
t = list(map(int,input().split()))
for i in range(q):
    nt = t[i]
    nt -= 1
    if exist[nt]:
        exist[nt] = False
    else:
        exist[nt] = True

ans = 0
for i in range(n):
    if exist[i]:
        ans += 1

print(ans)