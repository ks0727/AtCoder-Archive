n,k = map(int,input().split())
s = input()
cnt = 0
ans = 0
for i,c in enumerate(s):
    if c == 'O':
        cnt+=1
        if cnt == k:
            ans += 1
            cnt = 0
    else:
        cnt = 0

print(ans)