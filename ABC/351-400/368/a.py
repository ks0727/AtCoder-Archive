n,k = map(int,input().split())
a = list(map(int,input().split()))

b = a[n-k:] + a[:n-k]
b = [str(x) for x in b]
print(" ".join(b))
