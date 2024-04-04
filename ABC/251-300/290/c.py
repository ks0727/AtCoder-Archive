n, k = map(int,input().split())
a = list(map(int,input().split()))

st = set(a)
na = list(st)
na.sort()
ans = 0
for i in range(min(k,len(na))):
    if(ans == na[i]):
        ans += 1
        if i >= k:
            ans = k
            break
    else:
        break

print(ans)