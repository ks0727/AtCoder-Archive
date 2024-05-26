N, L, R = map(int, input().split())
ans = []
while L != R:
    i = 0
    while L % pow(2, i+1) == 0 and L+pow(2, i+1) <= R:
        i += 1
    ans.append([i, (pow(2, i)+1)//pow(2,i)])
    L += pow(2, i)

r = 0

for l, r in ans:
    print(f"? {l} {r}")
    x = int(input())
    r += x
    r %= 100

print(f"! {r}")