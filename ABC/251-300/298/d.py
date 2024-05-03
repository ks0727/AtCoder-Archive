from collections import deque

q = int(input())
MOD = 998244353
digit = 0
ans = 1
s = deque()
s.append('1')
for _ in range(q):
    qi = list(map(int,input().split()))
    if qi[0] == 1:
        x = qi[1]
        ans *= 10
        ans %= MOD
        ans += x
        ans %= MOD
        s.append(str(x))
        digit+=1
    elif qi[0] ==  2:   
        y = int(s.popleft())
        l = pow(10,digit,MOD)
        ans -= y*l
        ans %= MOD
        digit-=1
    else:
        print(ans)