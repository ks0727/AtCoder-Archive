n = int(input())
s = input()

ans = 0

for i in range(n):
    if s[i] == '/':
        l = i-1
        r = i+1
        while l >= 0 and s[l] == '1':
            l -=1
        while r < n and s[r] == '2':
            r += 1
        l += 1
        r -= 1
        now = min(max(r-i,0),max(i-l,0))
        ans = max(now*2+1,ans)
        
print(ans)