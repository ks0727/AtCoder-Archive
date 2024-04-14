n = int(input())
a = list(map(int,input().split()))

ans = []
for x in a:
    if x%2 == 0:
        ans.append(x)

ans = [str(x) for x in ans]
ans = " ".join(ans)
print(ans)