n,r = map(int,input().split())
now = r
for i in range(n):
    d,a = map(int,input().split())
    if d == 1 and 1600 <= now <= 2799:
        now += a
    elif d == 2 and 1200 <= now <= 2399:
        now += a

print(now)
