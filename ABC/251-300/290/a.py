n,m = map(int,input().split())
a = list(map(int,input().split()))
b = list(map(int,input().split()))

ans = 0
for idx in b:
    ans += a[idx-1]
    
print(ans)