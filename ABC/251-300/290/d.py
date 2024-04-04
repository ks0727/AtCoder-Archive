from math import gcd
t = int(input())

def solve():
    n,d,k = map(int,input().split())
    g = gcd(n,d)
    if g == 1: #互いの素の時
        print((d*(k-1))%n)
    else: #互いに素ではない時
        p = n//g
        c = (k-1)//p
        j = k%p
        res = (c+d*(j-1))%n
        print(res)

for _ in range(t):
    solve()