n = int(input())
a = list(map(int,input().split()))
print(a)
ok = [False]*n
ans = []
key = 0
while key < n:
    if not ok[key] and a[key] != key+1:
        ans.append((key+1,a[key]))
        tmp = a[key]
        a[key] = a[a[key]-1]
        a[a[key]-1] = tmp
        ok[a[key]-1] = True
    else:
        key += 1

print(len(ans))
for i in range(len(ans)):
    if ans[i][0] > ans[i][1]:
        ans[i][0],ans[i][1] = ans[i][1], ans[i][0]
    print(ans[i][0],ans[i][1])
