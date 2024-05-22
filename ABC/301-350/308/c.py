n = int(input())
def comp(c):
    return 

a = []
b = []
c = []
for _ in range(n):
    A,B = map(int,input().split())
    a.append(A)
    b.append(B)
    c.append((A,B))

ans = c.sort(key=comp())

