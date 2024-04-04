n,k = map(int,input().split())
s = input()

cnt = 0
ans = ""
for idx,c in enumerate(s):
    if c == 'o' and cnt < k:
        cnt += 1
        ans += 'o'
    elif c == 'o' and cnt > k:
        cnt += 1
        ans += 'x'
    else : ans += 'x'
    
print(ans)
    
    