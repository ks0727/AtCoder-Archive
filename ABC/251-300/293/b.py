n = int(input())
a = list(map(int,input().split()))
called = [False for _ in range(n)]

for i in range(len(a)):
    a[i] -= 1

for i in range(n):
    if not called[i]:
        called[a[i]] = True

ans = []
for i in range(n):
    if not called[i]:
        ans.append(i+1)
ans1 = [str(x) for x in ans]
s = ' '.join(ans1)
print(len(ans)) 
print(s)
