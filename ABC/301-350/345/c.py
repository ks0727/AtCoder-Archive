from collections import defaultdict

def c2(x):
    return x*(x-1)/2

s = input()
n = len(s)
cnt = defaultdict(int)
for c in s:
    cnt[c]+=1
ans = c2(n)
isminus = False
for key in cnt:
    minus = c2(cnt[key])
    ans -= minus
    if minus != 0:
        isminus = True

if isminus : ans += 1
print(int(ans))
