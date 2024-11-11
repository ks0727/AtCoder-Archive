n,m = map(int,input().split())
x = list(map(int,input().split()))
a = list(map(int,input().split()))
ps = []
assert(len(x) == len(a))
sum = 0
for xi,ai in zip(x,a):
    ps.append((xi-1,ai))
    sum += ai
    
if sum != n:
    print(-1)
    exit()

ps = sorted(ps)

prev = n-1
ans = 0
for i in range(m-1,-1,-1):
    idx,cnt = ps[i]
    if prev - idx < cnt -1:
        print(-1)
        exit()
    
    ans += prev*cnt - idx*cnt - cnt*(cnt-1)//2
    prev = prev - cnt

print(ans)

